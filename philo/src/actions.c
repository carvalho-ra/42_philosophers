#include "../inc/philo.h"

void    ph_eat(t_data_philo *ph)
{
    // Odd philosophers try to grab forks
    if (ph->index % 2 != 0)
    {
        pthread_mutex_lock(ph->left);
        print_action(ph, "has taken a fork");
        pthread_mutex_lock(ph->right);
        print_action(ph, "has taken a fork");
    }

    // Even philosophers try to grab forks
    if (ph->index % 2 == 0)
    {
        pthread_mutex_lock(ph->right);
        print_action(ph, "has taken a fork");
        pthread_mutex_lock(ph->left);
        print_action(ph, "has taken a fork");
    }

    // Philosopher eats
    print_action(ph, "is eating");
    usleep(ph->info->t_eat * 1000);
    //lock t_last_meal variable
    pthread_mutex_lock(&ph->info->last_meal_mutex);
    //update -_last_meal variable
    ph->t_last_meal = curr_time(ph);
    //unlock t_last_meal variable
    pthread_mutex_unlock(&ph->info->last_meal_mutex);

    // Philosopher releases forks
    pthread_mutex_unlock(ph->right);
    pthread_mutex_unlock(ph->left);
}

void *routine(void *arg)
{    
    t_data_philo ph = *(t_data_philo *)arg;
    while (1)
    {
        //usar mutex específica para variavel death
        //que pode ser lida por qualquer thread e alterada pelo monitor
        //lock mutex death_mutex
        pthread_mutex_lock(&ph.info->death_mutex);
        //read variable death_mutex
        if (ph.info->death == 1)
        {
            //unlock mutex death_mutex
            pthread_mutex_unlock(&ph.info->death_mutex);
            break ;
        }
        //unlock mutex death_mutex
        pthread_mutex_unlock(&ph.info->death_mutex);

        //Philosopher eats
        ph_eat(&ph);
        
        // Philosopher sleeps
        print_action(&ph, "is sleeping");
        usleep(ph.info->t_sleep * 1000);

        // Philosopher thinks
        print_action(&ph, "is thinking");
    }
    return (NULL);
}
