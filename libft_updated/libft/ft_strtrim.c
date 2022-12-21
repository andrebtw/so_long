/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:35:19 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/21 12:07:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinchar(char const *string, char c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_skipbegin(char const *string, char const *set, int s1_index)
{
	int	start;

	start = 0;
	if (ft_isinchar(set, string[s1_index]))
	{
		while (ft_isinchar(set, string[s1_index]))
		{
			s1_index++;
			start++;
		}
	}
	return (start);
}

static int	ft_skipend(char const *string, char const *set,
			int s1_index, int end)
{
	while (string[s1_index])
	{
		end = 0;
		while (ft_isinchar(set, string[s1_index]) && string[s1_index])
		{
			end++;
			s1_index++;
		}
		if (!string[s1_index])
			return (end);
		s1_index++;
	}
	return (0);
}

static char	*ft_r_string(char const *s1, int start, int end)
{
	int		i;
	int		j;
	char	*r_string;

	r_string = (char *) malloc ((ft_strlen(s1) + 1) - (start + end));
	if (!r_string)
		return (NULL);
	i = start;
	j = 0;
	while (s1[i] && j < (int)ft_strlen(s1) - ((start + end)))
	{
		r_string[j] = s1[i];
		j++;
		i++;
	}
	r_string[j] = '\0';
	return (r_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		s1_index;
	char	*r_string;

	if (!set[0])
		return (ft_strdup(s1));
	s1_index = 0;
	start = ft_skipbegin(s1, set, s1_index);
	end = ft_skipend(s1, set, s1_index, start);
	if (!s1[0] || start + end >= (int)ft_strlen(s1))
	{
		r_string = (char *) malloc (1);
		if (!r_string)
			return (NULL);
		r_string[0] = '\0';
		return (r_string);
	}
	r_string = ft_r_string(s1, start, end);
	if (!r_string)
		return (NULL);
	return (r_string);
}
