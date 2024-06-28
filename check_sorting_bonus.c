/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:12:49 by mthamir           #+#    #+#             */
/*   Updated: 2024/04/30 18:20:31 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header.h"

void	set_index(t_list **stack_a)
{
	t_list	*faster;
	t_list	*slower;
	t_list	*s;

	slower = (*stack_a);
	s = (*stack_a);
	while (slower)
	{
		faster = (*stack_a);
		while (faster)
		{
			if (slower->content < faster->content)
				faster->index++;
			faster = faster->next;
		}
		slower = slower->next;
	}
}

int	is_sorted(t_list	**stack)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = (*stack);
	tmp1 = (*stack)->next;
	while (tmp1 != NULL)
	{
		if (tmp->content < tmp1->content)
		{
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\n' && s2[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
