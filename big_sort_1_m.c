/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_1_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:37:13 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	continu_and_push(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	while (tmp->ra > 0 || tmp->rb > 0 || tmp->rra > 0 || tmp->rrb > 0)
	{
		if (tmp->ra > 0)
		{
			r_stack(stack_a, "ra");
			tmp->ra--;
		}
		if (tmp->rb > 0)
		{
			r_stack(stack_b, "rb");
			tmp->rb--;
		}
		if (tmp->rra > 0)
		{
			rr_stack(stack_a, "rra");
			tmp->rra--;
		}
		if (tmp->rrb > 0)
		{
			rr_stack(stack_b, "rrb");
			tmp->rrb--;
		}
	}
}

void	optimise_moves(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	tmp_b = (*stack_b);
	tmp_a = (*stack_a);
	while (tmp_b != NULL)
	{
		if (tmp_b->pos == pos)
			break ;
		tmp_b = tmp_b->next;
	}
	while (tmp_b->ra > 0 && tmp_b->rb > 0)
	{
		r_ab_stack(stack_a, stack_b, "rr");
		tmp_b->ra--;
		tmp_b->rb--;
	}
	while (tmp_b->rra > 0 && tmp_b->rrb > 0)
	{
		rr_ab_stack(stack_a, stack_b, "rrr");
		tmp_b->rra--;
		tmp_b->rrb--;
	}
	if (tmp_b->ra > 0 || tmp_b->rb > 0 || tmp_b->rra > 0 || tmp_b->rrb > 0)
		continu_and_push(stack_a, stack_b, tmp_b);
}

void	do_the_best_move(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp_b;
	int		best_one;
	int		pos;

	tmp_b = (*stack_b);
	pos = 0;
	best_one = tmp_b->num_moves;
	while (tmp_b->next != NULL)
	{
		if (tmp_b->next->num_moves < best_one)
		{
			best_one = tmp_b->next->num_moves;
			pos = tmp_b->next->pos;
		}
		tmp_b = tmp_b->next;
	}
	optimise_moves(stack_a, stack_b, pos);
}

void	final_step(t_list	**stack_a)
{
	t_list	*tmp;
	int		nb;

	set_pos(stack_a);
	tmp = (*stack_a);
	nb = 0;
	while (tmp->index != 0)
		tmp = tmp->next;
	if (tmp->index == 0)
		nb = tmp->pos;
	while (nb > 0 && nb < ft_lstsize(*stack_a))
	{
		if (nb <= (ft_lstsize((*stack_a)) / 2))
		{
			r_stack(stack_a, "ra");
			nb--;
		}
		else if (nb > (ft_lstsize((*stack_a)) / 2))
		{
			rr_stack(stack_a, "rra");
			nb++;
		}
	}
}
