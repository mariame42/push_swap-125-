#include "try.h"
void after_the_first_push(the_stack **stack_a, the_stack **stack_b);
int max_in_chunk(the_stack *stack_b, int chunk_size);
void tiny_sort_from_stack(the_stack **stack_a, the_stack **stack_b, int flag);
int get_max_3_and_push(the_stack **stack_a, the_stack **stack_b, int chunk_size);
void print_res_after(the_stack **stack_a, the_stack **stack_b);


// int get_max_3_and_push(the_stack **stack_a, the_stack **stack_b, int chunk_size)
// {
//     int count_push = 0;
//     int count_rb = 0;
//     the_stack *tmp = *stack_b;
//     // int i = 0;
//     int i = max_in_chunk(*stack_b, chunk_size) - 2;
//     while (count_push != 3)
//     {
//         printf("i----->     %d:      tmp->data    %d \n", i, tmp->data);
//         if (tmp->data < i)
//         {
//             printf("-------------0-------------\n");
//             ft_rb(stack_b);
//             tmp = *stack_b;
//             count_rb++;
//             usleep(500000);
//         }
//         else if (tmp->data >= i)
//         {
//             ft_pa(stack_b, stack_a);
//             tmp = (*stack_b);
//             count_push++;
//         }
//         // print_res_after(stack_a, stack_b);
//         chunk_size--;
//     }
//     int save_count_rb = count_rb;
//     while (count_push > 0)
//     {
//         ft_pb(stack_a ,stack_b);
//         count_push--;
//     }
//     tiny_sort_from_stack(stack_a, stack_b);
//     return (save_count_rb);
// }

void tiny_sort_from_stack(the_stack **stack_a, the_stack **stack_b, int flag)
{
    // int i = 0;
    printf("(*stack_b)->data: %d\n ,   (*stack_b)->next->data:  %d\n , (*stack_b)->next->next->data  %d\n", (*stack_b)->data, (*stack_b)->next->data, (*stack_b)->next->next->data);
    if ((*stack_b)->data > (*stack_b)->next->data && (*stack_b)->data > (*stack_b)->next->next->data)
    {
        printf("if:(*stack_b)->data is the biggest-------------1-------------\n");
        ft_pa(stack_b,stack_a);
        after_the_first_push(stack_a, stack_b);
    }
    else if((*stack_b)->next->data > (*stack_b)->data && (*stack_b)->next->data > (*stack_b)->next->next->data)
    {
        printf("else if:(*stack_b)->next->data is the biggest-------------2-------------\n");
        ft_sb(stack_b);
        ft_pa(stack_b,stack_a);
        after_the_first_push(stack_a, stack_b);
    }
    else if((*stack_b)->next->next->data > (*stack_b)->data && (*stack_b)->next->next->data > (*stack_b)->next->data)
    {
        printf("else:(*stack_b)->next->next->data is the biggest-------------3-------------\n");
        if ((*stack_b)->data < (*stack_b)->next->data)
            ft_sb(stack_b);
        ft_rb(stack_b);
        ft_rb(stack_b);
        ft_pa(stack_b, stack_a);
        ft_rrb(stack_b);
        ft_rrb(stack_b);
        ft_pa(stack_b, stack_a);
        ft_pa(stack_b, stack_a);
    }
    if (flag == 0)
    {
        tiny_sort_from_stack(stack_a, stack_b, 1);

    }
}


void after_the_first_push(the_stack **stack_a, the_stack **stack_b)
{
    if ((*stack_b)->data > (*stack_b)->next->data && (*stack_b)->data > (*stack_b)->next->next->data)
    {
        printf("-------------4-------------\n");
        ft_pa(stack_b,stack_a);
        ft_pa(stack_b,stack_a);
    }
    else
    {
        printf("-------------5-------------\n");
        ft_sb(stack_b);
        ft_pa(stack_b,stack_a);
        ft_pa(stack_b,stack_a);
    }
}

void print_res_after(the_stack **stack_a, the_stack **stack_b)
{
    static int i = 0;
    the_stack *tmp1 = *stack_a;
    the_stack *tmp2 = *stack_b;
    printf("stack_a_a : data\n");
    while (tmp1)
    {
        printf("%d\n",tmp1->data);
        tmp1 = tmp1->next;
    }
    printf("stack_b_b : data\n");
    while (tmp2)
    {
        printf("%d\n", tmp2->data);
        tmp2 = tmp2->next;
    }
    i++;
    printf("-=-=-=--=-=-=-=-%d=-=-=-=-=-=-=-=-=", i);
}

int main(void)
{
    int i = 1;
    /*warning!!!!!!!!! : threr is problem the the numbers*/
    int stack_a[] = {79, 80, 81};
    int stack_b[] = {77, 78, 76, 75, 74, 73, 72, 56, 40, 66, 35, 4, 37, 15, 48, 46, 31, 34, 6, 44, 38, 1, 51, 23, 47, 18, 16, 49, 59, 54, 32, 43, 45, 13, 52, 64, 68, 33, 22, 24, 55, 11, 28, 30, 67, 42, 69, 14, 9, 5, 71, 3, 20, 58, 61, 12, 8, 19, 29, 10, 2, 25, 41, 70, 26, 60, 57, 50, 65, 7, 53, 36, 27, 17, 63, 39, 21, 62};
    // int stack_a[] = {19, 20, 21};
    // int stack_b[] = {9, 15, 10, 18, 3, 14, 13, 4, 5, 7, 11, 1, 2, 8, 6, 12, 16, 17};
    the_stack *stack_a_a = ft_lstnew(stack_a[0]);  
    the_stack *stack_b_b = ft_lstnew(stack_b[0]);
    int size_a = 3;
    int size_b = 77;
    while (i < size_a)
    {
        the_stack *new_node = ft_lstnew(stack_a[i]);
        if (!new_node)
            return (0);
        ft_lstadd_back(&stack_a_a, new_node);
        i++;
    }
    i = 1;
    while (i < size_b)
    {
        the_stack *new_node2 = ft_lstnew(stack_b[i]);
        if (!new_node2)
            return (0);
        ft_lstadd_back(&stack_b_b, new_node2);
        i++;
    }
//     int count_rb = get_max_3_and_push(&stack_a_a, &stack_b_b, 6);
//     while (count_rb > 0)
//     {
//         ft_rrb(&stack_b_b);
//         count_rb--;
//     }
//    if (6 - 3 == 3)
//     {
//         printf("\n----nah----\n");
        tiny_sort_from_stack(&stack_a_a, &stack_b_b, 0);

    // }

    the_stack *tmp1 = stack_a_a;
    the_stack *tmp2 = stack_b_b;
    printf("stack_a_a : data\n");
    while (tmp1)
    {
        printf("%d\n",tmp1->data);
        tmp1 = tmp1->next;
    }
    printf("stack_b_b : data\n");
    int ip = 0;
    while (tmp2 && ip < 9)
    {
        printf("%d\n", tmp2->data);
        tmp2 = tmp2->next;
        ip++;
    }

}

int max_in_chunk(the_stack *stack_b, int chunk_size)
{
	int result;
	
	if (chunk_size == 0)
		return (0);
    the_stack *tmp = stack_b; 
	result = tmp->data;
	while(tmp)
	{
		if (result <  tmp->data)
			result = tmp->data;
        tmp = tmp->next;
	}
	return result;
}