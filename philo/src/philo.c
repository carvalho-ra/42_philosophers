#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	unsigned long int	init;
	unsigned long int	start;
	unsigned long int	end;
	
	init = curr_time();
	start = curr_time() - init;
	print_args(argc, argv);
	create_philos(ft_atoi(argv[1]));
	usleep(50000);
	end = curr_time() - init;
	printf("start time = %lu milisec\nend time = %lu milisec\nexecution time = %lu milisec\n", start, end, end - start);
	return (0);
}