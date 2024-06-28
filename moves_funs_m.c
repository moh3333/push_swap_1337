/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_funs_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:27:29 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	s_stack(t_list **stack, char *to_write)
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
		write(1, to_write, ft_strlen(to_write));
		write(1, "\n", 1);
	}
}

void	r_stack(t_list	**stack, char *to_write)
{
	t_list	*tmp;

	tmp = (*stack);
	if (tmp)
	{
		(*stack) = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
		write(1, to_write, ft_strlen(to_write));
		write(1, "\n", 1);
	}
}

void	rr_stack(t_list	**stack, char *to_write)
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
		write(1, to_write, ft_strlen(to_write));
		write(1, "\n", 1);
	}
}

void	r_ab_stack(t_list	**stack_a, t_list	**stack_b, char *to_write)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	if (tmp_a && tmp_b)
	{
		(*stack_a) = (*stack_a)->next;
		tmp_a->next = NULL;
		ft_lstadd_back(stack_a, tmp_a);
		(*stack_b) = (*stack_b)->next;
		tmp_b->next = NULL;
		ft_lstadd_back(stack_b, tmp_b);
		write(1, to_write, ft_strlen(to_write));
		write(1, "\n", 1);
	}
}

void	rr_ab_stack(t_list	**stack_a, t_list	**stack_b, char *to_write)
{
	t_list	*tmp_a;
	t_list	*lst_a;
	t_list	*tmp_b;
	t_list	*lst_b;

	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	if (tmp_a && tmp_b)
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
		write(1, to_write, ft_strlen(to_write));
		write(1, "\n", 1);
	}
}
