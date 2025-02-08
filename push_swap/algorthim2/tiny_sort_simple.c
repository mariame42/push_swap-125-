/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_semple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:17:40 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 07:40:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_info *s_info)
{
	int	count;

	count = 0;
	count = s_info->size_a;
	if (count == 3)
	{
		if (s_info->a->pos > s_info->a->next->pos
			&& s_info->a->pos > s_info->a->next->next->pos)
			ft_ra(s_info);
		else if (s_info->a->next->pos > s_info->a->pos
			&& s_info->a->next->pos > s_info->a->next->next->pos)
			ft_rra(s_info);
	}
	if (s_info->a->pos > s_info->a->next->pos)
		ft_sa(s_info);
}

void	tiny_sort_b(t_info *s_info)
{
	int	count;

	count = 0;
	count = s_info->size_b;
	if (count == 3)
	{
		if (s_info->b->pos > s_info->b->next->pos
			&& s_info->b->pos > s_info->b->next->next->pos)
			ft_rb(s_info);
		else if (s_info->b->next->pos > s_info->b->pos
			&& s_info->b->next->pos > s_info->b->next->next->pos)
			ft_rrb(s_info);
	}
	if (s_info->b->pos > s_info->b->next->pos)
		ft_sb(s_info);
}

void	tiny_sort_five(t_info *s_info)
{
	int	how_many_push_back;
	int	size_in_start;

	how_many_push_back = 0;
	find_mid(s_info, 'a');
	find_else(s_info, 'a');
	size_in_start = s_info->size_a;
	while (s_info->size_a > 3)
	{
		if (s_info->a->pos == s_info->min || (size_in_start == 5
				&& s_info->a->pos == s_info->after_min))
		{
			ft_pb(s_info);
			how_many_push_back++;
		}
		else
			ft_ra(s_info);
	}
	if (size_in_start == 5 && s_info->b->pos < s_info->b->next->pos)
		ft_sb(s_info);
	tiny_sort(s_info);
	while (how_many_push_back-- != 0)
		ft_pa(s_info);
}
