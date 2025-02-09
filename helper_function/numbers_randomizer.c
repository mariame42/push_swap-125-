#include "try.h"

void	ft_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;    
    *b = tmp;
}
void random_array_of_numbers(int *array, int size)
{
    int i = 0;
    int j;
    srand(5);
    while(i < size)
    {
        j = rand() % size;
        ft_swap(&array[i], &array[j]);
        i++;
    }
}

int main(void)
{
    int size;
    char flag;
    printf("how many numbers do you want?  ");
    scanf("%d", &size);

    printf("do you need ',' put y ot n?  ");
    scanf(" %c", &flag);
    int *tab = malloc(sizeof(int) * size);
    int j = 0;
    while (j < size)
    {
        tab[j] = 1 + j;
        j++;
    }
    
    for (int l = 0; l < size; l++)
        printf("%d ", tab[l]);
    printf("\n\n");
    random_array_of_numbers(tab, size);
    if (flag == 'y' || flag == 'Y')
    {
        for (int i = 0; i < size; i++)
            printf("%d, ", tab[i]);
    }
    else if (flag == 'n' || flag == 'N')
    {
        for (int i = 0; i < size; i++)
            printf("%d ", tab[i]);
    }
    else
        printf("put n or y only !!!!");
}
    // int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
