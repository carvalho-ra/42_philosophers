#include "../inc/philo.h"

void *routine(void *arg)
{    
    t_philo ph = *(t_philo *)arg;
    
    while (1) {
        // Philosopher thinks
        printf("Philosopher %d is thinking...\n", ph.index);
        
        // Philosopher sleeps
        printf("Philosopher %d is sleeping...\n", ph.index);
        usleep(ph.data->t_sleep);

        // Odd philosopher try to grab left fork
        if (ph.index % 2 != 0)
        {
            pthread_mutex_lock(ph.left);
            printf("Philosopher %d took fork %p.\n", ph.index, ph.left);
        }

        // Even philosopher try to grab right fork
        if (ph.index % 2 == 0)
        {
            pthread_mutex_lock(ph.right);
            printf("Philosopher %d took fork %p.\n", ph.index, ph.right);
        }

        // Odd philosopher try to grab right fork
        if (ph.index % 2 != 0)
        {
            pthread_mutex_lock(ph.right);
            printf("Philosopher %d took fork %p.\n", ph.index, ph.right);
        }

        // Even philosopher try to grab left fork
        if (ph.index % 2 == 0)
        {
            pthread_mutex_lock(ph.left);
            printf("Philosopher %d took fork %p.\n", ph.index, ph.left);
        }

        // Philosopher eats
        printf("Philosopher %d is eating...\n", ph.index);
        usleep(ph.data->t_eat);
        ph.t_last_meal = curr_time() - ph.data->ini_time;
        
        // Philosopher releases forks
        pthread_mutex_unlock(ph.right);
        printf("Philosopher %d released fork %p.\n", ph.index, ph.right);
        pthread_mutex_unlock(ph.left);
        printf("Philosopher %d released fork %p.\n", ph.index, ph.left);

    }
}
