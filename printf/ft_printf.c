/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:49:26 by lbard             #+#    #+#             */
/*   Updated: 2024/12/15 22:02:33 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char str, va_list ap)
{
	int	count;

	count = 0;
	if (str == 'c')
	{
		ft_putchar(va_arg(ap, int));
		count++;
	}
	if (str == 's')
		count += ft_print_s(va_arg(ap, char *));
	if (str == 'p')
		count += ft_print_p(va_arg(ap, void *));
	if (str == 'd' || str == 'i')
		count += ft_print_int(va_arg(ap, int));
	if (str == 'u')
		count += ft_format_u(va_arg(ap, unsigned int));
	if (str == 'x' || str == 'X')
		count += ft_format_x(str, ap);
	if (str == '%')
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			count++;
		}
		else
		{
			i++;
			count += ft_format(str[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
