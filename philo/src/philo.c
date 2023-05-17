/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:20:10 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 13:20:52 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_info			*info;
	t_data_philo	*ph;

	if (validation(argc, argv) == 1)
		return (0);
	info = parse_pub_info(argc, argv);
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
