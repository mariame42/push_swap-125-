/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:51:57 by meid              #+#    #+#             */
/*   Updated: 2024/11/25 20:17:10 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*cpy_word(char const *s, char c, char *str)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, i);
	return (str);
}

size_t	my_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**allocation(char **array, char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = my_count(s, c);
	array = ((malloc(sizeof(char *) * (count + 1))));
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		array[i] = cpy_word(s, c, array[i]);
		if (!array[i])
		{
			free_array(array);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = NULL;
	if (s == NULL)
	{
		return (NULL);
	}
	array = allocation(array, s, c);
	return (array);
}

void	ft_split_multi(int ac, char **av, char c, t_info *i)
{
	i->s->k = 0;
	while (i->s->o < ac)
	{
		i->s->total_words += my_count(av[i->s->o], c);
		i->s->o++;
	}
	i->s->result = malloc(sizeof(char *) * (i->s->total_words + 1));
	if (!i->s->result)
		handle_error(i, 1);
	i->s->k = 0;
	i->s->o = 1;
	while (i->s->o < ac)
	{
		i->s->split_result = ft_split(av[i->s->o], c);
		if (!i->s->split_result)
			handle_error(i, 1);
		i->s->j = 0;
		while (i->s->split_result[i->s->j])
			i->s->result[i->s->k++] = i->s->split_result[i->s->j++];
		free(i->s->split_result);
		i->s->o++;
	}
	i->s->result[i->s->k] = NULL;
}
