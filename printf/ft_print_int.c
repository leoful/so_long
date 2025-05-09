/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:58:37 by lbard             #+#    #+#             */
/*   Updated: 2024/12/16 19:06:58 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i = 1;
	}
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int nb)
{
	int			i;
	char		*str;
	long int	num;

	num = nb;
	i = ft_nbrlen(nb);
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		i--;
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

int	ft_print_int(int nb)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_itoa(nb);
	ft_putstr(str);
	count = ft_strlen(str);
	free(str);
	return (count);
}
