/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:57:10 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/08 12:33:00 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex_char(unsigned int num, char word)
{
	if (num < 10)
	{
		if (ft_print_char(num + '0') == -1)
			return (-1);
	}
	else
	{
		if (word == 'x')
		{
			if (ft_print_char(num - 10 + 'a') == -1)
				return (-1);
		}
		else if (word == 'X')
		{
			if (ft_print_char(num - 10 + 'A') == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_is_hexadecimal(unsigned int num, char word)
{
	if (num >= 16)
	{
		if (ft_is_hexadecimal(num / 16, word) == -1)
			return (-1);
		if (ft_is_hexadecimal(num % 16, word) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_hex_char(num, word) == -1)
			return (-1);
	}
	return (0);
}

int	ft_len_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

int	ft_print_hexadecimal(unsigned int num, char word)
{
	int	r;

	if (num == 0)
	{
		r = ft_print_char('0');
		if (r == -1)
			return (-1);
		return (1);
	}
	else
	{
		r = ft_is_hexadecimal(num, word);
		if (r == -1)
			return (-1);
	}
	return (ft_len_hexadecimal(num));
}
