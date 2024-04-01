/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:33:09 by iziane            #+#    #+#             */
/*   Updated: 2024/03/22 02:40:10 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> //write
# include <stdarg.h> //variadic functions

//Prototypesss
int	ft_printf(const char *format, ...);
int	ft_putstr_ap(char *str);
int	ft_putchar_ap(int argument);
int	write_ptr(long nbr, int base);
int	write_nbr_u(unsigned long nbr, int base);
int	write_nbr(long nbr, int base);
int	write_nbr_upper(long nbr, int base);

#endif
