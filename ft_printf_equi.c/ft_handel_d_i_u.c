#include "printf.h"


int ft_handlenum(const char *str, int i, va_list arg)
{
	int count;

	count = 0;
	if (str[i] == 'i' || str[i] == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'u')
		count += ft_putnbr_long(va_arg(arg, unsigned long));
	return (count);
}
int	ft_putnbr(int n)
{
	long	nbr;
	char	c[10];
	int		i;
	int		j;

	nbr = n;
	i = 0;
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
