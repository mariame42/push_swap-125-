#ifndef TRY_H
# define TRY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


# include <stdio.h> // printf (will use our printf future so rmove that leter)
# include <unistd.h> // read
# include <stdlib.h> // malloc , free , exit
# include <limits.h> // INT_MAX , INT_MIN

typedef struct stack{
    int          data;
    struct stack *next;
    struct stack *per;
    int          pos;
}       the_stack;

void random_array_of_numbers(int *array, int size);
void	ft_swap(int *a, int *b);

the_stack	*ft_lstlast(the_stack *lst);
the_stack	*ft_lstnew(int content);
void	ft_lstadd_back(the_stack **lst, the_stack *new);
int how_many_a(the_stack *stack_a, int part, int size, char flag);

/*stack_operations.c*/

void ft_sa(the_stack **stack_a);
void ft_sb(the_stack **stack_b);
void ft_ra(the_stack **stack_a);
void ft_rb(the_stack **stack_a);
void ft_pa(the_stack **stach_b, the_stack **stach_a);
void ft_pb(the_stack **stach_a, the_stack **stach_b);
void ft_ss(the_stack **stack_a, the_stack **stack_b);
void ft_rr(the_stack **stack_a, the_stack **stack_b);
void ft_rra(the_stack **stack_a);
void ft_rrb(the_stack **stack_b);
void ft_rrr(the_stack **stack_a, the_stack **stack_b);

/*list_new.c*/

the_stack	*ft_lst_before_last(the_stack *lst);
the_stack	*ft_lstlast(the_stack *lst);
void	ft_lstadd_back(the_stack **lst, the_stack *new);
the_stack	*ft_lstnew(int content);
int 	ft_mid(the_stack *stack_a, int size);
int	ft_list_size(the_stack *stack);



int *chunk_maker(the_stack **stack_a, the_stack **stack_b, int count, int chunk_b_counter);
int two_thirds(the_stack *stack_a, int count, int last_pos);

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);
void pass_the_array_to_pos(int *numbers, int count);
void chunk_pos_2(the_stack **stack_a, int count, int *numbers);
int two_thirds(the_stack *stack_a, int count, int last_pos);
the_stack *array_to_linked_list(int *numbers,int count);
int ft_chunk_b_counter(int count);



int two_before_max(the_stack *b, int chunk_size);
#endif