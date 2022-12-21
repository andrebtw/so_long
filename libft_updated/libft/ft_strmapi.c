/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:53:28 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/19 18:53:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r_string;
	int		i;

	r_string = (char *) malloc (ft_strlen(s) + 1);
	if (!r_string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r_string[i] = f(i, s[i]);
		i++;
	}
	r_string[i] = '\0';
	return (r_string);
}
