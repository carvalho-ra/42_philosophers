#include "../inc/philo.h"

//think
void    ph_think(t_philo *data)
{
    printf("Philosopher %i is thinking...", data->index);
}

//sleep
void    ph_sleep(t_philo *data)
{
    printf("Philosopher %i is sleeping...", data->index);
    usleep(data->data->t_sleep);
}

//eat
void    ph_eat(t_philo *data)
{
    printf("Philosopher %i is eating...", data->index);
    usleep(data->data->t_eat);
    //save time
    data->t_last_meal = curr_time();
}

