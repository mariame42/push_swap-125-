/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:03:24 by meid              #+#    #+#             */
/*   Updated: 2024/11/26 09:09:29 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "gnl/get_next_line.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_split
{
	char			**result;
	int				total_words;
	int				o;
	int				j;
	int				k;
	char			**split_result;
}					t_split;

typedef struct s_stack
{
	int				data;
	int				pos;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
typedef struct s_tmp
{
	int				size;
	t_stack			*tmp;
	int				count;
	int				*number;
	long long		*num;
}					t_tmp;

typedef struct s_info
{
	t_split			*s;
	t_stack			*a;
	t_stack			*b;
	int				max;
	int				mid;
	int				min;
	int				b_flag;
	int				before_max;
	int				after_min;
	int				mid_pos;
	int				size_a;
	int				size_b;
	int				op;
	int				cur_flag;
	int				saved_min;
	char			*line;
	t_tmp			tmp;
}					t_info;

/*=========================helper_functions=========================*/

/*----------------------------parcsing----------------------------*/
void				parsing(int ac, char **av, t_info *i);

void				check_if_empty(int ac, char **av, t_info *info);
void				check_good_for_split(int ac, char **av, t_info *info);
void				check_for_repetition_limits(t_info *i);
/*----------------------------ft_split----------------------------*/
void				ft_split_multi(int ac, char **av, char c, t_info *i);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				free_array(char **array);
void				free_split(char **split);
/*-----------------------list_new------------------------*/
t_stack				*ft_lstnew(int content);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lst_before_last(t_stack *lst);
/*-----------------------sort_for_pos.c------------------------*/
void				pass_the_array_to_pos(t_info *i);
void				chunk_pos_2(t_info *i);
/*-----------------------store_array_list.c------------------------*/
void				store_nums_in_array(char **split, t_info *i);
void				array_to_linked_list(t_info *i);
/*-----------------------operations------------------------*/
void				ft_pa(t_info *s_info);
void				ft_pb(t_info *s_info);
void				ft_rra(t_info *s_info);
void				ft_rrb(t_info *s_info);
void				ft_rrr(t_info *s_info);
void				ft_ra(t_info *s_info);
void				ft_rb(t_info *s_info);
void				ft_rr(t_info *s_info);
void				ft_sa(t_info *s_info);
void				ft_sb(t_info *s_info);
void				ft_ss(t_info *s_info);
void				ft_pda(t_info *i);
void				print_op(t_info *i, char *op_name);
/*-----------------------new_info-----------------------*/
t_info				initializer(void);
void				handle_error(t_info *i, int flag);
/*-----------------------algorthim2-----------------------*/
void				algorthim_2(t_info *i);
void				push_half_to_b(t_info *i);
void				push_half_to_a(t_info *i);
void				move_a_to_b(t_info *i);
void				find_mid(t_info *i, char flag);
void				find_else(t_info *i, char flag);
int					chunk_size_2(t_info *i, char stack, char flag);
int					check_if_sorted(t_info *i, char flag);
int					search_min_b_to_a(t_info *i);
void				search_min_a_to_b(t_info *i);
void				tiny_sort_five_b(t_info *i);
void				tiny_sort_five_a(t_info *i);
void				tiny_sort_five(t_info *s_info);
void				tiny_sort_b(t_info *s_info);
void				tiny_sort(t_info *s_info);

#endif
