#include "philo.h"

int mails = 0;

void    *routine()
{
    int i;
    
    i = 0;
    while (i < 1000000)
    {
        mails++;
        i++;
    }
    return (0);
}

int main(void)
{
    pthread_t   t1;
    pthread_t   t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    {
        return (1);
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        return (1);
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return (1);
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return (1);
    }
    printf("Number of mails = %d\n", mails);
    return (0);
}
