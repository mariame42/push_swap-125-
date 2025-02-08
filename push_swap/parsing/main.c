/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:15:29 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 09:11:33 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parsing(int ac, char **av, t_info *i)
{
	if (ac == 1)
		return ;
	check_good_for_split(ac, av, i);
	ft_split_multi(ac, av, ' ', i);
	i->tmp.count = 0;
	while (i->s->result[i->tmp.count])
		i->tmp.count++;
	store_nums_in_array(i->s->result, i);
	free_split(i->s->result);
	check_for_repetition_limits(i);
	array_to_linked_list(i);
	i->b = NULL;
	pass_the_array_to_pos(i);
	chunk_pos_2(i);
	free(i->tmp.number);
	i->size_a = i->tmp.count;
	i->size_b = 0;
	i->op = 0;
}
