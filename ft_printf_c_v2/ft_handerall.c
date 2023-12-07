#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

int ft_handlerall(const char *str,int i,va_list arg)
{
	int count = 0;
	if (str[i] == 'c')
	{
		char c = va_arg(arg, int);
		write (1, &c, 1);
		count++;
	}
	else if (str[i] == 's')
		count += ft_print(va_arg(arg, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'u')
		count += ft_putnbr_long(va_arg(arg, unsigned long));
	else if (str[i] == 'x')
		count += ft_checkdecimal(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		count += ft_checkdecimal_caps(va_arg(arg, unsigned int));
	else if (str[i] == 'p')
	{
		if (!va_arg(arg, unsigned int))
			count += ft_print("(nil)");
		else
			count += ft_checkdecimal(va_arg(arg, unsigned int));
	}
	return(count);

}

int ft_handlerall(const char *str,int i,va_list arg)
{
    int count;

    count = 0;
    if (str[i] == 'c' || str[i] == 's')
        count += ft_handelc(str, i), arg;
    return (count);
}

int ft_handelc(const char *str, int i, va_list arg)
{
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