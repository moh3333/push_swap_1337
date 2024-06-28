/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthamir <mthamir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:55:34 by mthamir           #+#    #+#             */
/*   Updated: 2024/05/01 15:21:54 by mthamir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_m.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst != NULL && del != NULL)
		del(lst->content);
	free(lst);
}

void	ft_lstiter(t_list	*lst, void (*f)(int))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

t_list	*ft_lstnew(int content)
{
	t_list	*lstnew;

	lstnew = (t_list *) malloc (sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->index = 0;
	lstnew->next = NULL;
	return (lstnew);
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	count = 0;
	if (lst == NULL)
		return (0);
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
