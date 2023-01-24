#include <stdio.h>
#include <stdlib.h>
int power(int a, int b)
{
    int res = 1;
    while (1)
    {
        if (b % 2 == 1)
        {
            res = res * a;
        }
        b = b / 2;
        if (b == 0)
        {
            break;
        }
        a = a * a;
    }
    return res;
}
int main()
{
    int v, max_variables, i = 0;
    printf("Enter number of variables\n");
    scanf("%d", &v);
    max_variables = power(2, v);
    int *dec_inputs;
    dec_inputs = (int *)malloc(max_variables * sizeof(int));
    printf("Click enter after entering last number\n");
    printf("Enter SOP form of expression: ");
    while (1)
    {
        scanf("%d", &dec_inputs[i]);
        if (dec_inputs[i] > (max_variables - 1))
        {
            printf("invald input!\n");
            return 0;
        }
        if ((getchar()) == '\n')
        {
            break;
        }
        i++;
    }
    dec_inputs = (int *)realloc(dec_inputs, (i + 1) * sizeof(int));
    int *initial_binary_numbers;
    initial_binary_numbers = (int *)malloc((i + 1) * v * sizeof(int));
    for (int j = 0; j < v * (i + 1); j = j + v)
    {
        int x = v - 1 + j, dec;
        static int k = 0;
        dec = dec_inputs[k];
        while (x >= j)
        {
            if (dec > 0)
            {
                if (dec % 2 == 0)
                {
                    initial_binary_numbers[x] = 0;
                }
                else
                {
                    initial_binary_numbers[x] = 1;
                }
            }
            else
            {
                initial_binary_numbers[x] = 0;
            }
            dec = dec / 2;
            x--;
        }
        k++;
    }
    int **array_of_tables;
    array_of_tables=(int **)malloc((v-1)*sizeof(int *));
    for(int x=0;x<v-1;x++){
        array_of_tables[x]=(int *)malloc(sizeof(int));
    }

    
    free(dec_inputs);
    free(array_of_tables);
    free(initial_binary_numbers);
    return 0;
}