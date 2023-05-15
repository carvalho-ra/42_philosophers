#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_data_philo *ph;

    if (validation(argc, argv) == 1)
        return (0);
	info = parse_pub_info(argc, argv);
	ph = priv_data_philos(info);
	create_th_philos(info, ph);
	death_monitor(ph);
	join_threads(ph);
	return (0);
}
