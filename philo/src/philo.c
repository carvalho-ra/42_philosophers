#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	unsigned int	init;
	unsigned int	start;
	unsigned int	end;
	t_data	*data;

	init = curr_time();
	start = curr_time() - init;
	//print_args(argc, argv);
	data = init_data(argc, argv, init);
	init_data_philos(data);
	create_philos(data, (init_data_philos(data)));
	create_forks(data);
	usleep(50000);
	end = curr_time() - init;
	printf("start time = %u milisec\n", start);
	printf("end time = %u milisec\n", end);
	printf("execution time = %u milisec\n", end - start);
	return (0);
}
