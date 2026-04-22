/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:40:33 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/08 12:32:39 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_is_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_is_pointer(ptr / 16);
		ft_is_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
		{
			if (ft_print_char(ptr + '0') == -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(ptr - 10 + 'a') == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_len_pointer(unsigned long long ptr)
{
	int	l;

	l = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		l++;
	}
	return (l);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	l;
	int	r;

	l = ft_print_str("0x");
	if (l == -1)
		return (-1);
	if (ptr == 0)
	{
		r = ft_print_char('0');
		if (r == -1)
			return (-1);
		l++;
	}
	else
	{
		ft_is_pointer(ptr);
		r = ft_len_pointer(ptr);
		if (r == -1)
			return (-1);
		l += r;
	}
	return (l);
}
