#include "../inc/philo.h"

void    ph_eat(t_data_philo *ph)
{
    // Odd philosopher try to grab forks
    if (ph->index % 2 != 0)
    {
        pthread_mutex_lock(ph->left);
        printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
        pthread_mutex_lock(ph->right);
        printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
    }

    // Even philosopher try to grab forks
    if (ph->index % 2 == 0)
    {
        pthread_mutex_lock(ph->right);
        printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
        pthread_mutex_lock(ph->left);
        printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
    }

    // Philosopher eats
    printf("%lu %d is eating\n", curr_time(ph), ph->index);
    usleep(ph->info->t_eat * 1000);
    ph->t_last_meal = curr_time(ph);
    
    // Philosopher releases forks
    pthread_mutex_unlock(ph->right);
    pthread_mutex_unlock(ph->left);
}

void *routine(void *arg)
{    
    t_data_philo ph = *(t_data_philo *)arg;
    while (1)
    {
        //death monitor
        //usar mutex específica para variavel death
        //que pode ser lida por qualquer thread e alterada pelo monitor
        if (ph.info->death == 1)
            break ;

        //Philosopher eats
        ph_eat(&ph);
        
        // Philosopher sleeps
        printf("%lu %d is sleeping\n", curr_time(&ph), ph.index);
        usleep(ph.info->t_sleep * 1000);

        // Philosopher thinks
        printf("%lu %d is thinking\n", curr_time(&ph), ph.index);
    }
    return (NULL);
}
