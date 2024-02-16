/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:49:06 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/14 16:06:09 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

static int	is_digit(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			if (av[i][k] < '0' || av[i][k] > '9')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static int	value_control(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 1)
			return (1);
		i++;
	}
	if (av[5] && ft_atoi(av[5]) <= 0)
		return (1);
	return (0);
}

static void	instructions(void)
{
	printf("\n");
	printf("|-------------------- Wrong input! ----------------------|\n");
	printf("|--- 'at least 4 arguments, at most 5 arguments' --------|\n");
	printf("|--- 'Arg 1 : number_of_philosophers' -------------------|\n");
	printf("|--- 'Arg 2 : time_to_die' ------------------------------|\n");
	printf("|--- 'Arg 3 : time_to_eat' ------------------------------|\n");
	printf("|--- 'Arg 4 : time_to_sleep' ----------------------------|\n");
	printf("|--- 'Arg 5 (optional) : num_each_philosopher_must_eat' -|\n");
	printf("|--------------------------------------------------------|\n");
	printf("\n");
}

int	arg_control(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		instructions();
		return (1);
	}
	if (is_digit(ac, av) || value_control(ac, av))
	{
		instructions();
		return (1);
	}
	return (0);
}
