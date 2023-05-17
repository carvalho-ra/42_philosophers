/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:43:52 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 14:51:34 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//includes
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

//parse information - public info
typedef struct s_data_philo	t_data_philo;

typedef struct s_info
{
	unsigned long	ini_time;
	int				n_philos;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	int				n_meals;
	int				death;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	n_meals_mutex;
	t_data_philo	*ph;
}	t_info;

//create struct of philosopher - private data
typedef struct s_data_philo
{
	int				index;
	int				meals;
	unsigned long	t_last_meal;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	t_info			*info;
	pthread_t		th_philo;
}	t_data_philo;

//function prototypes - utils
int				ft_isdigit(int nbr);
int				ft_strlen(char *s);
int				ft_atoi(const char *str);

//function prototypes - validation
int				check_empty(int argc, char **argv);
int				check_char(int argc, char **argv);
int				check_max_int(int argc, char **argv);
int				validation(int argc, char **argv);

//function prototypes - time
unsigned long	prog_start(void);
unsigned long	curr_time(t_data_philo *ph);
void			smart_sleep(unsigned int time, t_data_philo *ph);

//function prototypes - init
t_info			*parse_pub_info(int argc, char **argv);
t_data_philo	*priv_data_philos(t_info *info);
void			create_th_philos(t_info *info, t_data_philo *ph);
void			join_threads(t_data_philo *ph);
pthread_mutex_t	*create_forks(t_info *info);

//function prototypes - monitor
int				check_nbr_meals(t_data_philo *ph);
void			*death_monitor(t_data_philo *ph);

//function prototypes - routine
void			take_forks(t_data_philo *ph);
void			ph_eat(t_data_philo *ph);
void			actions(t_data_philo *ph);
void			*routine(void *arg);
void			print_action(t_data_philo *ph, char *action);

#endif
