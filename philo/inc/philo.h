
#ifndef PHILO_H
# define PHILO_H

//includes
#include <pthread.h> // threads
#include <stdio.h> // REMOVE - debug
#include <stdlib.h> // malloc array of threads (philos and forks)
#include <sys/time.h> // gettimeofday
#include <unistd.h> // write

typedef struct s_data_philo t_data_philo;

//parse information
typedef struct s_info
{
	unsigned long	ini_time;
	int		n_philos;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	int		n_meals;
	int	death;
	t_data_philo *ph;
}
t_info;

typedef struct s_data_philo
{
	int	index;
	unsigned long	t_last_meal;
	//usar na pthread_mutex (lock/unlock) on routine
	pthread_mutex_t *right;
	pthread_mutex_t *left;
	t_info	*info;
	pthread_t philo;
} 
t_data_philo;

//function prototypes - utils
int	ft_isdigit(int nbr);
int	ft_strlen(char *s);
int	ft_atoi(const char *str);

//function prototypes - validation
int	check_empty(int argc, char **argv);
int	check_char(int argc, char **argv);
int	check_max_int(int argc, char **argv);
int	validation(int argc, char **argv);
void	print_args(int argc, char **argv);

//function prototypes - time
unsigned long	curr_time(t_data_philo *data);
unsigned long	prog_start(void);

//function prototypes - philosophers
t_data_philo    *init_data_philos(t_info *info);
void    create_philos(t_info *info, t_data_philo *ph);
void    join_threads(t_data_philo *data_philo);

//function prototypes - forks
pthread_mutex_t *create_forks(t_info *info);

//function prototypes - data
t_info  *parse_pub_info(int argc, char **argv);


//function prototypes - routine
void *routine(void *arg);
void    ph_eat(t_data_philo *ph);
void *death_monitor(t_data_philo *ph);



#endif
