#include "philo.h"

void    *routine()
{
    printf("Test thread 1\n");
    printf("End of routine 1\n");
    return (0);
}

void    *routine2()
{
    printf("Test thread 2\n");
    printf("End of routine 2\n");
    return (0);
}

int main(void)
{
    pthread_t   t1;
    pthread_t   t2;

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return (0);
}
