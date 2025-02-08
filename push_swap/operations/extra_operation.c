/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:48:42 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 19:58:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strleno(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

void	ft_pda(t_info *i)
{
	i->b->flag = -1;
	ft_pa(i);
	ft_ra(i);
}

void	print_op(t_info *i, char *op_name)
{
	if (i->b_flag == 0)
		write(1, op_name, ft_strleno(op_name));
}
