#include "../inc/philo.h"

void    ph_eat(t_data_philo *ph)
{
    // Odd philosophers try to grab forks
    if (ph->index % 2 != 0)
    {
        pthread_mutex_lock(ph->left);
        print_action(ph, "has taken a fork");
        //printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
        pthread_mutex_lock(ph->right);
        print_action(ph, "has taken a fork");
        //printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
    }

    // Even philosophers try to grab forks
    if (ph->index % 2 == 0)
    {
        pthread_mutex_lock(ph->right);
        print_action(ph, "has taken a fork");
        //printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
        pthread_mutex_lock(ph->left);
        print_action(ph, "has taken a fork");
        //printf("%lu %d has taken a fork\n", curr_time(ph), ph->index);
    }

    // Philosopher eats
    print_action(ph, "is eating");
    //printf("%lu %d is eating\n", curr_time(ph), ph->index);
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
        pthread_mutex_lock(&ph.info->death_mutex);
        if (ph.info->death == 1)
        {
            pthread_mutex_unlock(&ph.info->death_mutex);
            break ;
        }

        pthread_mutex_unlock(&ph.info->death_mutex);

        //Philosopher eats
        ph_eat(&ph);
        
        // Philosopher sleeps
        print_action(&ph, "is sleeping");
        //printf("%lu %d is sleeping\n", curr_time(&ph), ph.index);
        usleep(ph.info->t_sleep * 1000);

        // Philosopher thinks
        print_action(&ph, "is thinking");

        //printf("%lu %d is thinking\n", curr_time(&ph), ph.index);

    }
    return (NULL);
}
