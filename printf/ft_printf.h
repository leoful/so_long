/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:22:10 by lbard             #+#    #+#             */
/*   Updated: 2024/12/18 15:52:01 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_strlen(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_format_x(char str, va_list ap);
unsigned int	ft_format_u(unsigned int nb);
int				ft_print_p(void *ptr);
int				ft_print_s(char *str);
int				ft_print_int(int nb);

#endif