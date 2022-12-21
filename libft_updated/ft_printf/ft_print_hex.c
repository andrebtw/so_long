/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:58:34 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 17:46:14 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	if (ft_putbase_int_fd(number, 1, "0123456789abcdef") == -1)
		return (WRITE_ERROR);
	return (ft_sizeof_nb_base_u(number, "0123456789abcdef"));
}

int	ft_print_hex(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	if (ft_putbase_int_fd(number, 1, "0123456789ABCDEF") == -1)
		return (WRITE_ERROR);
	return (ft_sizeof_nb_base_u(number, "0123456789ABCDEF"));
}
