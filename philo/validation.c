#include <philo.h>

//is digit
int	ft_isdigit(int nbr)
{
	if (nbr < '0' || nbr > '9')
		return (0);
	else
		return (1);
}

//ft_strlen
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//ft_atoi
int	ft_atoi(const char *str)
{
	int		result;
	size_t	count;
	int		sign;

	sign = 1;
	result = 0;
	count = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (ft_isdigit(str[count]) == 1)
	{
		result = (result * 10) + (str[count] - '0');
		count++;
	}
	return (result * sign);
}

//has char
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
				{
					write(2, "Error\n", 6);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

//int max min - no negative
int	check_max_min_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i] < 0))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

//all validations
int	validation(int argc, char **argv)
{
	if (check_char(argc, argv) == 1)
		return (-1);
	if (check_max_min_int(argc, argv) == 1)
		return (-2);
	return (0);
}