/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:28:03 by iziane            #+#    #+#             */
/*   Updated: 2024/03/22 02:34:43 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char specifier, va_list ap)
{
	int	counter;

	if (specifier == 'c')
		counter = ft_putchar_ap(va_arg(ap, int));
	else if (specifier == 's')
		counter = ft_putstr_ap(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		counter = write_nbr((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		counter = write_nbr((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		counter = (write_nbr_upper(va_arg(ap, unsigned int), 16));
	else if (specifier == 'u')
		counter = write_nbr_u(va_arg(ap, unsigned int), 10);
	else if (specifier == '%')
		counter = ft_putchar_ap('%');
	else if (specifier == 'p')
		counter = write_ptr(va_arg(ap, long), 16);
	else
		return (-1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		counter;
	int		error;

	va_start(ap, format);
	i = -1;
	counter = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			error = printf_format(format[++i], ap);
			if (error == -1)
				return (va_end(ap), error);
			counter += error;
			continue ;
		}
		error = write(1, &format[i], 1);
		if (error == -1)
			return (va_end(ap), error);
		counter += error;
	}
	return (va_end(ap), counter);
}

/*
	using va_list ==> object type suitable for
	holding information needed by the macros (va_start, ...)

	va_start ==> initializes the array/vektor aka a va_list that acces each argument
	va_arg ==> takes the next argument
	va_end ==> ends retrieving arguments --> free up resources

	Kochrezept: (BONUS)
	loop, that is goingto check every char of the string,
	until it finds '%' followed
	by flaggs, width, precision, data type --> store all these
	informations in buffer

	1. creating struct, that contains all these thigs above in header file
	2. Creating the loop
		0. Initialization of the data in the struct
		1. Finding '%' sign
*/
