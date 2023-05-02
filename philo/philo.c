#include "philo.h"

int mails = 0;
pthread_mutex_t mutex;

void    *routine()
{
    int i;
    
    i = 0;
    while (i < 1000000)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        i++;
        pthread_mutex_unlock(&mutex);
    }
    return (0);
}

int main(void)
{
    int i;
    pthread_t   th[8];
    
    pthread_mutex_init(&mutex, NULL);
    i = 0;
    while (i < 8)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            return (1);
        }
        printf("Thread %i started\n", i);
        i++;
    }
    i = 0;
    while (i < 8)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            return (1);
        }
        printf("Thread %i finished\n", i);

        i++;
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails = %d\n", mails);
    return (0);
}
