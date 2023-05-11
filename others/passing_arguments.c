#include "philo.h"

int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void *routine(void *arg)
{
    int index = *(int *)arg;
    printf("%d ", digits[index]);
    return (0);
}

int main(void)
{
    int i;
    pthread_t   th[10];
    i = 0;
    while (i < 10)
    {
        int *j = malloc(sizeof(int));
        *j = i;
        if (pthread_create(&th[i], NULL, &routine, j) != 0)
        {
            perror("Failed to create thread");
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < 10)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return (1);
        }
        i++;
    }
}
