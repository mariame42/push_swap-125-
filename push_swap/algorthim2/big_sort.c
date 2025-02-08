/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:54:09 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:12:39 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_half_to_a(t_info *i)
{
	int	size_b;

	find_mid(i, 'b');
	size_b = i->size_b;
	while (size_b-- > 0)
	{
		if (search_min_b_to_a(i))
			continue ;
		if (i->b->pos > i->mid)
		{
			i->b->flag++;
			ft_pa(i);
		}
		else
		{
			i->b->flag++;
			ft_rb(i);
		}
	}
}

void	move_a_to_b(t_info *i)
{
	int	flag;
	int	min;

	flag = i->a->flag;
	while (i->a->flag == flag && flag != -1)
	{
		min = i->a->prev->pos + 1;
		if (i->size_b > 1)
			search_min_a_to_b(i);
		if (i->a->pos == min)
		{
			i->a->flag = -1;
			ft_ra(i);
		}
		else
			ft_pb(i);
	}
}

void	push_half_to_b(t_info *i)
{
	t_stack	*tmp;
	int		len;

	len = i->size_a;
	find_mid(i, 'a');
	while (len-- > 0 && (i->size_b < i->max - i->mid + 1))
	{
		tmp = i->a;
		if (tmp->pos <= i->mid)
		{
			ft_pb(i);
			if (i->b->pos == i->min)
			{
				i->b->flag = -1;
				ft_rb(i);
			}
		}
		else
			ft_ra(i);
	}
	while (i->b->prev->flag == -1)
		ft_rrb(i);
	while (i->b->flag == -1)
		ft_pda(i);
}
