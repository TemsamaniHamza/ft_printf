#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

int ft_print(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
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
	int count = 0;
	if (str[i] == 'c')
	{
		char c = va_arg(arg, int);
		write (1, &c, 1);
		count++;
	}
	if (str[i] == 's')
	{
		count += ft_print(va_arg(arg, char *));
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
	return(count);

}

int ft_printf(const char *str, ...)
{
	va_list arg;
	int i = 0;
	int j = 0;
	va_start(arg,str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += ft_handlerall(str, i, arg);
		}
		else if (ft_isprint(str[i]))
		{
			write (1, &str[i], 1);
		}
			i++;
	}
	return (j);
}

int main()
{
	int n1 = ft_printf("%s","this is just a test");
	printf("\n");
	ft_printf("%d", n1);
	printf("\n");
	int n2 = printf("%s", "this is just a test");
	printf("%d\n", n2);
}

