#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_t
{
	int	i;
	int	j;
}
t_t;

void	*rotina(void *ptr)
{
	t_t seila = (t_t *)ptr;

	while(seila->i < 200)
	{
		printf("%i\n", seila->i);
		seila->i++;
	}
	return (NULL);
}

int	main(void)
{
	t_t 		x = {0};
	pthread_t	th;
	pthread_t	th2;
	
	pthread_create(&th, NULL, &rotina, &x);
	pthread_create(&th2, NULL, &rotina, &x);
	pthread_join(th, NULL);
	pthread_join(th2, NULL);

	return (0);
}
