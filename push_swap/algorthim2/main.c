/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:16:11 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:12:43 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	the_big_sort(t_info *i)
{
	push_half_to_b(i);
	while (!(i->size_b == 0 && check_if_sorted(i, 'a') == 0))
	{
		i->cur_flag = i->a->flag;
		if (i->size_b >= 1 && i->size_b <= 5)
			tiny_sort_five_b(i);
		else if (i->size_b > 5)
			push_half_to_a(i);
		else if (i->size_b == 0)
		{
			tiny_sort_five_a(i);
			move_a_to_b(i);
		}
	}
}

void	algorthim_2(t_info *i)
{
	if (check_if_sorted(i, 'a') == 0)
		return ;
	if (i->size_a <= 3)
		tiny_sort(i);
	else if (i->size_a <= 5)
		tiny_sort_five(i);
	else
		the_big_sort(i);
	return ;
}
