/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:46:52 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/03 16:37:39 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header.h"

int	check_the_move_1(char **move, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp((*move), "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp((*move), "pb\n"))
		pb(stack_b, stack_a);
	else if (!ft_strcmp((*move), "sa\n"))
		s_stack(stack_a);
	else if (!ft_strcmp((*move), "sb\n"))
		s_stack(stack_b);
	else if (!ft_strcmp((*move), "ss\n"))
		ss_stack(stack_a, stack_b);
	else
		return (1);
	return (0);
}

void	check_the_move(char **move, t_list **stack_a, t_list **stack_b)
{
	if (!check_the_move_1(move, stack_a, stack_b))
		;
	else if (!ft_strcmp((*move), "ra\n"))
		r_stack(stack_a);
	else if (!ft_strcmp((*move), "rb\n"))
		r_stack(stack_b);
	else if (!ft_strcmp((*move), "rra\n"))
		rr_stack(stack_a);
	else if (!ft_strcmp((*move), "rrb\n"))
		rr_stack(stack_b);
	else if (!ft_strcmp((*move), "rrr\n"))
		rr_ab_stack(stack_a, stack_b);
	else if (!ft_strcmp((*move), "rr\n"))
		r_ab_stack(stack_a, stack_b);
	else
	{
		free((void *)(*move));
		out("Error", 2);
	}
	free((void *)(*move));
}

char	**get_next_move(int fd)
{
	static char	*buff;
	int			bytes;
	int			i;
	char		c;

	bytes = 1;
	i = 0;
	buff = malloc (10 * sizeof(char));
	while (bytes > 0 && buff != NULL)
	{
		bytes = read(fd, &c, 1);
		if ((bytes == 0 && i == 0) || bytes == -1)
			return (NULL);
		if (c == '\n' && bytes > 0)
		{
			buff[i] = '\n';
			buff[++i] = 0;
			break ;
		}
		if (i < 10 && bytes > 0)
			buff[i] = c;
		i++;
	}
	return (&buff);
}

static void	check_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	if (tmp_a != NULL && !is_sorted(stack_a) && tmp_b == NULL )
	{
		write(1, "OK\n", 3);
		ft_lstclear(stack_a);
	}
	else
	{
		write(1, "KO\n", 3);
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**move;

	stack_b = NULL;
	if (ac <= 1)
		exit(1);
	check_empty_args(av, ac);
	if (!check_num(av) || check_args(ac, av) == 1 || valid_args(av, ac) == 1)
		out("Error", 2);
	join_split_fill_stack_a(av, ac, &stack_a);
	while (1)
	{
		move = get_next_move(0);
		if (!move)
			break ;
		check_the_move(move, &stack_a, &stack_b);
	}
	check_stacks(&stack_a, &stack_b);
}
