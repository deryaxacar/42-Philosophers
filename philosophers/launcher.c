/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:08 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/15 18:03:14 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	routine_while(t_philo *philo, t_table *table)
{
	while (1)
	{
		philo_eats(philo);
		pthread_mutex_lock(&(table->dieded_check));
		if (table->dieded)
		{
			pthread_mutex_unlock(&(table->dieded_check));
			break ;
		}
		pthread_mutex_unlock(&(table->dieded_check));
		pthread_mutex_lock(&(table->all_ate_check));
		if (table->nb_eat != -1 && (table->all_ate
				|| philo->eat_count >= table->nb_eat))
		{
			pthread_mutex_unlock(&(table->all_ate_check));
			break ;
		}
		pthread_mutex_unlock(&(table->all_ate_check));
		action_print(table, philo->pid, SLEEP);
		smart_sleep(table->t_sleep, table);
		action_print(table, philo->pid, THINK);
	}
}

void	*routine(void *void_philo)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)void_philo;
	table = philo->table;
	if (philo->pid % 2)
		usleep(15000);
	routine_while(philo, table);
	return (NULL);
}

void	exit_launcher(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->philo_num)
		pthread_join(philo[i].pthread, NULL);
	i = -1;
	while (++i < table->philo_num)
		pthread_mutex_destroy(&(table->forks[i]));
	pthread_mutex_destroy(&(table->writing));
	pthread_mutex_destroy(&(table->die_check));
	pthread_mutex_destroy(&(table->meal_check));
	pthread_mutex_destroy(&(table->eat_count_check));
	pthread_mutex_destroy(&(table->last_eat_check));
	pthread_mutex_destroy(&(table->dieded_check));
	pthread_mutex_destroy(&(table->all_ate_check));
	pthread_mutex_destroy(&(table->die_write));
	ft_free(table);
}

void	death_checker(t_table *table, t_philo *philo, int i, int j)
{
	while (!(table->all_ate))
	{
		i = -1;
		while (++i < table->philo_num && !(table->dieded))
		{
			pthread_mutex_lock(&(table->last_eat_check));
			if (time_diff(philo[i].last_eat, timestamp()) > table->t_death)
			{
				pthread_mutex_lock(&(table->dieded_check));
				printf("%i ", (int)(timestamp() - table->first_timestamp));
				printf("%i ", i + 1);
				printf("%s\n", DIE);
				table->dieded = 1;
				pthread_mutex_unlock(&(table->dieded_check));
				j = -1;
				while (++j < table->philo_num)
					pthread_mutex_unlock(&(table->forks[j]));
			}
			pthread_mutex_unlock(&(table->last_eat_check));
			usleep(50);
		}
		if (table->dieded)
			break ;
		eat_control(table, philo);
	}
}

int	launcher(t_table *table)
{
	int				i;
	t_philo			*philo;

	i = 0;
	philo = table->philos;
	table->first_timestamp = timestamp();
	while (i < table->philo_num)
	{
		if (pthread_create(&(philo[i].pthread), NULL, routine, &(philo[i])))
			return (1);
		pthread_mutex_lock(&(table->last_eat_check));
		philo[i].last_eat = timestamp();
		pthread_mutex_unlock(&(table->last_eat_check));
		i++;
	}
	death_checker(table, table->philos, -1, -1);
	exit_launcher(table, philo);
	return (0);
}
