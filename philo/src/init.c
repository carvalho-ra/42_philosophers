/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:02 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 16:39:46 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_info	*parse_pub_info(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->ini_time = prog_start();
	info->n_philos = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->n_meals = ft_atoi(argv[5]);
	info->death = 0;
	pthread_mutex_init(&info->death_mutex, NULL);
	pthread_mutex_init(&info->last_meal_mutex, NULL);
	pthread_mutex_init(&info->n_meals_mutex, NULL);
	return (info);
}

t_data_philo	*priv_data_philos(t_info *info)
{
	int				i;
	t_data_philo	*ph;
	pthread_mutex_t	*mutex;


		mutex = create_forks(info);
		info->mutex = mutex;
		i = 0;
		ph = malloc(sizeof(t_data_philo) * info->n_philos);
		if (!ph)
			return (NULL);
		while (i < info->n_philos)
		{
			ph[i].left = &mutex[i];
			if (i == info->n_philos - 1)
				ph[i].right = &mutex[0];
			else
				ph[i].right = &mutex[i + 1];
			ph[i].index = i + 1;
			ph[i].t_last_meal = 0;
			ph[i].meals = 0;
			ph[i].info = info;
			i++;
		}
	return (ph);
}

void	create_th_philos(t_info *info, t_data_philo *ph)
{
	int	i;

	i = 0;
	while (i < info->n_philos)
	{
		pthread_create(&ph[i].th_philo, NULL, &routine, &ph[i]);
		i++;
	}
}

void	join_threads(t_data_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->info->n_philos)
	{
		pthread_join(ph[i].th_philo, NULL);
		i++;
	}
}

pthread_mutex_t	*create_forks(t_info *info)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = malloc(sizeof(pthread_mutex_t) * info->n_philos);
	if (!(mutex))
		return (NULL);
	i = 0;
	while (i < info->n_philos)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}
