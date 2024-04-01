/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:48:14 by iziane            #+#    #+#             */
/*   Updated: 2024/03/22 02:37:36 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_ptr(long nbr, int base)
{
	int	error;

	error = ft_putstr_ap("0x");
	if (error == -1)
		return (error);
	error = write_nbr_u(nbr, base);
	if (error == -1)
		return (error);
	return (error + 2);
}
