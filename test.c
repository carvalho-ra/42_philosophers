#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
	struct timeval jorgin;
	gettimeofday(&jorgin, NULL);

	long long	oi, cris, mv;

	oi = jorgin.tv_sec * 1000 + jorgin.tv_usec / 1000;
	printf("oi -> %lld\n", oi);

	while(1)
	{
		if(cris >= 10 * 1000)
			break ;
		struct timeval ro;
		gettimeofday(&ro, NULL);
		mv = ro.tv_sec * 1000 + ro.tv_usec / 1000;
		cris = mv - oi; 
		printf("cris ->%lld\n", cris);
		usleep(100);
	}
	printf("cris -> %lld\ndeu green\n", cris);
}
