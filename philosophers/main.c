/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:15 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/14 16:16:16 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (arg_control(ac, av))
		return (write_error("Invalid Character Argument"), 0);
	if (preparation(&table, av))
		return (write_error("Mutex Start Error"), 0);
	if (init_philo(&table))
		return (write_error("Philosophers Init Error"), 0);
	if (init_mutex(&table))
		return (write_error("Mutex Init Error"), 0);
	if (launcher(&table))
		return (write_error("Thread Create Error"), 0);
}
