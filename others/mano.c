#include <stdio.h>
#define S int nano_strlen(char *str)
#define T { int len = 0;
#define R while (str && *(str + len))
#define L   len++;
#define E return (len);
#define N }

S
T
R
L
E
N

int	main(int argc, char *argv[])
{
	printf ("len = %d\n", nano_strlen(argv[1]));
	return (0);
}
