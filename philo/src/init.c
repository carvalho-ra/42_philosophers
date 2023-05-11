#include "../inc/philo.h"

//init data (struct data)
t_data  *init_data(int argc, char **argv, unsigned int init)
{
    if (validation(argc, argv) == 1)
        return (0);
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
//function receives struct data as argument(all informations from arguments)
t_philo    *init_data_philos(t_data *data)
{
    int i;
    //create an array of structs t_philo
    t_philo *data_philo;
    pthread_mutex_t *mutex;

    mutex = create_forks(data);
    i = 0;
    //malloc array of structs (one for each philosopher)
    data_philo = malloc(sizeof(t_philo) * data->n_philos);
    if (!(data_philo))
        return (NULL);
    printf("number of philosophers = %i\n", data->n_philos);
    while (i < data->n_philos)
    {
        //set forks
        data_philo[i].left = &mutex[i];
        //if i = number of philosophers (n_philos - 1)
        if (i == data->n_philos - 1)
            data_philo[i].right = &mutex[0];
        else
            data_philo[i].right = &mutex[i + 1];
        printf("philosopher %i\n", i + 1);
        //set time of creation
        data_philo[i].birth = curr_time() - data->ini_time;
        printf("data_philo[%i].birth = %u\n", i, data_philo[i].birth);
        //set index of philosopher equal to i + 1 (take zero out)
        data_philo[i].index = i + 1;
        printf("data_philo[%i].index = %i\n", i, data_philo[i].index);
        //set last meal to zero
        data_philo[i].t_last_meal = 0;
        printf("data_philo[%i].t_last_meal = %i\n", i, data_philo[i].t_last_meal);
        //tell which struct data struct philo will have acsses to
        data_philo[i].data = data;
        printf("data_philo[%i].data->n_philos = %d\n", i, data_philo[i].data->n_philos);
        i++;
    }
    //return array of data_philos
    return (data_philo);
}

//create philosophers (threads)
pthread_t   *create_philos(t_data *data, t_philo *data_philo)
{
    int i;
    pthread_t *tmp;

    //malloc threads
    tmp = malloc(sizeof(pthread_t) * data->n_philos);
    if (!(tmp))
        return (NULL);
    i = 0;
    //initialize thread "philo" declared in the struct data_philo
    while(i < data->n_philos)
    {
        pthread_create(&data_philo[i].philo, NULL, &routine, &data_philo[i]);
        i++;
    }
    //join in the same function? monitor joins the threads?
    //joins happens in the end of program?
    i = 0;
    while(i < data->n_philos)
    {
        pthread_join(data_philo[i].philo, NULL);
        i++;
    }
    return (tmp);
}

//create forks (mutex)
//create (one fork for each philosopher)
pthread_mutex_t *create_forks(t_data *data)
{

    //create an array of mutexes
    pthread_mutex_t *mutex;

    int i;

    //malloc mutexes
    mutex = malloc(sizeof(pthread_mutex_t) * data->n_philos);
    if(!(mutex))
        return (NULL);
    i = 0;
    //initialize mutexes
    while (i < data->n_philos)
    {
        pthread_mutex_init(&mutex[i], NULL);
        printf("fork %i initialized (mutex)\n", i + 1);
        i++;
    }
    return (mutex);
}

//make a death monitor
//receives array of philosophers threads