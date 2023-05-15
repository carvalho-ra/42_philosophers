#include "../inc/philo.h"

//init data (struct data)
t_info  *parse_pub_info(int argc, char **argv)
{
    t_info *info;
    
    info = malloc(sizeof(t_info));
    info->ini_time = prog_start();
    info->n_philos = ft_atoi(argv[1]);
    info->t_die = ft_atoi(argv[2]);
    info->t_eat = ft_atoi(argv[3]);
    info->t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        info->n_meals = ft_atoi(argv[5]);
    info->death = 0;
    pthread_mutex_init(&info->death_mutex, NULL);
    pthread_mutex_init(&info->last_meal_mutex, NULL);
    return (info);
}

//create data philosophers (one struct for each philosopher)
t_data_philo    *priv_data_philos(t_info *info)
{
    int i;
    //create an array of structs t_philo
	t_data_philo *ph;
    //create an array of mutexes
    pthread_mutex_t *mutex;

    //call function to create forks
    mutex = create_forks(info);
    i = 0;
    //malloc array of structs (one for each philosopher)
    //that's realy necessary?
    ph = malloc(sizeof(t_data_philo) * info->n_philos);
	if (!ph)
		return NULL;
    while (i < info->n_philos)
    {
        //set forks
        ph[i].left = &mutex[i];
        //if i = number of philosophers (n_philos - 1)
        if (i == info->n_philos - 1)
            ph[i].right = &mutex[0];
        else
            ph[i].right = &mutex[i + 1];
        //set index of philosopher equal to i + 1 (take zero out)
        ph[i].index = i + 1;
        //set last meal to zero
        ph[i].t_last_meal = 0;
        //tell which struct info struct philo will have acsses to
        ph[i].info = info;
        i++;
    }
    //return array of data_philos
	return (ph);
}

void    create_th_philos(t_info *info, t_data_philo *ph)
{
    int i;
    
    i = 0;
    //initialize thread "th_philo" declared in the struct data_philo
    while(i < info->n_philos)
    {
        pthread_create(&ph[i].th_philo, NULL, &routine, &ph[i]);
        i++;
    }
}
void    join_threads(t_data_philo *ph)
{
    int i;
    //join in the same function? monitor joins the threads?
    //joins happens in the end of program?
    i = 0;
    while(i < ph->info->n_philos)
    {
        pthread_join(ph[i].th_philo, NULL);
        i++;
    }
}

//create forks (mutex)
pthread_mutex_t *create_forks(t_info *info)
{
    //create an array of mutexes
    pthread_mutex_t *mutex;
    int i;

    //malloc mutexes
    //is that necessary?
    mutex = malloc(sizeof(pthread_mutex_t) * info->n_philos);
    if(!(mutex))
        return (NULL);
    i = 0;
    //initialize mutexes
    while (i < info->n_philos)
    {
        pthread_mutex_init(&mutex[i], NULL);
        i++;
    }
    return (mutex);
}
