### 变长数组形式参数

```c
int sum_array(int a[], int n);

int sum_array(int n, int a[n]);

int sum_array(int n, inta[*]);

int sum_two_dimensional_array(int m, int n, int a[m][n]) {
    int i, j, sum = 0;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum += a[i][j];
        }
    }
    
    return sum;
}
```

### 复合字面量

```c
int b[] = {2, 3, 4, 6, 1};
int total = sum_array(b, 5);

total = sum_array((int []) {2, 3, 4, 6, 1}, 5);
```

### exit函数

```c
#include <stdlib.h>

exit(EXIT_SUCCESS);
exit(EXIT_FAILURE);
```