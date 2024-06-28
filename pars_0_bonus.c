/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_0_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:00:19 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 16:48:22 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header.h"

int	check_num(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (num(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int ac, char **args)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (i < ac)
	{
		s = args[i];
		j = 0;
		while (s[j] != 0)
		{
			if (num(s[j]) == 0)
				if (s[j] != '-' && s[j] != '+')
					if (s[j] != ' ')
						return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_args(char **args, int ac)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (i < ac)
	{
		s = args[i];
		j = 0;
		while (s[j])
		{
			if (s[j] == '-' || s[j] == '+')
			{
				if ((s[j + 1]) && (!num(s[j - 1]) && num(s[j + 1])))
					j++;
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	join_split_fill_stack_a(char **av, int ac, t_list	**stack_a)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**ret;

	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		tmp2 = tmp;
		tmp = ft_strjoin(tmp2, av[i++]);
		free(tmp2);
	}
	ret = ft_split(tmp);
	free(tmp);
	i = 0;
	while (ret[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(ret[i])));
		free(ret[i++]);
	}
	free(ret);
	check_double((*stack_a));
}

void	check_empty_args(char **args, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if (args[i][0] == '\0')
			out("Error", 2);
		while (args[i][j])
		{
			if (args[i][j] != ' ' && args[i][j] != '\t')
				break ;
			j++;
			if (args[i][j] == '\0' || args[i][j] == '\t')
				out("Error", 2);
		}
		i++;
	}
}
