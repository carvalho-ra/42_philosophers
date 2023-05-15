#ifndef PHILO_H
# define PHILO_H

//includes
# include <pthread.h> // threads
# include <stdio.h> // printf
# include <stdlib.h> // malloc array of structs (philos) and forks (mutexes)
# include <sys/time.h> // gettimeofday
# include <unistd.h> // write

typedef struct s_data_philo	t_data_philo;

//parse information - public info
typedef struct s_info
{
	unsigned long	ini_time;
	int				n_philos;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	int				n_meals;
	int				death;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	last_meal_mutex;
	t_data_philo	*ph;
}	t_info;

//create struct of philosopher - private data
typedef struct s_data_philo
{
	int				index;
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
void			print_args(int argc, char **argv);

//function prototypes - time
unsigned long	curr_time(t_data_philo *ph);
unsigned long	prog_start(void);

//function prototypes - philosophers
t_data_philo	*priv_data_philos(t_info *info);
void			create_th_philos(t_info *info, t_data_philo *ph);
void			join_threads(t_data_philo *ph);

//function prototypes - forks
pthread_mutex_t	*create_forks(t_info *info);
pthread_mutex_t	*create_death_mutex(t_data_philo *ph);

//function prototypes - data
t_info			*parse_pub_info(int argc, char **argv);

//function prototypes - routine
void			*routine(void *arg);
void			ph_eat(t_data_philo *ph);
void			*death_monitor(t_data_philo *ph);
void			print_action(t_data_philo *ph, char *action);
void	monitor2(t_info *info);
#endif
