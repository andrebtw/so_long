/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:57:45 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 17:13:53 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char_check(const char *s, int i, va_list args)
{
	if (s[i] == '%')
	{
		if (s[i + 1] == 'c')
			return (ft_print_char(args));
		else if (s[i + 1] == '%')
			return (ft_print_pourcentage());
		else if (s[i + 1] == 's')
			return (ft_print_string(args));
		else if (s[i + 1] == 'p')
			return (ft_print_pointer_hex(args));
		else if (s[i + 1] == 'i' || s[i + 1] == 'd')
			return (ft_print_decimals(args));
		else if (s[i + 1] == 'u')
			return (ft_print_u_decimals(args));
		else if (s[i + 1] == 'x')
			return (ft_print_hex_lower(args));
		else if (s[i + 1] == 'X')
			return (ft_print_hex(args));
		else
			return (NO_FORMAT_SPEC);
	}
	if (ft_putchar_fd_p(s[i], 1) == -1)
		return (WRITE_ERROR);
	return (0);
}

int	ft_print_loop(const char *s, va_list args, int return_size, int i)
{
	int	size_string;

	while (s[i])
	{
		size_string = ft_printf_char_check(s, i, args);
		if (size_string > 0)
			i++;
		else if (size_string == EMPTY_V && ++i)
			size_string = 0;
		else if (size_string == NULL_V && ++i)
		{
			size_string = ft_null_found();
			if (size_string == -1)
				return (WRITE_ERROR);
		}
		else if (size_string == WRITE_ERROR)
			return (WRITE_ERROR);
		else if (size_string == NO_FORMAT_SPEC)
			size_string = 0;
		else
			return_size++;
		return_size = return_size + size_string;
		i++;
	}
	return (return_size);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		return_size;
	int		i;

	i = 0;
	return_size = 0;
	va_start(args, s);
	return_size = ft_print_loop(s, args, return_size, i);
	va_end(args);
	if (return_size == WRITE_ERROR)
		return (-1);
	return (return_size);
}
