/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_0_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:16:58 by mthamir           #+#    #+#             */
/*   Updated: 2024/04/28 02:58:28 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header.h"

void	s_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		tmp->next = NULL;
		lst = (*stack);
		(*stack) = (*stack)->next;
		lst->next = NULL;
		ft_lstadd_front(stack, tmp);
		ft_lstadd_front(stack, lst);
	}
}

void	r_stack(t_list	**stack)
{
	t_list	*tmp;

	tmp = (*stack);
	if (tmp)
	{
		(*stack) = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	rr_stack(t_list	**stack)
{
	t_list	*tmp;
	t_list	*lst;

	tmp = (*stack);
	if (tmp)
	{
		tmp = ft_lstlast(tmp);
		lst = (*stack);
		while (lst->next->next != NULL)
			lst = lst->next;
		ft_lstadd_front(stack, tmp);
		lst->next = NULL;
	}
}

void	r_ab_stack(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	if (ft_lstsize(tmp_a) && ft_lstsize(tmp_b))
	{
		(*stack_a) = (*stack_a)->next;
		tmp_a->next = NULL;
		ft_lstadd_back(stack_a, tmp_a);
		(*stack_b) = (*stack_b)->next;
		tmp_b->next = NULL;
		ft_lstadd_back(stack_b, tmp_b);
	}
}

void	rr_ab_stack(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*tmp_a;
	t_list	*lst_a;
	t_list	*tmp_b;
	t_list	*lst_b;

	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	if (ft_lstsize(tmp_a) > 1 && ft_lstsize(tmp_b) > 1)
	{
		tmp_a = ft_lstlast(tmp_a);
		lst_a = (*stack_a);
		while (lst_a->next->next != NULL)
			lst_a = lst_a->next;
		ft_lstadd_front(stack_a, tmp_a);
		lst_a->next = NULL;
		tmp_b = ft_lstlast(tmp_b);
		lst_b = (*stack_b);
		while (lst_b->next->next != NULL)
			lst_b = lst_b->next;
		ft_lstadd_front(stack_b, tmp_b);
		lst_b->next = NULL;
	}
}
