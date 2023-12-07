#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

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
int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
int ft_checkdecimal(unsigned int n)
{
    char *str = "0123456789abcdef";
    int count = 0;

    if (n > 15)
    {
        count += ft_checkdecimal(n / 16);
        count += ft_putchar(str[n % 16]);
    }
    else
        count += ft_putchar(str[n]);
    return count;
}

int ft_checkdecimal_caps(unsigned int n)
{
    char *str = "0123456789ABCDEF";
    int count = 0;

    if (n > 15)
    {
        count += ft_checkdecimal_caps(n / 16);
        count += ft_putchar(str[n % 16]);
    }
    else
        count += ft_putchar(str[n]);
    return count;
}

int	ft_putnbr_long(unsigned int n)
{
	unsigned long	nbr;
	char	c[10];
	int		i;
	int		j;
	nbr = n;
	i = 0;

	while (nbr > 9)
	{
		c[i] = (nbr % 10) + '0';
		nbr = (nbr / 10);
		i++;
	}
	c[i] = nbr + '0';
	j = i + 1;
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
	}
	return (j);
}

int	ft_putnbr(int n)
{
	long	nbr;
	char	c[10];
	int		i;
	int		j;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		c[i] = (nbr % 10) + '0';
		nbr = (nbr / 10);
		i++;
	}
	c[i] = nbr + '0';
	j = i + 1;
	while (i >= 0)
	{
		write(1, &c[i], 1);
		i--;
	}
	return (j);
}




int ft_printf(const char *str, ...)
{
	va_list arg;
	int i = 0;
	int j = 0;
	int count = 0;

	if (!str)
		return 0;
	va_start(arg,str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_handlerall(str, i, arg);
		}
		else
		{
			count += write (1, &str[i], 1);
		}
			i++;
	}
	return (count);
}
#include <stdlib.h>

int main()
 {
	char *ptr = malloc(999);
	int n1 = printf("%s -> %p\n",NULL , NULL);
	printf("%d\n", n1); 
	// int n2 = ft_printf("%s -> %p\n",NULL , NULL);
	// ft_printf("%d\n", n2);
	return (0);
}