#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
int ft_checkdicimal(unsigned int n)
{
    int count;

    count = 0;
    char *str= "0123456789abcdef";
    if (n > 15)
    {
        count += ft_checkdicimal(n / 16);
        count += ft_putchar(ft_checkdicimal[n % 16]);
    }
    else
         count += ft_putchar(ft_checkdicimal[n]);
    return (count);
}

int main()
{
    unsigned int n = 444;
    ft_checkdicimal(n);
    return (0);
}
/* int ft_hexadicimal_base(unsigned int nb)
{
    char str[15] = "0123456789abcdef";
    char c[15];
    int i = 0;
    while (nb > 9)
    {

    }
} */