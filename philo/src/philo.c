#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	struct timeval  start;
	struct timeval  end;
	
	gettimeofday(&start, NULL);
	print_args(argc, argv);
	//usleep(500);
	gettimeofday(&end, NULL);
	printf("start time = %i\nend time = %i\nexecution time = %i", start.tv_usec, end.tv_usec, end.tv_usec - start.tv_usec);
	return (0);
}