#include "../inc/philo.h"

//parse information
t_info  *parse(int argc, char **argv)
{
    t_info *info;

    if (validation(argc, argv) != 0)
        return (0);
    info = malloc(sizeof(t_info));
    info->t_start = curr_time();
    info->n_philos = ft_atoi(argv[1]);
    info->t_die = ft_atoi(argv[2]);
    info->t_eat = ft_atoi(argv[3]);
    info->t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        info->n_meals = ft_atoi(argv[5]);
    else
        info->n_meals = 0;
    return (info);
}

t_philo *data_philos(t_info *info)
{
    int i;
    t_philo *data;

    data = malloc(sizeof(t_philo) * info->n_philos);

    i = 0;
    while (i < info->n_philos)
    {
        data[i]->index = i + 1;
        data[i]->info = info;
        data[i]->t_last_meal = 0;
        i++;
    }
    return (data);
}
