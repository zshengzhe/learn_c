/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>

#define N 10

int main(void)
{

    int arr[N], i;

    printf("Enter %d numbers: ", N);

    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("In reverse order: ");
    for (i = N - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}