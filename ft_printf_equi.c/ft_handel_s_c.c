#include "printf.h"


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
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
int ft_handelc(const char *str, int i, va_list arg)
{
    int count;

    count = 0;
	if (str[i] == 'c')
	{
		char c = va_arg(arg, int);
		write (1, &c, 1);
		count++;
	}
	else if (str[i] == 's')
		count += ft_print(va_arg(arg, char *));
    return (count);
}  