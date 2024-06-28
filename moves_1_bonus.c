/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:17:45 by mthamir           #+#    #+#             */
/*   Updated: 2024/04/28 02:58:22 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header.h"

void	pa(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	if (tmp)
	{
		(*stack_b) = (*stack_b)->next;
		tmp->next = NULL;
		if (ft_lstsize(*stack_b) >= 0)
			ft_lstadd_front(stack_a, tmp);
	}
}

void	pb(t_list	**stack_b, t_list	**stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	if (tmp)
	{
		(*stack_a) = (*stack_a)->next;
		tmp->next = NULL;
		if (ft_lstsize((*stack_a)) >= 0)
			ft_lstadd_front(stack_b, tmp);
	}
}

void	ss_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*lst_a;
	t_list	*tmp_b;
	t_list	*lst_b;

	if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
	{
		tmp_a = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		tmp_a->next = NULL;
		lst_a = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		lst_a->next = NULL;
		ft_lstadd_front(stack_a, tmp_a);
		ft_lstadd_front(stack_a, lst_a);
		tmp_b = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		tmp_b->next = NULL;
		lst_b = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		lst_b->next = NULL;
		ft_lstadd_front(stack_a, tmp_b);
		ft_lstadd_front(stack_a, lst_b);
	}
}
