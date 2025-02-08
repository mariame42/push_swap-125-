/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_array_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:59:10 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:17:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] && str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (sign == -1 && res >= 9223372036854775808LLU)
		return (0);
	if (res >= __LONG_LONG_MAX__ && sign != -1)
		return (-1);
	return (sign * (int)res);
}

static long long	ft_atoi_2(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] && str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (sign == -1 && res >= 9223372036854775808LLU)
		return (0);
	if (res >= __LONG_LONG_MAX__ && sign != -1)
		return (-1);
	return (sign * res);
}

void	store_nums_in_array(char **split, t_info *i)
{
	int	j;

	i->tmp.number = malloc(i->tmp.count * sizeof(int));
	i->tmp.num = malloc(i->tmp.count * sizeof(long long int));
	if (i->tmp.number == NULL)
		return ;
	j = 0;
	while (j < i->tmp.count)
	{
		i->tmp.number[j] = ft_atoi(split[j]);
		i->tmp.num[j] = ft_atoi_2(split[j]);
		if (i->tmp.num[j] > INT_MAX || i->tmp.num[j] < INT_MIN)
			handle_error(i, 2);
		j++;
	}
	free(i->tmp.num);
}

void	lstadd_back_doubly(t_info *i, t_stack *node)
{
	t_stack	*start;

	if (node == NULL)
		handle_error(i, 3);
	start = i->a;
	if (start)
	{
		if (start->prev)
		{
			start->prev->next = node;
			node->prev = start->prev;
			node->next = start;
			start->prev = node;
		}
		else
		{
			start->prev = node;
			start->next = node;
			node->prev = start;
			node->next = start;
		}
	}
	else
		i->a = node;
}

void	array_to_linked_list(t_info *i)
{
	int	j;

	j = 0;
	while (j < i->tmp.count)
	{
		lstadd_back_doubly(i, ft_lstnew(i->tmp.number[j]));
		j++;
	}
}
