#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo *ph;

	info = parse_pub_info(argc, argv);
	ph = init_data_philos(info);
	create_philos(info, ph);
	death_monitor(ph);
	join_threads(ph);
	return (0);
}
