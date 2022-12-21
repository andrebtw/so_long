/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:09:34 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 16:45:58 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(va_list args)
{
	char	*print_s;

	print_s = va_arg(args, char *);
	if (!print_s)
		return (NULL_V);
	if (ft_putstr_fd_p(print_s, 1) == -1)
		return (WRITE_ERROR);
	if (ft_strlen_p(print_s))
		return (ft_strlen_p(print_s));
	return (EMPTY_V);
}
