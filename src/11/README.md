### * 和 ++ 运算符的组合

| 表达式          | 含义                            |
| -------------- | ------------------------------ |
| *p++ 或 *(p++) | 自增前表达式的值是*p，以后再自增p   |
| (*p)++         | 自增前表达式的值是*p，以后再自增*p |
| *++p或*(++p)   | 先自增p，自增后表达式的值是*p      |
| ++*p或++(*p)   | 先自增*p，自增后表达式的值是*p     |

### 多维度数组循环

```c
int a[NUM_ROWS][NUM_COLS];
int row, col;
for(row = 0; row < NUM_ROWS; row++)
    for (col = 0; col < NUM_COLS; col++)
        a[row][col] = 0;
    
int *p;
for (p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++)
    *p = 0;
```

#### 处理多维数组的行

```c
int a[NUM_ROWS][NUM_COLS], *p, i;
for (p = &a[i]; p < a[i] + NUM_COLS; p++)
    *p = 0;
```

#### 处理多维数组的列

```c
int a[NUM_ROWS][NUM_COLS], (*p)[NUM_COLS], i;
for (p = &a[0]; p < &a[NUM_ROWS]; p++)
    (*p)[i] = 0;
```

```c
int *p[10]; // 指针数组，每个元素都是指针
int (*p)[10]; // 数组指针，p是指向数组的指针
```