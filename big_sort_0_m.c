/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_0_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:53:25 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	calcul_moves1(t_list **tmp_a, t_list **stack, t_list **tmp_b, char c)
{
	if (c == 'b')
	{
		if ((*tmp_b)->pos <= (ft_lstsize((*stack)) / 2))
			(*tmp_b)->rb = (*tmp_b)->pos;
		else if ((*tmp_b)->pos > (ft_lstsize((*stack)) / 2))
			(*tmp_b)->rrb = ft_lstsize((*stack)) - (*tmp_b)->pos;
	}
	else if (c == 'a')
	{
		if ((*tmp_a)->pos <= (ft_lstsize((*stack)) / 2))
			(*tmp_b)->ra = (*tmp_a)->pos;
		else if ((*tmp_a)->pos > (ft_lstsize((*stack)) / 2))
			(*tmp_b)->rra = ft_lstsize((*stack)) - (*tmp_a)->pos;
	}
}

void	not_found(t_list **tmp_a, int *i, int *check, t_list **stack_a)
{
	(*tmp_a) = (*tmp_a)->next;
	if ((*tmp_a) == NULL && *check == 0)
	{
		(*i)++;
		(*tmp_a) = (*stack_a);
	}
}

void	renitializ_pos(t_list **tmp_b, t_list **stack_a, t_list **stack_b)
{
	(*tmp_b) = (*stack_b);
	set_pos(stack_a);
	set_pos(stack_b);
}

void	calcul_moves(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		i;
	int		check;

	renitializ_pos(&tmp_b, stack_a, stack_b);
	while (tmp_b != NULL)
	{
		check = 0;
		i = 1;
		tmp_a = (*stack_a);
		calcul_moves1(&tmp_a, stack_b, &tmp_b, 'b');
		while (tmp_a != NULL)
		{
			if (tmp_a->index == ((tmp_b->index) + i))
			{
				check = 1;
				calcul_moves1(&tmp_a, stack_a, &tmp_b, 'a');
				break ;
			}
			not_found(&tmp_a, &i, &check, stack_a);
		}
		tmp_b->num_moves = (tmp_b->ra + tmp_b->rb + tmp_b->rra + tmp_b->rrb);
		tmp_b = tmp_b->next;
	}
}
