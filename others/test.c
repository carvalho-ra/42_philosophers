#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// int main()
// {
// 	struct timeval jorgin;
// 	gettimeofday(&jorgin, NULL);

// 	long long	oi, cris, mv;

// 	oi = jorgin.tv_sec * 1000 + jorgin.tv_usec / 1000;
// 	printf("oi -> %lld\n", oi);

// 	while(1)
// 	{
// 		if(cris >= 10 * 1000)
// 			break ;
// 		struct timeval ro;
// 		gettimeofday(&ro, NULL);
// 		mv = ro.tv_sec * 1000 + ro.tv_usec / 1000;
// 		cris = mv - oi; 
// 		printf("cris ->%lld\n", cris);
// 		usleep(100);
// 	}
// 	printf("cris -> %lld\ndeu green\n", cris);
// }

//smart time
int	main(void)
{
	unsigned long	tm1;
	unsigned long	tm2;

	struct timeval first;
	struct timeval second;

	gettimeofday(&first, NULL);
	tm1 = (first.tv_sec * 1000) + (first.tv_usec / 1000);
	while (1)
	{
		gettimeofday(&second, NULL);
		tm2 = (second.tv_sec * 1000) + (second.tv_usec / 1000);
		if (tm2 - tm1 >= 10 * 1000)
			break;
		usleep(100);
	}
	printf("time = %lu\n", tm2 - tm1);
}
