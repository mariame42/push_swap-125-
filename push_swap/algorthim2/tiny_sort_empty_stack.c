/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_empty_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:21:31 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 09:02:49 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_down_a_sorted(t_info *i, int flag)
{
	if (i->a->pos > i->a->next->pos && i->a->flag == i->a->next->flag)
		ft_sa(i);
	while (i->size_b != 0)
	{
		if (i->a->pos > i->b->pos || i->a->flag == -1)
			ft_pda(i);
		else
		{
			i->a->flag = -1;
			ft_ra(i);
		}
	}
	while (i->a->flag == flag && flag != -1 && i->a->pos
		+ 1 == i->a->prev->pos)
	{
		i->a->flag = -1;
		ft_ra(i);
	}
}

void	tiny_sort_five_b(t_info *i)
{
	int	min;

	min = i->a->prev->pos + 1;
	while (i->size_b > 3)
	{
		if (i->b->pos == min)
		{
			ft_pda(i);
			min++;
		}
		else
			ft_pa(i);
	}
	tiny_sort_b(i);
	put_down_a_sorted(i, i->a->flag);
}

void	tiny_sort_five_a(t_info *i)
{
	int	min;
	int	counter;

	min = i->a->prev->pos + 1;
	counter = chunk_size_2(i, 'a', i->a->flag);
	if (counter <= 5)
	{
		while (counter >= 3)
		{
			if (i->a->pos == min)
			{
				i->a->flag = -1;
				ft_ra(i);
				min++;
			}
			else
				ft_pb(i);
			counter--;
		}
		tiny_sort_b(i);
		put_down_a_sorted(i, i->a->flag);
	}
}
