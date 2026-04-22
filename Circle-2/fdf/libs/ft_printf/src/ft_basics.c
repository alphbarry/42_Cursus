/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:23:06 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/07 21:50:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(int c)
{
	if ((write(1, &c, 1) == -1))
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (str[len])
	{
		if (ft_print_char(str[len]) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (ft_print_char('0') == -1)
			return (-1);
		len++;
		return (len);
	}
	if (n == -2147483648)
	{
		len += ft_print_str("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n > 0)
		len += ft_print_unsigned(n);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	d;
	int		i;

	len = 0;
	i = 0;
	if (n >= 10)
	{
		i = ft_print_unsigned (n / 10);
		if (i == -1)
			return (-1);
		len += i;
		n = n % 10;
	}
	d = n + '0';
	i = write (1, &d, 1);
	if (i == -1)
		return (-1);
	len += i;
	return (len);
}
