#include "printf.h"

int ft_printf(const char *str, ...)
{
	va_list arg;
	int i = 0;
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