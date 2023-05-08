#include "../inc/philo.h"

//init data (struct data)
t_data  *init_data(int argc, char **argv, unsigned int init)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    data->ini_time = init;
    data->n_philos = ft_atoi(argv[1]);
    data->t_die = ft_atoi(argv[2]);
    data->t_eat = ft_atoi(argv[3]);
    data->t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->n_meals = ft_atoi(argv[5]);
    return (data);
}


//create data philosophers (one struct for each philosopher)
//function receives struct data (all informations from arguments) as argument
void    *init_data_philos(t_data *data)
{
    int i;

    i = 0;
    //create an array of structs t_philo
    t_philo *data_philo;
    //malloc array of structs (one for each philosopher)
    data_philo = malloc(sizeof(t_philo) * data->n_philos);
    if (!(data_philo))
        return (NULL);
    printf("number of philosophers = %i\n", data->n_philos);
    while (i < data->n_philos)
    {
        printf("philosopher %i\n", i + 1);
        printf("i = %i\n", i);
        //set time of creation
        data_philo[i].birth = curr_time() - data->ini_time;
        printf("data_philo[i].birth = %u\n", data_philo[i].birth);
        //set index of philosopher equal to i + 1 (take zero out)
        data_philo[i].index = i + 1;
        printf("data_philo[i].index = %i\n", data_philo[i].index);
        //set last meal to zero
        data_philo[i].t_last_meal = 0;
        printf("data_philo[i].t_last_meal = %i\n", data_philo[i].t_last_meal);
        //tell which struct data struct philo will have acsses to
        data_philo[i].data = data;
        printf("data_philo[i].data->n_philos = %d\n", data_philo[i].data->n_philos);
        i++;
    }
    printf("test after while\n");
    return (0);
}

//routine
void    *routine()
{
    printf("philosopher created\n");
    //usleep(500);
    return (0);
}

//create philosophers (threads)
void    *create_philos(t_data *data)
{
    int i;
    pthread_t philo[data->n_philos];

    i = 0;
    while(i < data->n_philos)
    {
        pthread_create(&philo[i], NULL, &routine, NULL);
        i++;
    }
    i = 0;
    while(i < data->n_philos)
    {
        pthread_join(philo[i], NULL);
        i++;
    }
    return (0);
}

//create forks (mutex)
//create (one fork for each philosopher)
void    *create_forks(t_data *data)
{

    //create an array of mutexes
    pthread_mutex_t mutex[data->n_philos];
    int i;

    i = 0;
    //initialize mutexes
    while (i < data->n_philos)
    {
        pthread_mutex_init(&mutex[i], NULL);
        printf("fork %i initialized (mutex)\n", i + 1);
        i++;
    }
    return (0);
}
