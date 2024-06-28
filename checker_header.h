/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:56:14 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 16:55:28 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HEADER_H
# define CHECKER_HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

int		check_num(char **av);
int		check_args(int ac, char **args);
int		valid_args(char **args, int ac);
void	join_split_fill_stack_a(char **av, int ac, t_list	**stack_a);
void	check_empty_args(char **args, int ac);
void	check_double(t_list	*stack_a);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list	*lst, void (*f)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		num(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	out(char *s, int fd);
char	**ft_split(char const *s);
char	**get_next_move(int fd);
int		check_the_move_1(char **move, t_list **stack_a, t_list **stack_b);
void	check_the_move(char **move, t_list **stack_a, t_list **stack_b);
int		ft_strcmp(char *s1, char *s2);
int		is_sorted(t_list	**stack);
void	set_index(t_list **stack_a);
void	ss_stack(t_list **stack_a, t_list **stack_b);
void	r_ab_stack(t_list	**stack_a, t_list	**stack_b);
void	rr_ab_stack(t_list	**stack_a, t_list	**stack_b);
void	s_stack(t_list **stack);
void	rr_stack(t_list	**stack);
void	r_stack(t_list	**stack);
void	pb(t_list	**stack_b, t_list	**stack_a);
void	pa(t_list	**stack_a, t_list	**stack_b);

#endif