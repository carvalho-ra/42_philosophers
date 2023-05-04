
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
typedef struct s_time
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}
t_time;

typedef struct s_philo
{
	int	number_of_philosophers;
	int	number_of_times_each_philosopher_must_eat;
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
int start_time();
int end_time();


#endif
