/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:45 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

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

void	set_pos(t_list	**stack_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		tmp->pos = i;
		tmp->num_moves = 0;
		tmp->ra = 0;
		tmp->rb = 0;
		tmp->rra = 0;
		tmp->rrb = 0;
		tmp = tmp->next;
		i++;
	}
}

int	get_max(t_list **stack_a, int size)
{
	t_list	*tmp;
	int		max;

	tmp = (*stack_a);
	max = 0;
	while (tmp != NULL)
	{
		if (tmp->index == (size - 1))
		{
			max = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	get_middle(t_list	**stack_a, int size)
{
	t_list	*tmp;
	int		middle;

	tmp = (*stack_a);
	middle = 0;
	while (tmp != NULL)
	{
		if (tmp->index == ((size - 1) / 2))
		{
			middle = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	return (middle);
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
