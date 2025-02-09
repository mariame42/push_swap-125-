typedef struct stack{
    int          data;
    struct stack *next;
    struct stack *per;
    int          pos;
}       the_stack;


the_stack	*ft_lstnew(int content)
{
	the_stack	*new;

	new = malloc((sizeof(the_stack)));
	if (new)
	{
		new->data = content;
		new->next = NULL;
		new->per = NULL;
	}
	return (new);
}


#include <limits.h>

int two_before_max(the_stack *b, int chunk_size)
{
    int max_value = INT_MIN;
    int second_max_value = INT_MIN;
    int third_max_value = INT_MIN;
    the_stack *tmp = b;

    if (chunk_size < 3)  // If there are fewer than 3 elements, return 0 or an appropriate error value
        return (0);

    // Find the maximum, second highest, and third highest values in the list
    while (tmp)
    {
        if (tmp->data > max_value)
        {
            third_max_value = second_max_value;  // Move second_max to third_max
            second_max_value = max_value;  // Move max to second_max
            max_value = tmp->data;  // Update max
        }
        else if (tmp->data > second_max_value && tmp->data != max_value)
        {
            third_max_value = second_max_value;  // Move second_max to third_max
            second_max_value = tmp->data;  // Update second_max
        }
        else if (tmp->data > third_max_value && tmp->data != max_value && tmp->data != second_max_value)
        {
            third_max_value = tmp->data;  // Update third_max
        }
        tmp = tmp->next;
    }

    return third_max_value;  // Return the value two below max
}

// Example use in main
int main(void)
{
    the_stack *node1 = ft_lstnew(7);
    the_stack *node2 = ft_lstnew(8);
    the_stack *node3 = ft_lstnew(4);
    the_stack *node4 = ft_lstnew(5);
    the_stack *node5 = ft_lstnew(1);
    the_stack *node6 = ft_lstnew(6);
    the_stack *node7 = ft_lstnew(3);
    the_stack *node8 = ft_lstnew(2);

    ft_lstadd_back(&node1, node2);
    ft_lstadd_back(&node2, node3);
    ft_lstadd_back(&node3, node4);
    ft_lstadd_back(&node4, node5);
    ft_lstadd_back(&node5, node6);
    ft_lstadd_back(&node6, node7);
    ft_lstadd_back(&node7, node8);

    the_stack *tmp = node1;
    printf("The list before processing:\n");
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }

    printf("\nThe number two below max is: %d\n", two_before_max(node1, 8));
}
