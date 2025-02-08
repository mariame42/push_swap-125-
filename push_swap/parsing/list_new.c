/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:57:38 by meid              #+#    #+#             */
/*   Updated: 2024/11/26 09:08:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc((sizeof(t_stack)));
	if (new)
	{
		new->data = content;
		new->next = NULL;
		new->prev = NULL;
		new->flag = 0;
	}
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		return ;
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lst_before_last(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
