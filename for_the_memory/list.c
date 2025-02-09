#include "try.h"

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

void	ft_lstadd_back(the_stack **lst, the_stack *new)
{
	the_stack	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->per = last;
}

the_stack	*ft_lstlast(the_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

the_stack	*ft_lst_before_last(the_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int 	ft_mid(the_stack *stack_a, int size)
{
	the_stack *tmp = stack_a;
	int mid = size/2;
	while (mid != 0)
	{
		tmp = tmp->next; 
		mid--;
	}
	int res = tmp->data;
	return (res);
}

int	ft_list_size(the_stack *stack)
{
    int counter = 0;
    while (stack)
    {
        counter++;
        stack = stack->next;
    }
    return (counter);
}