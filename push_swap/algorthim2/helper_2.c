/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:36:45 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:02:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	search_min_a_to_b(t_info *i)
{
	int	min;

	min = i->a->prev->pos + 1;
	if (i->b->pos == min)
	{
		ft_pda(i);
	}
	else if (i->b->next->pos == min)
	{
		ft_sb(i);
		ft_pda(i);
	}
	else if (i->b->prev->pos == min)
	{
		ft_rrb(i);
		ft_pda(i);
	}
	else if (i->a->next->pos == min)
	{
		ft_sa(i);
		i->a->flag = -1;
		ft_ra(i);
	}
}

int	search_min_b_to_a(t_info *i)
{
	int	min;

	min = i->a->prev->pos + 1;
	if (i->b->pos == min)
	{
		ft_pda(i);
		return (1);
	}
	else if (i->a->pos == min)
	{
		i->a->flag = -1;
		ft_ra(i);
	}
	else if (i->a->next->pos == min)
	{
		ft_sa(i);
		i->a->flag = -1;
		ft_ra(i);
	}
	return (0);
}

int	check_if_sorted(t_info *i, char flag)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	if (flag == 'a')
	{
		tmp = i->a;
		size = i->size_a;
	}
	else
	{
		tmp = i->b;
		size = i->size_b;
	}
	while (size > 1)
	{
		if (tmp->pos > tmp->next->pos)
			return (1);
		tmp = tmp->next;
		size--;
	}
	return (0);
}
