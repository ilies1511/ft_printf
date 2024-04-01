/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:28:07 by iziane            #+#    #+#             */
/*   Updated: 2024/03/21 22:30:18 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ap(char *str)
{
	int	i;
	int	counter;
	int	error;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			error = ft_putchar_ap(str[i++]);
			if (error == -1)
				return (error);
			counter += error;
		}
	}
	return (counter);
}
