/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:36:47 by lbard             #+#    #+#             */
/*   Updated: 2024/12/16 19:06:57 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_countnbr_base(unsigned long int nb, int base)
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

static char	*ft_itoa_base(unsigned long int nb, int base)
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
		else
			str[i] = stash - 10 + 'a';
		nb /= base;
	}
	return (str);
}

int	ft_print_p(void *ptr)
{
	char	*str;
	int		len;

	str = ft_itoa_base((unsigned long)ptr, 16);
	if (!str || ((unsigned long)ptr == 0))
	{
		free(str);
		ft_putstr("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	ft_putstr(str);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
