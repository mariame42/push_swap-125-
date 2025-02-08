/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:59:26 by meid              #+#    #+#             */
/*   Updated: 2024/11/26 09:17:19 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(int array[], int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	swap(&array[i], &array[high]);
	return (i);
}

void	quicksort_recursion(int array[], int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, high);
	}
}

void	quicksort(int array[], int length)
{
	quicksort_recursion(array, 0, length - 1);
}

void	pass_the_array_to_pos(t_info *i)
{
	quicksort(i->tmp.number, i->tmp.count);
}
