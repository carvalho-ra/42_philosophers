#include "../inc/philo.h"

//start time
unsigned long int	curr_time()
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}
