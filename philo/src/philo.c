#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo *ph;

	data = init_data(argc, argv);
	ph = init_data_philos(data);
	create_philos(data, ph);
	death_monitor(ph);
	join_threads(ph);
	return (0);
}
