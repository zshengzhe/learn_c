### 声明的语法

```c
[声明] 声明说明符 声明符;
```

声明说明符:

* 存储类型。auto、static、extern和register

* 类型限定符。const和volatile C99有restrict

* 类型说明符。void、char、short、int、long、float、double、signed和unsigned

### 存储类型

#### 变量的性质

* 存储期限。自动存储期限、静态存储期限

* 作用域。块作用域、文件作用域

* 链接。外部链接、内部链接、无链接

```c
// 静态存储期限 文件作用域 外部链接
int i;

void f(void)
{
    // 自动存储期限 块作用域 无链接
    int j;
}
```

#### auto

#### static

```c
// 静态存储期限 文件作用域 内部链接
static int i;

void f(void)
{
    // 静态存储期限 块作用域 无链接
    static int j;
}
```

#### extern

```c
// 静态存储期限 文件作用域 什么链接?
extern int i;

void f(void)
{
    // 静态存储期限 块作用域 什么链接?
    extern int j;
}
```

#### register

#### 函数的存储类型

extern和static，在函数声明开始处extern说明函数具有外部链接，也就是允许其他文件调用此函数；static说明是内部链接，
也就是说只能在定义函数的文件内部调用此函数。

### 总结

```c
int a;
extern int b;
static int c;

void f(int d, register int e)
{
    auto int g;
    int h;
    static int i;
    extern int j;
    register int k;
}
```

| 名字 | 存储期限 | 作用域 | 链接 |
| ---- | ------ | ----- | --- |
| a    | 静态    | 文件  | 外部 |
| b    | 静态    | 文件  | 外部 |
| c    | 静态    | 文件  | 内部 |
| d    | 自动    | 块    | 无  |
| e    | 自动    | 块    | 无  |
| g    | 自动    | 块    | 无  |
| h    | 自动    | 块    | 无  |
| i    | 静态    | 块    | 无  |
| j    | 静态    | 块    | 外部 |
| k    | 自动    | 块    | 无  |

### 解释复杂声明符

* 始终从内往外读声名符

* 在作选择时，始终使[]和()优先于*

```c
int *ap[10];
```
ap是标识符，由于*在ap前面，且后边跟着[]，[]优先级高，所以ap是指针数组

```c
float *fp(float);
```

fp是标识符，由于*在标识符前面，且后边跟着()，()优先级高，所以fp是返回指针的函数

```c
void (*pf)(int);
```

*pf包含在圆括号内，所以pf一定是指针，但(*pf)后边跟着(int)，所以pf必须是指向函数，且此函数带有int型的实际参数

### 内联函数

```c
inline
```

内联函数 编译器把函数的每一次调用都用函数的机器指令来代替

#### 定义

```c
inline double average(double a, double b)
{
    return (a + b) / 2;
}
```

假设average有外部链接，所以在其他源文件也可以调用average。但是编译器并没有考虑average的定义时外部定义（它是内联定义） ，
所以试图在别的文件中调用average将被认为是错误的。

有两种方法可以避免这一错误

1.

```c
static inline double average(double a, double b)
{
    return (a + b) / 2;
}
```

2.

将average的内联定义放入头文件(average.h)中:

```c
#ifndef AVERAGE_H
#define AVERAGE_H
inline double average(double a, double b)
{
    return (a + b) / 2;
}
#endif
```

接下来，再创建与之匹配的源文件average.c:

```c
#include "average.h"

extern double average(double a, double b);
```