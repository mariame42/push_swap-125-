// #include "../push_swap.h"
// #include <stdio.h>
// #include <stdlib.h>

// void swap(int *x, int *y);
// void quicksort(int array[], int length);
// void quicksort_recursion(int array[], int low, int high);
// int partition(int array[], int low, int high);
// void pass_the_array_to_pos(int *numbers, int count);
// void chunk_pos_2(the_stack **stack_a, int count, int *numbers);

// void swap(int *x, int *y)
// {
// 	int temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

// void quicksort(int array[], int length)
// {
//     quicksort_recursion(array, 0, length - 1);
// }

// void quicksort_recursion(int array[], int low, int high)
// {
// 	if (low < high)
//   	{
//         int pivot_index = partition(array, low, high);
//     	quicksort_recursion(array, low, pivot_index - 1);
//     	quicksort_recursion(array, pivot_index + 1, high);
// 	}
// }

// int partition(int array[], int low, int high)
// {
//     int pivot_value = array[high];
  
//     int i = low; 
  
//     for (int j = low; j < high; j++)
//   	{
//         if (array[j] < pivot_value)
//     	{
//      		swap(&array[i], &array[j]);
//     		i++;
//     	}
// 	}
//     swap(&array[i], &array[high]);
//     return (i);
// }

// void pass_the_array_to_pos(int *numbers, int count)
// {
//     quicksort(numbers, count);
// }

// void chunk_pos_2(the_stack **stack_a, int count, int *numbers)
// {
//     int i = 0;
//     the_stack *tmp = *stack_a;

//     while (tmp)
//     {
//         while (i < count)
//         {
//             if (tmp->data == numbers[i])
//             {
//                 tmp->pos = i;
//                 break;
//             }
//             i++;
//         }
//         tmp = tmp->next;
//     }
//     the_stack *tmp1 = *stack_a;
//     while (tmp1)
//     {
//         printf("content -> %d ,  pos ->  %d  \n", tmp1->data, tmp1->pos);
//         tmp1 = tmp1->next;
//     } 
// }

// int main()
// {
//     int *number = {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27}
//     pass_the_array_to_pos(number, count);
//     chunk_pos_2(&stack_a, count, number);
// }

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 

// 12 14 10 2 19 4 6 21 26 7 15 16 5 3 8 20 9 27 24 23 17 11 22 1 13 25 18