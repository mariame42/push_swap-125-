/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:37:09 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 16:19:18 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_info *s_info)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (s_info->size_a < 2)
	{
		return ;
	}
	tmp1 = (s_info->a);
	tmp2 = s_info->a->next;
	tmp1->prev->next = tmp2;
	tmp2->prev = tmp1->prev;
	tmp1->next = tmp2->next;
	tmp2->next->prev = tmp1;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	s_info->a = tmp2;
	s_info->op += 1;
	print_op(s_info, "sa\n");
}

void	ft_sb(t_info *s_info)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (s_info->size_b < 2)
	{
		return ;
	}
	tmp1 = (s_info->b);
	tmp2 = s_info->b->next;
	tmp1->prev->next = tmp2;
	tmp2->prev = tmp1->prev;
	tmp1->next = tmp2->next;
	tmp2->next->prev = tmp1;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	s_info->b = tmp2;
	s_info->op += 1;
	print_op(s_info, "sb\n");
}

void	ft_ss(t_info *s_info)
{
	if (s_info->size_a < 2)
		ft_sa(s_info);
	if (s_info->size_b < 2)
		ft_sb(s_info);
	s_info->op += 1;
	print_op(s_info, "ss\n");
}
