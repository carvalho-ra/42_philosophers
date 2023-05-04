#include "../inc/philo.h"

//start time
int start_time()
{
	struct timeval start;
	gettimeofday(&start, NULL);
	return (start.tv_usec / 1000);
}

//end time
int end_time()
{
	struct timeval end;
	gettimeofday(&end, NULL);
	return (end.tv_usec / 1000);
}
