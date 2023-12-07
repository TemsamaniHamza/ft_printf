#include "printf.h"



int ft_handel_hexa(const char *str, int i, va_list arg)
{
    int count;
    
    count = 0;
    if (str[i] == 'x' || str[i] == 'p')
        count += ft_checkdecimal(va_arg(arg, unsigned int));
    else if (str[i] == 'X')
        count += ft_checkdecimal_caps(va_arg(arg, unsigned int ));
    return (count);
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
    return (count);
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
    return (count);
}