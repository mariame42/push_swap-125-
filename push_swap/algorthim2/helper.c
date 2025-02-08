/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:55:38 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:10:41 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_by_flag(t_info *i, char flag)
{
	if (flag == 'a')
	{
		i->tmp.tmp = i->a;
		i->tmp.size = i->size_a;
	}
	else if (flag == 'b')
	{
		i->tmp.tmp = i->b;
		i->tmp.size = i->size_b;
	}
}

void	find_mid(t_info *i, char flag)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	assign_by_flag(i, flag);
	tmp = i->tmp.tmp;
	i->min = tmp->pos;
	i->max = tmp->pos;
	while (j < i->tmp.size)
	{
		if (tmp->pos > i->max)
			i->max = tmp->pos;
		if (tmp->pos < i->min)
			i->min = tmp->pos;
		tmp = tmp->next;
		j++;
	}
	i->mid = (i->max + i->min) / 2;
}

void	find_else(t_info *i, char flag)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	assign_by_flag(i, flag);
	tmp = i->tmp.tmp;
	i->before_max = i->min;
	i->after_min = i->max;
	while (j < i->tmp.size)
	{
		if (tmp->pos < i->max && tmp->pos > i->before_max)
			i->before_max = tmp->pos;
		if (tmp->pos > i->min && tmp->pos < i->after_min)
			i->after_min = tmp->pos;
		tmp = tmp->next;
		j++;
	}
}

int	chunk_size_2(t_info *i, char stack, char flag)
{
	t_stack	*tmp;
	int		count;

	assign_by_flag(i, stack);
	tmp = i->tmp.tmp;
	count = 0;
	while (i->tmp.size > 0)
	{
		if (tmp->flag == flag)
			count++;
		tmp = tmp->next;
		i->tmp.size--;
	}
	return (count);
}
