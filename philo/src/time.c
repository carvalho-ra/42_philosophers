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

//smart sleep
void	smart_sleep(unsigned int time)
{
	unsigned long	tm1;
	unsigned long	tm2;

	struct timeval first;
	struct timeval second;

	gettimeofday(&first, NULL);
	tm1 = (first.tv_sec * 1000) + (first.tv_usec / 1000);
	while (1)
	{
		gettimeofday(&second, NULL);
		tm2 = (second.tv_sec * 1000) + (second.tv_usec / 1000);
		if (tm2 - tm1 >= time)
			break;
		usleep(100);
	}
}
