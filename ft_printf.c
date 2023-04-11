/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:57 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/03/07 14:51:49 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr(int n)
{
	char	c;
	int		sum;

	sum = 0;
	if (n == -2147483648)
	{
		sum += ft_putnbr(n / 10);
		sum += ft_putchar('8');
	}
	else if (n < 0)
	{
		sum += ft_putchar('-');
		sum += ft_putnbr(n / (-1));
	}
	else
	{
		if (n >= 10)
			sum += ft_putnbr(n / 10);
		c = n % 10 + '0';
		sum += ft_putchar(c);
	}
	return (sum);
}

static int	ft_check(char s, va_list ap)
{
	int	sum;

	sum = 0;
	if (s == 'c')
		sum += ft_putchar(va_arg(ap, int));
	else if (s == '%')
		sum += ft_putchar('%');
	else if (s == 's')
		sum += ft_putstr(va_arg(ap, char *));
	else if (s == 'd' || s == 'i')
		sum += ft_putnbr(va_arg(ap, int));
	return (sum);
}

int	ft_printf(const char *s, ...)
{
	int		sum;
	int		i;
	va_list	ap;

	i = 0;
	sum = 0;
	va_start(ap, s);
	while (s[i] != 0)
	{
		if (s[i] == '%')
			sum += ft_check(s[++i], ap);
		else
			sum += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (sum);
}
