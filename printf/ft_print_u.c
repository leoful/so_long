/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:04:39 by lbard             #+#    #+#             */
/*   Updated: 2024/12/15 22:09:10 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_unsigned(unsigned int nb)
{
	int		i;
	char	*str;

	i = ft_nbrlen(nb);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
	}
	while (nb > 0)
	{
		i--;
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

unsigned int	ft_format_u(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_itoa_unsigned(nb);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
