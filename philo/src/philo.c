/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:20:10 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 16:44:46 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	one_philo(t_info *info)
{
	if (info->n_philos == 1)
	{
		printf("%lu 1 has taken a fork\n", prog_start() - info->ini_time);
		usleep(info->t_die * 1000);
		printf("%lu 1 died\n", prog_start() - info->ini_time);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info			*info;
	t_data_philo	*ph;

	if (validation(argc, argv) == 1)
		return (0);
	info = parse_pub_info(argc, argv);
	if (info->n_philos == 1)
	{
		one_philo(info);
		return (0);
	}
	ph = priv_data_philos(info);
	create_th_philos(info, ph);
	death_monitor(ph);
	join_threads(ph);
	pthread_mutex_destroy(&info->death_mutex);
	pthread_mutex_destroy(&info->last_meal_mutex);
	pthread_mutex_destroy(info->mutex);
	free(ph);
	free(info->mutex);
	free(info);
	return (0);
}
