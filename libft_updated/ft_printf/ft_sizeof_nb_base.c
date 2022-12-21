/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_nb_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:15:45 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/30 18:44:38 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizeof_nb_base_u_int(unsigned int number, char *base)
{
	int	size;

	size = 0;
	if (!number)
		return (1);
	while (number != 0)
	{
		number = number / ft_strlen_p(base);
		size++;
	}
	return (size);
}

int	ft_sizeof_nb_base_u(unsigned long number, char *base)
{
	int	size;

	size = 0;
	if (!number)
		return (1);
	while (number != 0)
	{
		number = number / ft_strlen_p(base);
		size++;
	}
	return (size);
}

int	ft_sizeof_nb_base_int(long number, char *base)
{
	int		size;
	long	nb;

	size = 0;
	nb = number;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		size++;
		nb = nb * (-1);
	}
	while (nb != 0)
	{
		nb = nb / ft_strlen_p(base);
		size++;
	}
	return (size);
}
