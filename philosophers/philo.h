/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:59:30 by deryacar          #+#    #+#             */
/*   Updated: 2024/02/15 18:13:03 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIE "died"

//philosophers
typedef struct s_philo
{
	int				pid;
	int				eat_count;
	int				left_fork;
	int				right_fork;
	long long		last_eat;
	struct s_table	*table;
	pthread_t		pthread;
}					t_philo;

//table
typedef struct s_table
{
	int				philo_num;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				all_ate;
	int				dieded;
	long long		first_timestamp;
	pthread_mutex_t	last_eat_check;
	pthread_mutex_t	eat_count_check;
	pthread_mutex_t	die_check;
	pthread_mutex_t	dieded_check;
	pthread_mutex_t	all_ate_check;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	die_write;
	t_philo			*philos;
}					t_table;

// ----- init.c -----
int					preparation(t_table *table, char **argv);
int					init_philo(t_table *table);
int					init_mutex(t_table *table);

// ----- utils.c -----
int					ft_atoi(const char *str);
int					ft_isdigit(char **array);
long long			timestamp(void);
long long			time_diff(long long past, long long pres);
void				smart_sleep(long long time, t_table *table);

// ----- utils2.c -----
int					write_error(char *str);
void				eat_control(t_table *t, t_philo *p);
void				ft_free(t_table *table);
void				action_print(t_table *table, int id, char *string);
void				philo_eats(t_philo *philo);

// ----- launcher.c -----
int					launcher(t_table *table);
void				exit_launcher(t_table *table, t_philo *philos);

int					destroy_mutex(t_table *table);
void				chose_mutex(t_table *table, int flag);

// ----- controls.c -----
int					arg_control(int ac, char **av);

#endif
