
#ifndef PHILO_H
# define PHILO_H

// variables
#define INT_MAX 2147483647

//includes
#include <pthread.h> // threads
#include <stdio.h> // REMOVE - debug
#include <stdlib.h> // malloc array of threads (philos and forks)
#include <sys/time.h> // gettimeofday
#include <unistd.h> // write

//data
typedef struct s_data
{
	unsigned int	ini_time;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
}
t_data;

typedef struct s_philo
{
	unsigned int	birth;
	int	index;
	int	t_last_meal;
	//usar na pthread_mutex (lock/unlock) on routine
	//another option is to pass the mutex array and split forks on routine
	pthread_mutex_t *right;
	pthread_mutex_t *left;
	t_data	*data;
	pthread_t philo;
} 
t_philo;

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
unsigned long int	curr_time();

//function prototypes - philosophers
t_philo    *init_data_philos(t_data *data);
pthread_t    *create_philos(t_data *data, t_philo *data_philo);

//function prototypes - forks
pthread_mutex_t *create_forks(t_data *data);

//function prototypes - data
t_data  *init_data(int argc, char **argv, unsigned int init);

#endif
