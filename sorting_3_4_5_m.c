/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3_4_5_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:04 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	sort_3(t_list **stack_a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*stack_a)->content;
	a2 = (*stack_a)->next->content;
	a3 = (*stack_a)->next->next->content;
	if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		rr_stack(stack_a, "rra");
		s_stack(stack_a, "sa");
	}
	else if (a3 < a2 && a3 < a1 && a2 > a1)
		rr_stack(stack_a, "rra");
	else if ((a1 > a2 && a1 > a3 && a2 > a1) || (a1 > a2 && a2 < a3 && a1 < a3))
		s_stack(stack_a, "sa");
	else if (a1 > a2 && a2 > a3 && a1 > a3)
	{
		s_stack(stack_a, "sa");
		rr_stack(stack_a, "rra");
	}
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		r_stack(stack_a, "ra");
}

void	sort_4(t_list	**stack_a, t_list	**stack_b)
{
	int	a1;
	int	a2;
	int	a3;
	int	a4;

	a1 = (*stack_a)->content;
	a2 = (*stack_a)->next->content;
	a3 = (*stack_a)->next->next->content;
	a4 = (*stack_a)->next->next->next->content;
	if (a2 < a3 && a2 < a4 && a2 < a1)
		s_stack(stack_a, "sa");
	else if (a3 < a1 && a3 < a2 && a3 < a4)
	{
		rr_stack(stack_a, "rra");
		rr_stack(stack_a, "rra");
	}
	else if (a4 < a1 && a4 < a2 && a4 < a3)
		rr_stack(stack_a, "rra");
	if (!is_sorted(stack_a) && (*stack_b) == NULL)
		return ;
	pb(stack_b, stack_a);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	for_norm(int *a, t_list	**stack_a)
{
	if (a[1] < a[0] && a[1] < a[2] && a[1] < a[3] && a[1] < a[4])
		s_stack(stack_a, "sa");
	else if (a[2] < a[0] && a[2] < a[1] && a[2] < a[3] && a[2] < a[4])
	{
		r_stack(stack_a, "ra");
		r_stack(stack_a, "ra");
	}
	else if (a[3] < a[0] && a[3] < a[1] && a[3] < a[2] && a[3] < a[4])
	{
		rr_stack(stack_a, "rra");
		rr_stack(stack_a, "rra");
	}
	else if (a[4] < a[0] && a[4] < a[1] && a[4] < a[2] && a[4] < a[3])
		rr_stack(stack_a, "rra");
}

void	sort_5(t_list	**stack_a)
{
	int		a[5];
	t_list	*tmp;
	t_list	*stack_b;

	stack_b = NULL;
	tmp = (*stack_a);
	a[0] = tmp->content;
	a[1] = tmp->next->content;
	a[2] = tmp->next->next->content;
	a[3] = tmp->next->next->next->content;
	a[4] = tmp->next->next->next->next->content;
	for_norm(a, stack_a);
	if (!is_sorted(stack_a) && stack_b == NULL)
		return ;
	pb(&stack_b, stack_a);
	sort_4(stack_a, &stack_b);
	pa(stack_a, &stack_b);
}
