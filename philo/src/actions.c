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
    
    //lock t_last_meal variable
    pthread_mutex_lock(&ph->info->last_meal_mutex);
    //update - t_last_meal variable
    ph->t_last_meal = curr_time(ph);
    //unlock t_last_meal variable
    pthread_mutex_unlock(&ph->info->last_meal_mutex);
    
    //fix number of meals
    pthread_mutex_lock(&ph->info->n_meals_mutex);
    ph->meals++;
    pthread_mutex_unlock(&ph->info->n_meals_mutex);

    //trying to use smart sleep
    //usleep(ph->info->t_eat * 1000);
    smart_sleep(ph->info->t_eat, ph);


    // Philosopher releases forks
    pthread_mutex_unlock(ph->right);
    pthread_mutex_unlock(ph->left);
}

void *routine(void *arg)
{
    //aqui estava com erro
    //quando passava o cast para dentro de uma nova struct ph e não para um *ph
    t_data_philo *ph = (t_data_philo *)arg;
    while (1)
    {
        //usar mutex específica para variavel death
        //que pode ser lida por qualquer thread e alterada pelo monitor
        //lock mutex death_mutex
        pthread_mutex_lock(&ph->info->death_mutex);
        //read variable death
        if (ph->info->death == 1)
        {
            //unlock mutex death_mutex
            pthread_mutex_unlock(&ph->info->death_mutex);
            break ;
        }
        //unlock mutex death_mutex
        pthread_mutex_unlock(&ph->info->death_mutex);
        
        // check if ph.n_meals foi satisfeito
        pthread_mutex_lock(&ph->info->n_meals_mutex);
        if (ph->info->n_meals != 0 && ph->meals == ph->info->n_meals)
        {
            pthread_mutex_unlock(&ph->info->n_meals_mutex);
            break ;
        }
        pthread_mutex_unlock(&ph->info->n_meals_mutex);

        //Philosopher eats
        ph_eat(ph);

        // Philosopher sleeps
        print_action(ph, "is sleeping");
        
        //trying to use smart sleep
        //usleep(ph->info->t_sleep * 1000);
        smart_sleep(ph->info->t_sleep, ph);

        // Philosopher thinks
        print_action(ph, "is thinking");
        //Tawan's help to avoid death
        usleep(100);
    }
    return (NULL);
}

//death monitor
void *death_monitor(t_data_philo *ph)
{
    int i;
    
    i = 0;
    while (1)
    {
        if (i == ph[i].info->n_philos - 1)
            i = 0;
        
        // check if ph.n_meals foi satisfeito
        pthread_mutex_lock(&ph->info->n_meals_mutex);
        if (ph->info->n_meals != 0 && ph->meals == ph->info->n_meals)
        {
            pthread_mutex_unlock(&ph->info->n_meals_mutex);
            break ;
        }
        pthread_mutex_unlock(&ph->info->n_meals_mutex);
        

        //lock last meal mutex
        pthread_mutex_lock(&ph->info->last_meal_mutex);
        //read variable t_last_meal
        if ((curr_time(ph) - ph[i].t_last_meal) >= ph[i].info->t_die)
        {
            //unlock last meal mutex
            pthread_mutex_unlock(&ph[i].info->last_meal_mutex);
            pthread_mutex_lock(&ph[i].info->death_mutex);
            ph[i].info->death = 1;
            pthread_mutex_unlock(&ph[i].info->death_mutex);


            //print_action has mutex inside of it
            //but is not workin because it has an if death != 1
            //in this case death == 1
            //had to change print_action function
            print_action(&ph[i], "died");
            //printf("%lu %d died\n", curr_time(ph), ph[i].index);
            return (NULL);
        }
        i++;
        pthread_mutex_unlock(&ph->info->last_meal_mutex);
        usleep(100);
    }
    return (NULL);
}

//print action
void print_action(t_data_philo *ph, char *action)
{
    pthread_mutex_lock(&ph->info->death_mutex);
    //had to change to include death print
    if (ph->info->death != 1 || (ph->info->death == 1 && ft_strlen(action) == 4))
    {
        //pthread_mutex_unlock(&ph->info->death_mutex);
        printf("%lu %d %s\n", curr_time(ph), ph->index, action);
    }
    pthread_mutex_unlock(&ph->info->death_mutex);
}
