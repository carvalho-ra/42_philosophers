#include "../inc/philo.h"

//routine
void    *routine()
{
    printf("philosopher created\n");
    //usleep(500);
    return (0);
}

//create data philosophers (one struct for each philosopher)
//function receives struct data (all informations from arguments) as argument
void    *init_data_philos(t_data *data)
{
    //declare an iterator;
    int i;
    //create an array of structs t_philo
    t_philo *data_philo[data->number_of_philosophers];
    
    printf("%i", data->number_of_philosophers);
    //malloc array of structs (one for each philosopher)
    data_philo[data->number_of_philosophers] = malloc(sizeof(t_philo) * data->number_of_philosophers + 1);
    if (!(data_philo[data->number_of_philosophers]))
        return (NULL);
    //set iterator to zero;
    i = 0;
    printf("teste before while\n");
    while (i < data->number_of_philosophers)
    {
        printf("teste in while\n");

        //set index of philosopher equal to i
        data_philo[i]->index = i;
        printf("teste in while\n");

        //set last meal to zero
        data_philo[i]->time_last_meal = 0;
        //tell which struct data struct philo will have acsses to
        data_philo[i]->data = data;
        i++;
    }
    printf("teste after while\n");
    return (0);
}

//create philosophers (threads)
void    *create_philos(t_data *data)
{
    int i;
    pthread_t philo[data->number_of_philosophers];

    i = 0;
    while(i < data->number_of_philosophers)
    {
        pthread_create(&philo[i], NULL, &routine, NULL);
        i++;
    }
    i = 0;
    while(i < data->number_of_philosophers)
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
        data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
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


