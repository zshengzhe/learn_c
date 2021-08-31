### 18.1

#### 1

(a) 

存储类型 `静态`

类型限定符 `无`

类型说明符 `char **`

声名符 `lookup(int level)`

初始化式 `无`

(b)

存储类型 `无`

类型限定符 `volatile`

类型说明符 `unsigned long`

声名符 `io_flags`

初始化式 `无`

(c)

存储类型 `外部`

类型限定符 `无`

类型说明符 `char *[]`

声名符 `file_name, path`

初始化式 `无`

(d)

存储类型 `静态`

类型限定符 `const`

类型说明符 `char []`

声名符 `token_buf`

初始化式 `""`

### 18.2

#### 2

(a) `extern`

(b) `static`

(c) `extern static`

#### 3

```c
// 静态 文件 外部
extern float a;
// 自动 块 无
void f(register double b)
{
    // 静态 块 无
    static int c;
    // 自动 块 无
    auto char d;
}
```

#### 4

```c
f(10) == 0

f(f(f(f(f(f(10)))))) == 50
```

#### 5

(a) 不对，可以具有块作用域

(b) 不对，可以有外部链接

(c) 对

(d) 对

#### 6

```c
void print_error(const char *message)
{
    static int n = 1;
    printf("Error %d: %s\n", n++, message);
}
```

### 18.4

#### 8

(a)

```c
char (*x[10])(int);
```

x是一个函数指针数组，元素是参数为int返回值是char的函数

(b)

```c
int (*x(int))[5];
```

x是一个参数为int函数，返回值是一个函数指针

(c)

```c
float *(*x(void))(int);
```

x是一个参数为void类型的函数，返回一个函数指针，函数的入参是int返回值是float*

(d)

```c
void (*x(int, void (*y)(int)))(int);
```

x是一个函数，参数是int和一个函数指针，此函数指针入参为int无返回值，返回一个入参为int无返回值的函数指针

#### 10

(a)

```c
char *(*p)(char *p)
```

(b)

```c
void (*f(struct t *p, long n))(void)
```

(c)

```c
void (*a[4])(void) = {insert, search, update, print};
```

(d)

```c
struct t (*b[10])(int, int)
```

#### 12

(a)

```c
int (*f(float (*)(long), char *))(double);
```

f是一个函数，第一个参数是一个参数为long无返回值的函数，第二个参数是字符指针，返回一个函数指针，该函数指针的参数为double返回值为int

(b)

```c
float (*fp)(long);
char *cp;

int (*result)(double);

result = f(fp, cp);
```