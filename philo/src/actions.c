/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:30:37 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 16:38:41 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_forks(t_data_philo *ph)
{
	if (ph->index % 2 != 0)
	{
		pthread_mutex_lock(ph->left);
		print_action(ph, "has taken a fork");
		pthread_mutex_lock(ph->right);
		print_action(ph, "has taken a fork");
	}
	if (ph->index % 2 == 0)
	{
		pthread_mutex_lock(ph->right);
		print_action(ph, "has taken a fork");
		pthread_mutex_lock(ph->left);
		print_action(ph, "has taken a fork");
	}
}

void	ph_eat(t_data_philo *ph)
{
	take_forks(ph);
	print_action(ph, "is eating");
	pthread_mutex_lock(&ph->info->last_meal_mutex);
	ph->t_last_meal = curr_time(ph);
	pthread_mutex_unlock(&ph->info->last_meal_mutex);
	pthread_mutex_lock(&ph->info->n_meals_mutex);
	ph->meals++;
	pthread_mutex_unlock(&ph->info->n_meals_mutex);
	smart_sleep(ph->info->t_eat, ph);
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(ph->left);
}

void	actions(t_data_philo *ph)
{
	ph_eat(ph);
	print_action(ph, "is sleeping");
	smart_sleep(ph->info->t_sleep, ph);
	print_action(ph, "is thinking");
	usleep(100);
}

void	*routine(void *arg)
{
	t_data_philo	*ph;

	ph = (t_data_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&ph->info->death_mutex);
		if (ph->info->death == 1)
		{
			pthread_mutex_unlock(&ph->info->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&ph->info->death_mutex);
		pthread_mutex_lock(&ph->info->n_meals_mutex);
		if (ph->info->n_meals != 0 && ph->meals == ph->info->n_meals)
		{
			pthread_mutex_unlock(&ph->info->n_meals_mutex);
			break ;
		}
		pthread_mutex_unlock(&ph->info->n_meals_mutex);
		actions(ph);
	}
	return (NULL);
}

void	print_action(t_data_philo *ph, char *action)
{
	pthread_mutex_lock(&ph->info->death_mutex);
	if (ph->info->death != 1 || (ph->info->death == 1
			&& ft_strlen(action) == 4))
		printf("%lu %d %s\n", curr_time(ph), ph->index, action);
	pthread_mutex_unlock(&ph->info->death_mutex);
}
