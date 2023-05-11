#include "../inc/philo.h"

//start time
unsigned long	curr_time(t_philo *data)
{

	struct timeval tm;
	gettimeofday(&tm, NULL);
	return (((tm.tv_sec * 1000) + (tm.tv_usec / 1000)) - data->data->ini_time);
}

//start program
unsigned long	prog_start(void)
{

	struct timeval tm;
	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}
