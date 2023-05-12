#include "../inc/philo.h"

//current time
unsigned long	curr_time(t_data_philo *ph)
{

	struct timeval tm;
	gettimeofday(&tm, NULL);
	return (((tm.tv_sec * 1000) + (tm.tv_usec / 1000)) - ph->info->ini_time);
}

//start program
unsigned long	prog_start(void)
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}
