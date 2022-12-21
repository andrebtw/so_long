/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:21:12 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 17:44:42 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u_decimals(va_list args)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	if (ft_putnbr_u_fd(number, 1) == -1)
		return (WRITE_ERROR);
	return (ft_sizeof_nb_base_u_int(number, "0123456789"));
}

int	ft_print_decimals(va_list args)
{
	int	number;

	number = va_arg(args, int);
	if (ft_putnbr_fd_p(number, 1) == -1)
		return (WRITE_ERROR);
	return (ft_sizeof_nb_base_int(number, "0123456789"));
}
