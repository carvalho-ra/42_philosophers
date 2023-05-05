#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	unsigned long int	init;
	unsigned long int	start;
	unsigned long int	end;
	t_data	*data;

	init = curr_time();
	start = curr_time() - init;
	print_args(argc, argv);
	data = init_data(argc, argv);
	data->start_time = init;
	init_data_philos(data);
	create_philos(data);
	usleep(50000);
	end = curr_time() - init;
	printf("start time = %lu milisec\nend time = %lu milisec\nexecution time = %lu milisec\n", start, end, end - start);
	return (0);
}
