#include "philo.h"

void	*routine(void *arg)
{
	printf("test\n");
	return (0);
}

int	main(int ac, char **av)
{
	int i;

	if (ac == 5 || ac == 6)
	{
		t_philo *nbrs;
		t_time  *times;

		nbrs->number_of_philosophers = ft_atoi(av[1]);
		times->time_to_die = ft_atoi(av[2]);
		times->time_to_eat = ft_atoi(av[3]);
		times->time_to_sleep = ft_atoi(av[4]);
		nbrs->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);

		pthread_t	philosophers[nbrs->number_of_philosophers];
	

		while (i < nbrs->number_of_philosophers)
		{
			pthread_create(&philosophers, NULL, &routine, NULL);
			pthread_join(philosophers, NULL);
		}
	}
	return (0);
}
