/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:06:09 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:16:21 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_info	initializer(void)
{
	t_info	i;

	i.a = NULL;
	i.b = NULL;
	i.max = 0;
	i.mid = 0;
	i.min = 0;
	i.op = 0;
	i.size_a = 0;
	i.size_b = 0;
	i.tmp.count = 0;
	i.tmp.size = 0;
	i.tmp.tmp = NULL;
	i.mid_pos = 0;
	i.cur_flag = 0;
	i.b_flag = 0;
	i.s = malloc(sizeof(*(i.s)));
	if (!i.s)
		free(i.s);
	i.s->result = 0;
	i.s->total_words = 0;
	i.s->o = 1;
	i.s->j = 0;
	i.s->split_result = NULL;
	return (i);
}

void	ft_lstclear(t_stack **lst, int size)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!lst)
		return ;
	current = *lst;
	while (size > 0)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		size--;
	}
	*lst = NULL;
}

void	handle_error(t_info *i, int flag)
{
	if (flag == 1 || flag == 2)
		free_split(i->s->result);
	free(i->s);
	if (flag == 2)
		free(i->tmp.num);
	if (flag == 2 || flag == 3)
		free(i->tmp.number);
	if (flag >= 3)
	{
		ft_lstclear(&i->a, i->size_a);
		ft_lstclear(&i->b, i->size_b);
	}
	if (flag == 4)
		free(i->line);
	if (flag == 10)
		exit(0);
	write(2, "Error\n", 6);
	exit(1);
}
