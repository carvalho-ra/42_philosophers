#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	init_data_philos(data);
	create_philos(data, (init_data_philos(data)));
	create_forks(data);
	return (0);
}
