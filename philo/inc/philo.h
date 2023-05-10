
#ifndef PHILO_H
# define PHILO_H

//includes
#include <pthread.h> // threads
#include <stdio.h> // REMOVE - debug
#include <stdlib.h> // malloc array of threads (philos and forks)
#include <sys/time.h> // gettimeofday
#include <unistd.h> // write

//data - parsed information
typedef struct s_info
{
	unsigned int	t_start;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
}
t_info;

typedef struct s_philo
{
	int	index;
	int	t_last_meal;
	t_info			*info;
}
t_philo;

//function prototypes - utils
int				ft_isdigit(int nbr);
int				ft_strlen(char *s);
int				ft_atoi(const char *str);
unsigned int	curr_time();

//function prototypes - validation
int	check_empty(int argc, char **argv);
int	check_char(int argc, char **argv);
int	check_max_int(int argc, char **argv);
int	validation(int argc, char **argv);
void	print_args(int argc, char **argv);

//function prototypes - philosophers
t_info  *parse(int argc, char **argv);
t_philo *data_philos(t_info *info);



#endif
