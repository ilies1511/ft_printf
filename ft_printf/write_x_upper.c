/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:14:17 by iziane            #+#    #+#             */
/*   Updated: 2024/03/22 02:22:38 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_nbr_upper(long nbr, int base)
{
	int		counter;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	counter = 0;
	if (nbr < 0)
	{
		counter = ft_putchar_ap('-');
		if (counter != -1)
			return (write_nbr_upper((-1) * nbr, base) + 1);
	}
	else if (nbr < (long)base)
		return (ft_putchar_ap(symbols[nbr]));
	else
	{
		counter = write_nbr_upper(nbr / base, base);
		if (counter != -1)
			return (counter + ft_putchar_ap(symbols[nbr % base]));
	}
	return (-1);
}
