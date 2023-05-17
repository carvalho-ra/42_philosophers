/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarvalh <rcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:42:20 by rcarvalh          #+#    #+#             */
/*   Updated: 2023/05/17 11:42:21 by rcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_empty(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!(argv[i]))
		return (1);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			if (argc > 2)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				if (!((argv[i][j] == '+' || argv[i][j] == '-') &&
					(j == 0) && (ft_strlen(argv[i]) > 1)))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_max_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647)
			return (1);
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	validation(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		return (1);
	if (check_empty(argc, argv) == 1)
		return (1);
	if (check_char(argc, argv) == 1)
		return (1);
	if (check_max_int(argc, argv) == 1)
		return (1);
	return (0);
}
