#include <stdio.h>
#include <stdlib.h>

char *ft_is_it_sort(char *str)
{
    char *s = "   it i sorted    \n";
    char *s2 = "  it is not : (  \n";
    int i = 0, j = 0;
    int *arr = malloc(sizeof(int) * 22);

    while (str[i])
    {
        if (str[i] != ' ')
        {
            arr[j] = atoi(&str[i]);
            j++;
            while (str[i] && str[i] != ' ')
                i++;
        }
        else
            i++;
    }
    int y = 0;
    while (y < 22)
    {
        if (arr[y] < arr[y + 1])
            y++;
        else
            return (s2);
    }

    return (s);
}

int main(void)
{
    char * str = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22";
    printf("%s", ft_is_it_sort(str));
}