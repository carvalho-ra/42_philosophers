#include "../inc/philo.h"

//routine
void    *routine(void *arg)
{
    int i;

    i = *(int *)arg;
    printf("philosopher %i\n", i);
    usleep(500);
    return (0);
}

//create philosophers (threads)
void    *create_philos(int nbr_of_philos)
{
    int arr[nbr_of_philos];
    int i;

    i = 0;
    while (i < nbr_of_philos)
    {
        arr[i] = i;
        i++;
    }
    pthread_t philo[nbr_of_philos];

    i = 0;
    while(i < nbr_of_philos)
    {
        pthread_create(&philo[i], NULL, &routine, &arr[i]);
        i++;
    }
    i = 0;
    while(i < nbr_of_philos)
    {
        pthread_join(philo[i], NULL);
        i++;
    }
    return (0);
}

//init data (struct data)
t_data  *init_data(int argc, char **argv)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    data->number_of_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[6]);
    return (data);
}

//create forks (mutex)
void    *create_forks(int nbr_of_philos)
{
    pthread_mutex_t mutex[nbr_of_philos];
    int i;

    i = 0;
    while (i < nbr_of_philos)
    {
        pthread_mutex_init(&mutex[i], NULL);
        i++;
    }
    return (0);
}


