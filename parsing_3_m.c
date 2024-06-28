/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:58:57 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

int	num(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char	*s1)
{
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	str = (char *) malloc ((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strlen(s1) +ft_strlen(s2) + 1;
	str = (char *) malloc ((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ret = str;
	i = 0;
	while (s1[i] != '\0')
		*str++ = s1[i++];
	*str++ = ' ';
	i = 0;
	while (s2[i] != '\0')
		*str++ = s2[i++];
	*str = '\0';
	return (ret);
}

void	out(char *s, int fd)
{
	if (fd >= 0 && s != NULL)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
		exit(1);
	}
}
