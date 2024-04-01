/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:15:50 by iziane            #+#    #+#             */
/*   Updated: 2024/03/22 07:36:01 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_nbr_u(unsigned long nbr, int base)
{
	int		counter;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (nbr < 0)
	{
		counter = ft_putchar_ap('-');
		if (counter == -1)
			return (-1);
		return (write_nbr_u((-1) * nbr, base) + 1);
	}
	else if (nbr < (unsigned long)base)
	{
		counter = ft_putchar_ap(symbols[nbr]);
		if (counter != -1)
			return (counter);
	}
	else
	{
		counter = write_nbr_u(nbr / base, base);
		if (counter != -1)
			return (counter + write_nbr_u(nbr % base, base));
	}
	return (-1);
}
