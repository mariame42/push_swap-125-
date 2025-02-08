/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:36:20 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 16:18:02 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_info *s_info)
{
	t_stack	*tmp;

	if (s_info->size_b == 0)
		return ;
	tmp = (s_info->b);
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	(s_info->b) = (s_info->b)->next;
	if (s_info->size_a > 0)
	{
		tmp->next = (s_info->a);
		tmp->prev = (s_info->a)->prev;
		(s_info->a)->prev->next = tmp;
		(s_info->a)->prev = tmp;
	}
	else
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	(s_info->a) = tmp;
	s_info->size_a += 1;
	s_info->size_b -= 1;
	s_info->op += 1;
	print_op(s_info, "pa\n");
}

void	ft_pb(t_info *s_info)
{
	t_stack	*tmp;

	if (s_info->size_a == 0)
		return ;
	tmp = (s_info->a);
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	(s_info->a) = (s_info->a)->next;
	if (s_info->size_b > 0)
	{
		tmp->next = (s_info->b);
		tmp->prev = (s_info->b)->prev;
		(s_info->b)->prev->next = tmp;
		(s_info->b)->prev = tmp;
	}
	else
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	(s_info->b) = tmp;
	s_info->size_b += 1;
	s_info->size_a -= 1;
	s_info->op += 1;
	print_op(s_info, "pb\n");
}
