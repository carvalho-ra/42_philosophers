#include "../inc/philo.h"

//parse information
t_info  *parse_args(int ac, char **av)
{
    unsigned int    t_zero;
    t_info *info;

    if (validation(ac, av) != 0)
        return (0);
    info->ini_time = curr_time();
    info->n_philos = ft_atoi(av[1]);
    info->t_die = ft_atoi(av[2]);
    info->t_eat = ft_atoi(av[3]);
    info->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info->n_meals = ft_atoi(av[5]);
    else
        info->n_meals = 0;
    return (info);
}

int main(int ac, char **av)
{
    t_info *info;
    pthread_mutex_t *forks;
    int i;

    info = parse_args(ac, av);
    
    
    return (0);
}
