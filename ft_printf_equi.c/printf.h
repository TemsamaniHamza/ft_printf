#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int ft_handlenum(const char *str, int i, va_list arg);
int	ft_putnbr(int n);
int	ft_putnbr_long(unsigned int n);
int ft_putchar(char c);
int ft_print(char *str);
int ft_handelc(const char *str, int i, va_list arg);
int ft_handel_hexa(const char *str, int i, va_list arg);
int ft_checkdecimal(unsigned int n);
int ft_checkdecimal_caps(unsigned int n);
int ft_handlerall(const char *str, int i,   va_list arg);

#endif