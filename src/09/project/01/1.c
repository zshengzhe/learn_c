/**
 * Created by Linus Zhang on 2021/8/2.
 */

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void)
{
    int a[N];
    int i;
    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    selection_sort(a, N);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}

void selection_sort(int a[], int n)
{
    if (n == 0) return;

    int i, temp, largest = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > a[largest])
            largest = i;
    }

    temp = a[largest];
    a[largest] = a[n - 1];
    a[n - 1] = temp;

    selection_sort(a, n - 1);
}