#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_data_philo *ph;

	if (validation(argc, argv) == 1)
		return (0);
	info = parse_pub_info(argc, argv);
	//fix mutex initialization
	//mutex = create_forks(info);
	ph = priv_data_philos(info);
	create_th_philos(info, ph);
	death_monitor(ph);
	join_threads(ph);
	pthread_mutex_destroy(&info->death_mutex);
	pthread_mutex_destroy(&info->last_meal_mutex);
	pthread_mutex_destroy(ph[0].left);//fix mutex initialization
	free(ph);
	free(ph[0].left);//fix mutex initialization
	free(info);
	return (0);
}
