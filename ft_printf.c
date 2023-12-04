#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

char *ft_print(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (str);
}

void	ft_putnbr_long(unsigned int n)
{
	unsigned long	nbr;
	char	c[10];
	int		i;

	nbr = n;
	i = 0;

	while (nbr > 9)
	{
		c[i] = (nbr % 10) + '0';
		nbr = (nbr / 10);
		i++;
	}
	c[i] = nbr + '0';
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
	}
	return ;
}

int ft_handlerall(const char *str,int i,va_list arg)
{
	if (str[i] == 'c')
	{
		char c = va_arg(arg, int);
		write (1, &c, 1);
	}
	if (str[i] == 's')
	{
		char *a = va_arg(arg, char *);
		ft_print(a);
	}
	if (str[i] == 'd' || str[i] == 'i')
	{
		long d = va_arg(arg, long);
		ft_putnbr_fd(d,1);
	}
	if (str[i] == 'u')
	{
		unsigned long l = va_arg(arg, unsigned long);
		ft_putnbr_long(l);
	}
	return (0);

}

int ft_printf(const char *str, ...)
{
	va_list arg;
	int i = 0;

	va_start(arg,str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_handlerall(str, i, arg);
		}
		else if (ft_isprint(str[i]))
		{
			write (1, &str[i], 1);
		}
			i++;
	}
	return (0);
}

int main()
{
	char d = 'd';
	char *str = "HAAAAAAAAA";
	ft_printf("the charcheter is %c and the string is %s i'm writing this number %d and this is unsigned int maximum %u ",d,str,123, 4294967295);
}

