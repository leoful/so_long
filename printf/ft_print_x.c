/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:00:32 by lbard             #+#    #+#             */
/*   Updated: 2024/12/16 19:07:01 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countnbr_base(unsigned int nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static char	*ft_itoa_base(unsigned int nb, int base, char MAJ_or_min)
{
	char	*str;
	int		i;
	int		stash;

	i = ft_countnbr_base(nb, base);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		i--;
		stash = nb % base;
		if (stash < 10)
			str[i] = stash + '0';
		else if (MAJ_or_min == 'a')
			str[i] = stash - 10 + 'a';
		else if (MAJ_or_min == 'A')
			str[i] = stash - 10 + 'A';
		nb /= base;
	}
	return (str);
}

int	ft_format_x(char str, va_list ap)
{
	unsigned int	num;
	char			*number_str;
	int				len;

	num = va_arg(ap, unsigned int);
	if (str == 'x')
		number_str = ft_itoa_base(num, 16, 'a');
	else if (str == 'X')
		number_str = ft_itoa_base(num, 16, 'A');
	if (!number_str)
	{
		ft_putstr("(nil)");
		free(number_str);
		return (5);
	}
	ft_putstr(number_str);
	len = ft_strlen(number_str);
	free(number_str);
	return (len);
}
