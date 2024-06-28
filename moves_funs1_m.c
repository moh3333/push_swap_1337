/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_funs1_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:26:10 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	pa(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	if (tmp)
	{
		(*stack_b) = (*stack_b)->next;
		tmp->next = NULL;
		if (ft_lstsize(*stack_b) >= 0)
		{
			ft_lstadd_front(stack_a, tmp);
			write(1, "pa\n", 3);
		}
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
		{
			ft_lstadd_front(stack_b, tmp);
			write(1, "pb\n", 3);
		}
	}
}
