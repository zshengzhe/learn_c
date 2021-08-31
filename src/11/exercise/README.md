### 12.1节

#### 1

(a) *(p + 3) == 14

(b) *(q - 3) == 34

(c) q - p == 4

(d) p < q == true

(e) *p < *q == false

#### 2

The statement is illegal because pointers cannot be added together. The statement can be fixed by subtracting the
pointers, which is legal:

```c
middle = (high - low) / 2 + low;
```

### 12.2节

#### 3

```c
{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
```

#### 4

```c
int contents[STACK_SIZE];
int *top;

void make_empty(void)
{
    top = &contents[0];
}

bool is_empty(void)
{
    return top == &contents[0];
}

bool is_full(void)
{
    return top == &contents[STACK_SIZE];
}
```

### 12.3节

#### 5

(a) illegal

(b) true

(c) true

(d) true

#### 6

```c
int sum_array(const int a[], int n)
{
    int *p, sum;
    
    sum = 0;
    for (p = &a[0]; p < &a[n]; p++)
        sum += *p;
    return sum;
}
```

#### 7

```c
bool search(const int a[], int n, int key)
{
    int *p;
    for (p = &a[0]; p < &a[n]; p++) {
        if (key == *p)
            return true;
    }
    return false;
}
```

#### 8

```c
void store_zeros(int a[], int n)
{
    int *p;
    for (p = &a[0]; p < &a[n]; p++)
        *p = 0;
}
```

### 12.4节

#### 14

```c
bool has32 = search(temperatures, 7 * 24, 32);
```

#### 15

```c
int temperatures[7][24];

int *p = temperatures[i];
while (p < temperatures[i + 1])
    printf("%d ", *p++);
```