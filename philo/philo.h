
#ifndef PHILO_H
# define PHILO_H

// variables
#define INT_MAX 2147483647



//includes
#include <pthread.h> // threads
#include <stdio.h> // REMOVE - debug
#include <stdlib.h> //malloc array of threads (philos and forks)
#include <sys/time.h> //gettimeofday

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

//function prototypes


#endif
