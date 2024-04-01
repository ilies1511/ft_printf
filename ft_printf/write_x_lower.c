/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_x_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:23:53 by iziane            #+#    #+#             */
/*   Updated: 2024/03/22 17:56:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_nbr(long nbr, int base)
{
	int		counter;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (nbr < 0)
	{
		counter = ft_putchar_ap('-');
		if (counter == -1)
			return (-1);
		return (write_nbr((-1) * nbr, base) + 1);
	}
	else if (nbr < (long)base)
	{
		counter = ft_putchar_ap(symbols[nbr]);
		if (counter != -1)
			return (counter);
	}
	else
	{
		counter = write_nbr(nbr / base, base);
		if (counter != -1)
			return (counter + write_nbr(nbr % base, base));
	}
	return (-1);
}
