/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:42:37 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 16:18:57 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_info *s_info)
{
	if (!(s_info->a) || !(s_info->a)->next)
		return ;
	s_info->a = s_info->a->next;
	s_info->op += 1;
	print_op(s_info, "ra\n");
}

void	ft_rb(t_info *s_info)
{
	if (!(s_info->b) || !(s_info->b)->next)
		return ;
	s_info->b = s_info->b->next;
	s_info->op += 1;
	print_op(s_info, "rb\n");
}

void	ft_rr(t_info *s_info)
{
	if ((s_info->a))
		ft_ra(s_info);
	if ((s_info->b))
		ft_rb(s_info);
	s_info->op += 1;
	print_op(s_info, "rr\n");
}
