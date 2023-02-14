#include <stdio.h>
void swap(int *y, int *x)
{
    int temp;
    temp = *y;
    *y = *x;
    *x = temp;
}
void minmax(int *arr, int n)
{
    int *a;
    int *b;
    a = &arr[0];
    b = &arr[0];
    for (int i = 0; i < (n - 1); i++)
    {
        if (*a < arr[i + 1])
        {

            a = &arr[i + 1];
        }
    }
    for (int i = 0; i < (n - 1); i++)
    {
        if (*b > arr[i + 1])
        {
            b = &arr[i + 1];
        }
    }
    swap(b, a);
}
int main()
{
    int n = 0;
    printf("Enter the number\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the number in array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    minmax(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}