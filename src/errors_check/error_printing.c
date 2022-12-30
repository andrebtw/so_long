/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:38:47 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/30 11:38:47 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_printing(char *details, char *advice, char *example)
{
	ft_printf("%sError\n\n%s", KRED, KNORMAL);
	ft_printf("%sDetails: %s%s\n", KRED, details, KNORMAL);
	ft_printf("%sAdvice: %s%s\n", KRED, advice, KNORMAL);
	ft_printf("%sExample: %s%s\n\n", KRED, example, KNORMAL);
	ft_printf("%sPlease try again!%s\n", KYELLOW, KNORMAL);
}
