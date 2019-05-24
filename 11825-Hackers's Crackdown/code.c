#include <stdio.h>
#include <stdlib.h>

const int start = 1234;
const int end = 98765;

void to_char_array(char *s, int num, int den)
{
    if (num / 10000)
    {
        sprintf(s, "%d", num);
    }
    else
    {
        *s = '0';
        sprintf(s + 1, "%d", num);
    }

    if (den / 10000)
    {
        sprintf(s + 5, "%d", den);
    }
    else
    {
        *(s + 5) = '0';
        sprintf(s + 6, "%d", den);
    }
}

int has_duplicate(int numerator, int denominator)
{
    char *char_arr = malloc(10);
    to_char_array(char_arr, numerator, denominator);

    int i, j;
    int duplicate = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (!(*(char_arr + i) ^ *(char_arr + j)))
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
        {
            break;
        }
    }

    free(char_arr);
    return duplicate;
}

void process(int n)
{
    int numerator, denominator, count = 0;
    for (denominator = start; denominator <= end; denominator++)
    {
        numerator = denominator * n;
        if (numerator > end)
        {
            break;
        }

        if (!has_duplicate(numerator, denominator))
        {
            count++;
            if (numerator / 10000)
                printf("%d / ", numerator);
            else
                printf("0%d / ", numerator);

            if (denominator / 10000)
                printf("%d = %d", denominator, n);
            else
                printf("0%d = %d", denominator, n);

            printf("\n");
        }
    }

    if (!count)
        printf("There are no solutions for %d.\n", n);
}

int main()
{
    int n, i = 1;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        if (i)
            i = 0;
        else
            printf("\n");
        process(n);
    }
    return 0;
}