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
int ft_handlerall(const char *str, int i,   va_list arg)
{
    int count;

    count = 0;
    if (str[i] == 'c' || str[i] == 's')
        count = ft_handelc(str, i, arg);
    return (count);
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
			count += write (1, &str[i], 1);
			i++;
	}
	return (count);
}
#include <stdlib.h>

int main()
 {
    // ft_printf("%d\n", ft_printf("%s -> %c ->", "HELLO", 'c'));
    // int result1 = ft_printf("%s -> %c ->", "HELLO", 'c');
    // ft_printf(" res = %d\n", result1);
	// int n2 = ft_printf("%s -> %p\n",NULL , NULL);
	// ft_printf("%d\n", n2);
    int l = ft_printf("%s -> " ,"HELLO ");
    ft_printf("%d", l);
    return (0);
}