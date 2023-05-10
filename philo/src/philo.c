#include "../inc/philo.h"

int main(int argc, char **argv)
{
    //create struc with public information
    t_info *info;

    int i;

    //parse information to struct info
    info = parse(argc, argv);

    //create array of structs of private information about philosophers
    t_philo *data[info->n_philos];

    //initialize structs of philosophers
    *data = data_philos(info);

    //print struct info
    printf("argument 1 = %d\n", info->t_start);
    printf("argument 2 = %d\n", info->n_philos);
    printf("argument 3 = %d\n", info->t_die);
    printf("argument 4 = %d\n", info->t_eat);
    printf("argument 5 = %d\n", info->t_sleep);
    printf("argument 6 = %d\n", info->n_meals);
    
    //print struct data (philo)
    i = 0;
    while (i < info->n_philos)
    {
        printf("Philosopher = %d\n", data[i]->index);
        printf("Last meal = %d\n", data[i]->t_last_meal);
        printf("info - n_philos = %d\n", data[i]->info->n_philos);
        i++;
    }

    return (0);
}
