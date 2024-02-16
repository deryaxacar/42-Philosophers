/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:02 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/15 12:52:32 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

int	init_mutex(t_table *table)
{
	int	i;

	i = table->philo_num;
	table->forks = malloc(sizeof(pthread_mutex_t) * i);
	if (!(table->forks))
		return (free(table->philos), 1);
	if (!destroy_mutex(table))
		return (free(table->philos), 1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL))
		{
			while (++i < table->philo_num)
				pthread_mutex_destroy(&(table->forks[i]));
			free(table->philos);
			return (chose_mutex(table, 7), 1);
		}
	}
	return (0);
}

int	destroy_mutex(t_table *table)
{
	if (pthread_mutex_init(&(table->writing), NULL))
		return (0);
	else if (pthread_mutex_init(&(table->meal_check), NULL))
		return (chose_mutex(table, 1), 0);
	else if (pthread_mutex_init(&(table->die_check), NULL))
		return (chose_mutex(table, 2), 0);
	else if (pthread_mutex_init(&(table->eat_count_check), NULL))
		return (chose_mutex(table, 3), 0);
	else if (pthread_mutex_init(&(table->last_eat_check), NULL))
		return (chose_mutex(table, 4), 0);
	else if (pthread_mutex_init(&(table->dieded_check), NULL))
		return (chose_mutex(table, 5), 0);
	else if (pthread_mutex_init(&(table->all_ate_check), NULL))
		return (chose_mutex(table, 6), 0);
	else if (pthread_mutex_init(&(table->die_write), NULL))
		return (chose_mutex(table, 7), 0);
	return (1);
}

void	chose_mutex(t_table *table, int flag)
{
	if (flag >= 1)
		pthread_mutex_destroy(&(table->writing));
	if (flag >= 2)
		pthread_mutex_destroy(&(table->meal_check));
	if (flag >= 3)
		pthread_mutex_destroy(&(table->die_check));
	if (flag >= 4)
		pthread_mutex_destroy(&(table->eat_count_check));
	if (flag >= 5)
		pthread_mutex_destroy(&(table->last_eat_check));
	if (flag >= 6)
		pthread_mutex_destroy(&(table->dieded_check));
	if (flag >= 7)
		pthread_mutex_destroy(&(table->all_ate_check));
}

int	init_philo(t_table *table)
{
	int	i;

	i = table->philo_num;
	table->philos = malloc(sizeof(t_philo) * i);
	if (!(table->philos))
		return (1);
	while (--i >= 0)
	{
		table->philos[i].pid = i;
		table->philos[i].eat_count = 0;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % table->philo_num;
		table->philos[i].last_eat = 0;
		table->philos[i].table = table;
	}
	return (0);
}

int	preparation(t_table *table, char **argv)
{
	table->philo_num = ft_atoi(argv[1]);
	if (table->philo_num > 200)
		return (write_error("Error"), 1);
	table->t_death = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->all_ate = 0;
	table->dieded = 0;
	if (table->philo_num <= 0 || table->t_death <= 0 || table->t_eat <= 0
		|| table->t_sleep <= 0)
		return (1);
	if (argv[5])
	{
		table->nb_eat = ft_atoi(argv[5]);
		if (table->nb_eat <= 0)
			return (1);
	}
	else
		table->nb_eat = -1;
	return (0);
}
