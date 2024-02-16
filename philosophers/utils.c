/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:41 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/15 13:09:48 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

long long	timestamp(void)
{
	struct timeval	t;
	long long		time;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_table *table)
{
	long long	i;

	i = timestamp();
	while (1)
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		pthread_mutex_lock(&(table->dieded_check));
		if (table->dieded)
		{
			pthread_mutex_unlock(&(table->dieded_check));
			break ;
		}
		pthread_mutex_unlock(&(table->dieded_check));
		usleep(50);
	}
}
