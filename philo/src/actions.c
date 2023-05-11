#include "../inc/philo.h"

void *routine(void *arg)
{    
    t_philo data_philo = *(t_philo *)arg;
    
    while (1) {
        // Philosopher thinks
        printf("Philosopher %d is thinking...\n", data_philo.index);
        
        // Philosopher sleeps
        printf("Philosopher %d is sleeping...\n", data_philo.index);
        usleep(data_philo.data->t_sleep);

        // Philosopher tries to grab left fork
        pthread_mutex_lock(data_philo.left);
        printf("Philosopher %d took fork %p.\n", data_philo.index, data_philo.left);
        
        // Philosopher tries to grab right fork
        pthread_mutex_lock(data_philo.right);
        printf("Philosopher %d took fork %p.\n", data_philo.index, data_philo.right);
        
        // Philosopher eats
        printf("Philosopher %d is eating...\n", data_philo.index);
        usleep(data_philo.data->t_eat);
        
        // Philosopher releases forks
        pthread_mutex_unlock(data_philo.right);
        printf("Philosopher %d released fork %p.\n", data_philo.index, data_philo.right);
        pthread_mutex_unlock(data_philo.left);
        printf("Philosopher %d released fork %p.\n", data_philo.index, data_philo.left);
    }
}
