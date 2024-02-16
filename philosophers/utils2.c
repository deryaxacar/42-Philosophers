/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:47 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/15 18:12:39 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	action_print(t_table *table, int id, char *string)
{
	pthread_mutex_lock(&(table->dieded_check));
	if (!(table->dieded))
	{
		printf("%lli ", timestamp() - table->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
		usleep(50);
	}
	pthread_mutex_unlock(&(table->dieded_check));
	return ;
}

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

void	ft_free(t_table *table)
{
	free (table->forks);
	free (table->philos);
}

void	eat_control(t_table *t, t_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(t->eat_count_check));
	while (t->nb_eat != -1 && i < t->philo_num && p[i].eat_count >= t->nb_eat)
		i++;
	pthread_mutex_unlock(&(t->eat_count_check));
	if (i == t->philo_num)
	{
		pthread_mutex_lock(&(t->all_ate_check));
		t->all_ate = 1;
		pthread_mutex_unlock(&(t->all_ate_check));
	}
}

void	philo_eats(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&(table->forks[philo->left_fork]));
	pthread_mutex_lock(&(table->forks[philo->right_fork]));
	pthread_mutex_lock(&(table->meal_check));
	pthread_mutex_lock(&(table->die_write));
	action_print(table, philo->pid, FORK);
	action_print(table, philo->pid, FORK);
	action_print(table, philo->pid, EAT);
	pthread_mutex_unlock(&(table->die_write));
	pthread_mutex_unlock(&(table->meal_check));
	pthread_mutex_lock(&(table->last_eat_check));
	philo->last_eat = timestamp();
	pthread_mutex_unlock(&(table->last_eat_check));
	smart_sleep(table->t_eat, table);
	pthread_mutex_lock(&(table->eat_count_check));
	(philo->eat_count)++;
	pthread_mutex_unlock(&(table->eat_count_check));
	pthread_mutex_unlock(&(table->forks[philo->left_fork]));
	pthread_mutex_unlock(&(table->forks[philo->right_fork]));
}
