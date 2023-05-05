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
    usleep(data->data->time_to_sleep);
}

//eat
void    ph_eat(t_philo *data)
{
    printf("Philosopher %i is eating...", data->index);
    usleep(data->data->time_to_eat);
    //save time
    data->time_last_meal = curr_time();
}

