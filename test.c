#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_checkdecimal_caps(unsigned int n)
{
    char *str = "0123456789ABCDEF";
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

int main()
{
	unsigned int n = 15145;
	ft_checkdecimal_caps(n);
	printf("%d", n);
}
