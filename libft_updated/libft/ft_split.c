/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:04:35 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/23 16:45:32 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mt(char const *s, char c)
{
	int		i;
	int		malloc_size;

	if (!s || !s[0])
		return (0);
	i = 0;
	malloc_size = 1;
	while (s[i])
	{
		if (s[i] && (!i && s[0] == c))
			while (s[i] && s[i] == c)
				i++;
		if (s[i] && s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			malloc_size++;
		}
		else if (s[i])
			i++;
	}
	if (s[i - 1] == c)
		return (malloc_size - 1);
	return (malloc_size);
}

static int	ft_skip_begin(char const *s, char c, int i)
{
	if (s[i] && i == 0)
	{
		if (s[i] == c)
			while (s[i] && s[i] == c)
				i++;
	}
	return (i);
}

static char	*ft_amc(char const *s, int i, int n)
{
	int		r_string_index;
	char	*r_string;

	r_string_index = 0;
	r_string = (char *) malloc (i - n);
	if (!r_string)
		return (NULL);
	while (i > ++n)
		r_string[r_string_index++] = s[n];
	r_string[r_string_index] = '\0';
	return (r_string);
}

static char	*ft_malloc_string(char const *s, char c, int n)
{
	int		i;

	i = -1;
	if (s[0] == c)
		n++;
	while (s[++i] && n != 0)
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			n--;
		}
	}
	if (i)
		i--;
	n = ft_skip_begin(s, c, i) - 1;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] && !i)
		while (s[i])
			i++;
	return (ft_amc(s, i, n));
}

char	**ft_split(const char *s, char c)
{
	char	**r_string;
	int		i;

	r_string = (char **) malloc ((ft_mt(s, c) + 1) * sizeof(char **));
	if (!r_string)
		return (NULL);
	i = 0;
	while (i < ft_mt(s, c))
	{
		r_string[i] = ft_malloc_string(s, c, i);
		if (!r_string[i])
		{
			while (i >= 0)
			{
				free(r_string[i]);
				i--;
			}
			free(r_string);
			return (NULL);
		}
		i++;
	}
	r_string[i] = NULL;
	return (r_string);
}
