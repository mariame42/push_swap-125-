#include <stdio.h>

int ft_cal(int count, int last_pos)
{
    int target_pos = (count * 2 / 3) + last_pos + 1;
    return(target_pos);
}

int main(void)
{
    int count;
    int last_pos;
    printf("count: ");
    scanf("%d", &count);

    printf(" last_pos: ");
    scanf(" %d", &last_pos);

    printf("I am the result: %d\n", ft_cal(count, last_pos));
}