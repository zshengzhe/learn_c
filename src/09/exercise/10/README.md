```c
// a 数组中的最大元素
int max(int n, int a[n])
{
    int max = a[0];
    if (n < 2)
        return max;
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    
    return max;
}

// a 数组中所有元素的平均值

int avarage(int n, int a[n])
{
    int i, sum = 0; 
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    
    return sum / n;
}

// a 数组中正数元素的数量
int positives (int a[], int n)
{
    int total, i = 0;
    while (i++ < n) {
        if (a[n] > 0)
            total++;
    }

    return total;
}
```