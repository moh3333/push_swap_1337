/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:16:15 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

static int	c_arr(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != ' ' && s[i] != '\0')
			count++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	size(const char *s)
{
	int	j;

	j = 0;
	while (s[j] != ' ' && s[j] != '\0')
		j++;
	return (j);
}

static char	*strcp(char *str, const char	*s, int i)
{
	int	c;

	c = 0;
	while (c < i)
	{
		str[c] = s[c];
		c++;
	}
	str[c] = '\0';
	return (str);
}

static char	**spl(const char *s, char **str, int d)
{
	str[d] = (char *) malloc ((size(s) + 1) * sizeof(char));
	if (str[d] == NULL)
	{
		while (d > 0)
		{
			d--;
			free(str[d]);
		}
		free(str);
		return (NULL);
	}
	return (str);
}

char	**ft_split(char const *s)
{
	int		count;
	char	**str;
	int		d;
	int		i;

	d = 0;
	if (s == NULL)
		exit(1);
	count = c_arr(s);
	str = (char **) malloc ((count + 1) * sizeof (char *));
	if (str == NULL)
		exit(1);
	while (d < count)
	{
		while (*s == ' ')
			s++;
		i = size(s);
		if (!spl(s, str, d))
			exit(1);
		strcp(str[d], s, i);
		s = s + i;
		d++;
	}
	str[d] = NULL;
	return (str);
}
