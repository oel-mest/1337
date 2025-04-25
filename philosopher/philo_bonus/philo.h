/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:56:03 by oel-mest          #+#    #+#             */
/*   Updated: 2025/01/23 21:26:19 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>
# include <limits.h>

# define DIED "died"
# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"

# define FORK_S	"/forks_sem"
# define REPORT_S "/report_sem"
# define PRINT_S "/print_sem"
# define FULLPH_S "/fullphilos_sem"
# define RUN_S "/running_sem"
# define SYNCH_S "/synchro_sem"

typedef struct s_data	t_data;

typedef enum status_e
{
	IDLE = 0,
	DEAD = 1,
	FULL = 2
}	t_status;

typedef struct s_philo
{
	int			id;
	pid_t		pid;
	int			nbr_meals;
	long long	last_meal;
	char		*sem_name;
	t_status	state;
	t_data		*data;
	sem_t		*philo_sem;	
}	t_philo;

typedef struct s_data
{
	int			nbr_philos;
	int			max_eats;
	long long	time_to_eat;
	long long	time_to_die;
	long long	time_to_sleep;
	long long	start_time;
	t_philo		*philos;
	sem_t		*print_sem;
	sem_t		*forks;
	sem_t		*report_sem;
	sem_t		*full_philos_sem;
	sem_t		*running;
}	t_data;

// time
long long	get_time(void);
void		precise_sleep(long long sleep_time);
// print
void		print_msg(t_data *data, int id, char *msg);
// init
void		init_philo(t_data *data);
void		init_data(t_data *data);
void		create_sem(sem_t **semaphore, char *name, int value);
char		*gen_sem_name(int id);
// parsing
void		validate_args(int ac, char **av, t_data *data);
// cleaning
void		clean_data(t_data *data);
void		wait_all(t_data *data);
// monitors
void		*monitor_full(void *p_data);
void		*monitor_death(void	*p_philo);
// routine
void		routine(t_philo *philo);
void		r_think(t_philo *philo);
void		r_eat(t_philo *philo);
void		r_sleep(t_philo *philo);
// utils
long long	ft_atol(char *str);
char		*ft_itoa(int n);
char		*ft_strjoin(const char *s1, const char *s2);
// getters & setters
int			get_nbr_meals(t_philo *philo);
t_status	get_state(t_philo *philo);
long long	get_last_meal(t_philo *philo);
void		update_nbr_meals(t_philo *philo);
void		set_last_meal(t_philo *philo, long long value);
void		set_state(t_philo *philo, t_status value);
void		update_meals_count(t_philo *philo);

#endif