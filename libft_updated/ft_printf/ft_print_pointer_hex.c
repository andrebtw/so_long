/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:01:46 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 16:49:26 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_hex(va_list args)
{
	unsigned long long	number;

	number = (unsigned long long)va_arg(args, void *);
	if (write(1, "0x", 2) == -1)
		return (WRITE_ERROR);
	ft_putbase_fd_p(number, 1, "0123456789abcdef");
	return (ft_sizeof_nb_base_u(number, "0123456789abcdef") + 2);
}
