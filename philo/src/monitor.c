/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:40:52 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 16:53:01 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_nbr_meals(t_data_philo *ph)
{
	pthread_mutex_lock(&ph->info->n_meals_mutex);
	if (ph->info->n_meals != 0 && ph->meals == ph->info->n_meals)
	{
		pthread_mutex_unlock(&ph->info->n_meals_mutex);
		return (1);
	}
	pthread_mutex_unlock(&ph->info->n_meals_mutex);
	return (0);
}

void	*death_monitor(t_data_philo *ph)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == ph[i].info->n_philos - 1)
			i = 0;
		if (check_nbr_meals(ph) == 1)
			break ;
		pthread_mutex_lock(&ph->info->last_meal_mutex);
		if ((curr_time(ph) - ph[i].t_last_meal) >= ph[i].info->t_die)
		{
			pthread_mutex_unlock(&ph[i].info->last_meal_mutex);
			pthread_mutex_lock(&ph[i].info->death_mutex);
			ph[i].info->death = 1;
			pthread_mutex_unlock(&ph[i].info->death_mutex);
			print_action(&ph[i], "died");
			return (NULL);
		}
		pthread_mutex_unlock(&ph->info->last_meal_mutex);
		usleep(100);
		i++;
	}
	return (NULL);
}
