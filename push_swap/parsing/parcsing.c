/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:07:31 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:17:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_if_empty(int ac, char **av, t_info *info)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] == ' ')
			i++;
		if (av[j][i] == '\0')
			handle_error(info, 0);
		j++;
	}
}

void	check_good_for_split(int ac, char **av, t_info *info)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] == '-' || av[j][i] == '+') && (av[j][i + 1] > '0'
					&& av[j][i + 1] <= '9') && ((i == 0) || av[j][i - 1] == ' '
					|| av[j][i - 1] == '\0'))
				i++;
			else if ((av[j][i] >= '0' && av[j][i] <= '9') || (av[j][i] == ' ')
					|| (av[j][i] == '\0'))
				i++;
			else
				handle_error(info, 0);
		}
		j++;
	}
	check_if_empty(ac, av, info);
}

void	check_for_repetition_limits(t_info *i)
{
	int	k;
	int	j;

	k = 0;
	while (k < i->tmp.count)
	{
		j = k + 1;
		while (j < i->tmp.count)
		{
			if (i->tmp.number[k] == i->tmp.number[j])
				handle_error(i, 3);
			j++;
		}
		k++;
	}
}

void	chunk_pos_2(t_info *i)
{
	int		k;
	int		j;
	t_stack	*tmp;

	k = 0;
	j = 0;
	tmp = i->a;
	while (j < i->tmp.count)
	{
		while (k < i->tmp.count)
		{
			if (tmp->data == i->tmp.number[k])
			{
				tmp->pos = k;
				break ;
			}
			k++;
		}
		k = 0;
		tmp = tmp->next;
		j++;
	}
}
