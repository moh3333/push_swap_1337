/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_m.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:28:07 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:20:53 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_M_H
# define PUSH_SWAP_M_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				num_moves;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	struct s_list	*next;
}					t_list;
/* moves functions */
void	r_ab_stack(t_list	**stack_a, t_list	**stack_b, char *to_write);
void	rr_ab_stack(t_list	**stack_a, t_list	**stack_b, char *to_write);
void	final_step(t_list	**stack_a);
void	pa(t_list	**stack_a, t_list	**stack_b);
void	rr_stack(t_list	**stack, char *to_write);
void	r_stack(t_list	**stack, char *to_write);
void	pb(t_list	**stack_b, t_list	**stack_a);
void	s_stack(t_list **stack, char *to_write);

/* sort functions */
void	sort_stack(int size, t_list	**stack_a, t_list	**stack_b);
void	sort_large_stack(t_list	**stack_a, t_list	**stack_b, int size);
void	calcul_moves(t_list	**stack_a, t_list	**stack_b);
void	calcul_moves1(t_list **tmp_a, t_list **stack, t_list **tmp_b, char c);
void	do_the_best_move(t_list	**stack_a, t_list	**stack_b);
void	optimise_moves(t_list	**stack_a, t_list	**stack_b, int pos);
void	continu_and_push(t_list	**stack_a, t_list	**stack_b, t_list *to_cont);

/* side functions */
void	set_pos(t_list	**stack_a);
void	set_index(t_list	**stack_a);
int		get_max(t_list	**stack_a, int size);
int		get_middle(t_list	**stack_a, int size);

/* mini sort functions */
int		is_sorted(t_list	**stack);
void	sort_2(t_list	**stack_a);
void	sort_3(t_list **stack_a);
void	sort_4(t_list	**stack_a, t_list	**stack_b);
void	for_norm(int *a, t_list	**stack_a);
void	sort_5(t_list	**stack_a);

/* parsing functions */
void	join_split_fill_stack_a(char **av, int ac, t_list	**stack_a);
int		valid_args(char **args, int ac);
int		check_num(char **av);
int		check_args(int ac, char **args);
void	check_empty_args(char **args, int ac);
void	check_double(t_list	*stack_a);
int		num(int c);

/* libft functions */
int		ft_atoi(const char *str);
char	**ft_split(char const *s);
char	*ft_strdup(const char	*s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

/* error function */
void	out(char *s, int fd);

/* working with struct functions */
void	ft_lstadd_back(t_list	**lst, t_list	*new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstiter(t_list	*lst, void (*f)(int));
#endif