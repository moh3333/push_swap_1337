/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:27:48 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:05 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	sort_large_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int		r[2];
	t_list	*tmp;

	r[0] = get_max(stack_a, size);
	r[1] = get_middle(stack_a, size);
	while (size > 5)
	{
		tmp = (*stack_a);
		if (tmp->content == r[0])
			r_stack(stack_a, "ra");
		pb(stack_b, stack_a);
		if ((*stack_b)->content > r[1])
			r_stack(stack_b, "rb");
		size--;
	}
	sort_5(stack_a);
	while ((*stack_b) != NULL)
	{
		calcul_moves(stack_a, stack_b);
		do_the_best_move(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	final_step(stack_a);
}

void	sort_2(t_list	**stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		s_stack(stack_a, "sa");
}

void	sort_stack(int size, t_list **stack_a, t_list **stack_b)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a);
	else if (size > 5)
		sort_large_stack(stack_a, stack_b, size);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac <= 1)
		exit(1);
	check_empty_args(av, ac);
	if (!check_num(av) || check_args(ac, av) == 1 || valid_args(av, ac) == 1)
		out("Error", 2);
	join_split_fill_stack_a(av, ac, &stack_a);
	if (!is_sorted(&stack_a))
		return (ft_lstclear(&stack_a), 0);
	set_index(&stack_a);
	set_pos(&stack_a);
	sort_stack(ft_lstsize(stack_a), &stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
