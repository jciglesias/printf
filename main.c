
#include <stdio.h>
int ft_printf(const char *format, ...);
#include <unistd.h>
#define N -5
#define T "u"
#define W "15"
#define P "10"

int	main()
{
	unsigned int xxx;
	char *p = "arsta";
//	printf("'%#6.5o' [%#8.5x] '%10.5d' '%015.5f' '%.5s' [%-15.15s] [%5c] %#333\n", 123, 13, 123, 123.34, "4223544", "holaquetal", 't');

	printf("%d\n", printf("|%-0"W"."P""T"| %%0-"W"."P"\n", N));
	printf("%d\n", printf("|%0"W"."P""T"| %%0"W"."P"\n", N));
	printf("%d\n", printf("|%-"W"."P""T"| %%-"W"."P"\n", N));
	printf("%d\n", printf("|%"W"."P""T"| %%"W"."P"\n", N));
	printf("%d\n", printf("|%-0"W""T"| %%0-"W"\n", N));
	printf("%d\n", printf("|%0"W""T"| %%0"W"\n", N));
	printf("%d\n", printf("|%-"W""T"| %%-"W"\n", N));
	printf("%d\n", printf("|%"W""T"| %%"W"\n", N));

	write(1,  "\e[38;2;255;0;0m", 16);
//	ft_printf("'%#6.5o' [%#8.5x] '%10.5d' '%015.5f' '%.5s' [%-15.15s] [%5c] %#333\n", 123, 13, 123, 123.34, "4223544", "holaquetal", 't');

	printf("%d\n", ft_printf("|%-0"W"."P""T"| %%0-"W"."P"\n", N));
	printf("%d\n", ft_printf("|%0"W"."P""T"| %%0"W"."P"\n", N));
	printf("%d\n", ft_printf("|%-"W"."P""T"| %%-"W"."P"\n", N));
	printf("%d\n", ft_printf("|%"W"."P""T"| %%"W"."P"\n", N));
	printf("%d\n", ft_printf("|%-0"W""T"| %%0-"W"\n", N));
	printf("%d\n", ft_printf("|%0"W""T"| %%0"W"\n", N));
	printf("%d\n", ft_printf("|%-"W""T"| %%-"W"\n", N));
	printf("%d\n", ft_printf("|%"W""T"| %%"W"\n", N));

	printf("<%u>", -1000000000);

//ft_printf("@moulitest: %s", NULL);

	write(1, "\e[0m", 4);

	//write(1, "HH", 2);
	return (0);
}
