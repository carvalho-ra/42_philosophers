
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
	long int	start_time; //not in use 
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}
t_data;

typedef struct s_philo
{
	int	index;
	int	time_last_meal;
	//pointer to right fork
	//pointer to left fork
	t_data	*data;
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
void    *init_data_philos(t_data *data);
void    *create_philos(t_data *data);

//function prototypes - data
t_data  *init_data(int argc, char **argv);


#endif
