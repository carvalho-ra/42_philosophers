/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:44:59 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 14:29:10 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long	prog_start(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

unsigned long	curr_time(t_data_philo *ph)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return (((tm.tv_sec * 1000) + (tm.tv_usec / 1000)) - ph->info->ini_time);
}

void	smart_sleep(unsigned int time, t_data_philo *ph)
{
	unsigned long	tm1;
	unsigned long	tm2;
	struct timeval	first;
	struct timeval	second;

	gettimeofday(&first, NULL);
	tm1 = (first.tv_sec * 1000) + (first.tv_usec / 1000);
	while (1)
	{
		pthread_mutex_lock(&ph->info->death_mutex);
		if (ph->info->death == 1)
		{
			pthread_mutex_unlock(&ph->info->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&ph->info->death_mutex);
		gettimeofday(&second, NULL);
		tm2 = (second.tv_sec * 1000) + (second.tv_usec / 1000);
		if (tm2 - tm1 >= time)
			break ;
		usleep(100);
	}
}
