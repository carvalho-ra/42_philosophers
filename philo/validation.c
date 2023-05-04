#include "philo.h"

//empty argument
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
			{
				//remove error message
				write(2, "Error - empty argument\n", 23);
			}
			return (1);
		}
		i++;
	}
	return (0);
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
					//remove error message
					write(2, "Error - argument has char\n", 26);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

//int max (no negative numbers)
int	check_max_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647)
		{
			//remove error message
			write(2, "Error - argument exceed max int\n", 32);
			return (1);
		}
		if (ft_atoi(argv[i]) < 0)
		{
			//remove error message
			write(2, "Error - argument has negative number\n", 37);
			return (1);
		}
		i++;
	}
	return (0);
}

//all validations
int	validation(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
	{
		//remove error message
		write(2, "Error - wrong number of arguments\n", 34);
		return (1);
	}
	if (check_empty(argc, argv) == 1)
		return (1);
	if (check_char(argc, argv) == 1)
		return (1);
	if (check_max_int(argc, argv) == 1)
		return (1);
	return (0);
}

//print args
void	print_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (validation(argc, argv) == 0)
	{
		while (i < argc)
		{
			printf("argument (%i) = %i\n", i, ft_atoi(argv[i]));
			i++;
		}
	}
}