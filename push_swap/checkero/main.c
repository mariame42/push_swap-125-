/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:54:49 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:16:49 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	apply_operation(t_info *i, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(i);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(i);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(i);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(i);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(i);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(i);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(i);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(i);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(i);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(i);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(i);
	else
		handle_error(i, 4);
}

void	checker(t_info *i)
{
	while (1)
	{
		i->line = get_next_line(0);
		if (!i->line)
			break ;
		apply_operation(i, i->line);
		free(i->line);
	}
	if ((i->size_b == 0 && check_if_sorted(i, 'a') == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_info	i;

	if (ac == 1)
		return (0);
	i = initializer();
	i.line = NULL;
	i.b_flag = 1;
	parsing(ac, av, &i);
	checker(&i);
	handle_error(&i, 10);
}
