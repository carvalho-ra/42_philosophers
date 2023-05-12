#include "../inc/philo.h"

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
	int		sign;
	int		result;
	size_t	count;

	sign = 1;
	result = 0;
	count = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-')
	{
		sign = -sign;
		count++;
	}
    else if (str[count] == '+')
        count++;
    if (str[count] == '-' || str[count] == '+')
		return (0);
	while (ft_isdigit(str[count]) == 1)
	{
		result = (result * 10) + (str[count] - '0');
		count++;
	}
	return (result * sign);
}
