#include "try.h"
                 //list     //how man parts   //list_size      /flage
int how_many_a(the_stack *stack_a, int part, int size, char flag)
{
    the_stack *tmp = stack_a;
    int target_pos = size / part;
    // if (size % part != 0)
    //     target_pos +=1;

    while (tmp)
    {
        int count = 0;
        the_stack *tmp1 = stack_a;
        while (tmp1)
        {
            if ((flag == 'S' && tmp->data > tmp1->data) || 
                (flag == 'B' && tmp->data < tmp1->data))
            {
                count++;
            }
            tmp1 = tmp1->next;
        }
        if (count == target_pos)
        {
            return tmp->data;
        }
        tmp = tmp->next;
    }
    return 0;
}


int main(void)
{
    int size = 18;
    int *tab = malloc(sizeof(int) * size);
    int j = 0;
    while (j < size)
    {
        tab[j] = 1 + j;
        j++;
    }
    random_array_of_numbers(tab, size);
    the_stack *node1 = ft_lstnew(tab[0]);
    int i = 1;
    while (i < size)
    {
        the_stack *new_node = ft_lstnew(tab[i]);
        if (!new_node)
            return (0);
        ft_lstadd_back(&node1, new_node);
        i++;
    }
    the_stack *tmp = node1;
    printf("the list before rotate:  \n");
    printf("%p\n", node1);
    printf("%p\n", node1->next);
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    printf("||||%d||||\n", how_many_a(node1, 3, size, 'B'));
}

// 1 2 3 4 5 6     7 8 9  10 11 12                13     14 15 16 17 18 19 20



