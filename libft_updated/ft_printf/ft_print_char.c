/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:54:02 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 16:40:12 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	print_c;

	print_c = (char)va_arg(args, int);
	if (ft_putchar_fd_p(print_c, 1) == -1)
		return (WRITE_ERROR);
	return (1);
}
