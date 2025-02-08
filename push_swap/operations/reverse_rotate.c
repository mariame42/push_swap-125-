/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:38:10 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 16:18:41 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_info *s_info)
{
	if (!(s_info->a) || !(s_info->a)->prev)
		return ;
	s_info->a = s_info->a->prev;
	s_info->op += 1;
	print_op(s_info, "rra\n");
}

void	ft_rrb(t_info *s_info)
{
	if (!(s_info->b) || !(s_info->b)->prev)
		return ;
	s_info->b = s_info->b->prev;
	s_info->op += 1;
	print_op(s_info, "rrb\n");
}

void	ft_rrr(t_info *s_info)
{
	ft_rra(s_info);
	ft_rrb(s_info);
	s_info->op += 1;
	print_op(s_info, "rrr\n");
}
