/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:41:24 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/20 19:54:11 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_data	t_data;

# define DIED "died"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

typedef enum e_state
{
	IDLE = 0,
	DEAD = 1,
}	t_state;

typedef struct s_philo
{
	int				id;
	int				nb_meals;
	t_data			*data;
	t_state			state;
	t_mutex			*first_fork;
	t_mutex			*second_fork;
	t_mutex			state_mutex;
	t_mutex			nb_meals_mutex;
	t_mutex			last_meals_mutex;
	long long		last_meal;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	bool			running;
	long long		time_to_eat;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		start_time;
	pthread_t		monitor_death;
	pthread_t		monitor_full;
	pthread_t		*philos_threads;
	t_mutex			print_mutex;
	t_mutex			running_mutex;
	t_mutex			starttime_mutex;
	t_mutex			*forks;
	t_philo			*philos;
}	t_data;

long long	get_time(void);
void		precise_sleep(long long sleep_time);
bool		get_running(t_data *data);
int			get_nb_philos(t_data *data);
long long	get_start_time(t_data *data);
long long	get_time_to_eat(t_data *data);
long long	get_time_to_sleep(t_data *data);
long long	get_time_to_die(t_data *data);
int			get_max_meals(t_data *data);
int			get_nb_full_philos(t_data *data);
t_state		get_state(t_philo *philo);
int			get_nb_meals(t_philo *philo);
long long	get_last_meal(t_philo *philo);
void		set_start_time(t_data *data);
void		update_last_meal_time(t_philo *philo);
void		update_nb_meals(t_philo *philo);
void		set_philo_state(t_state status, t_philo *philo);
void		set_running(t_data *data, bool newval);
long		ft_atol(char *str);
int			validate_args(int ac, char **av, t_data *data);
int			init_data(t_data *data);
int			init_forks(t_data *data);
int			init_philos(t_data *data);
void		clean_data(t_data *data);
int			simulation(int ac, char **av, t_data *data);
int			r_think(t_philo *philo);
int			r_sleep(t_philo *philo);
int			r_eat(t_philo *philo);
void		drop_forks(t_philo *philo);
void		drop_f_fork(t_philo *philo);
void		drop_s_fork(t_philo *philo);
int			take_f_fork(t_philo *philo);
int			take_s_fork(t_philo *philo);
int			take_forks(t_philo *philo);
void		*routine(void *p_philo);
void		print_msg(t_data *data, int id, char *msg);
void		*monitor_death(void *p_data);
void		*monitor_full(void	*p_data);
int			check_death(t_philo *philo);

#endif