/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>

int main(void)
{
    int i, n;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("In reverse order:");
    for (i = n - 1; i >= 0; i--)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}