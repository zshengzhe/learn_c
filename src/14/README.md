### 预处理器工作原理

C程序

↓

预处理器

↓

修改后的C程序

↓

目标代码

```c
#include <stdio.h>

#define FREEZING_PT 32.0f

#define SCALE_FACTOR  （5.0f / 9.0f）

int main(void)
{
    float fahrenheit, celsius;
    
    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);
    
    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
    
    printf("Celsius equivalent is: %.1f\n", celsius);
    
    return 0;
}
```

预处理结束后

```c
空行
空行
从stdio.h中引入的行
空行
空行
空行
空行
int main(void)
{
    float fahrenheit, celsius;

    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32.0f) * (5.0f / 9.0f);

    printf("Celsius equivalent is: %.1f\n", celsius);

    return 0;
}
```

### 预处理指令

* 宏定义 #define
  
* 文件包含 #include
  
* 条件编译 #if、#ifdef、#ifndef、#elif、#else

* 指令都以#开始

* 在指令的符号之间可以插入任意数量的空格或水平制表符

* 指令总是在第一个换行符处结束，除非明确的指明要延续

* 指令可以出现在程序中的任何地方

* 注释可以与指令放在同一行

### 宏定义

#### 简单的宏

```c
#define 标识符 替换列表
```

简单的宏主要用来定义明示常量

使用#define来为常量命名优点

* 程序会更易读
  
* 程序会更易于修改

* 可以帮助避免前后不一致或键盘输入错误

* 可以对C语法做小的修改

* 对类型重命名

* 控制条件编译

#### 带参数的宏

```c
#define 标识符(x1, x2, ..., xn) 替换列表

#define MAX(x, y) ((x) > (y) ? (x) : (y))
```

**优点**

* 程序可能会稍微快些

调用函数通常会有额外的开销--存储上下文信息、复制参数值等，调用宏没有这些运行开销
  
* 宏更通用

宏没有类型，只要预处理后的程序依然是合法的，宏可以接受任何类型的参数

**缺点**

* 编译后的代码通常会变大

* 宏没有类型检查

* 无法用一个指针来指向一个宏

* 宏可能会不止一次的计算它的参数
```c
n = MAX(i++, j);
n = ((i++) > (j) ? (i++) : (j));
```

#### #运算符

`#`运算符将宏的一个参数转换为字符串字面量。它仅允许出现在带参数的宏的替换列表中

```c
#define PRINT_INT(n) printf(#n " = %d\n", n);
```

e.g.

```c
#define STRINGIZE(x) #x

预处理器会将 STRINGIIZE("foo") 替换为 "\"foo\""
```

#### ##运算符

`##`运算符可以将两个几号"粘合"在一起，成为一个记号

```c
#define MK_ID(n) i##n

int MK_ID(1), MK_ID(2);
int i1, i2;
```

```c
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}
```

#### 宏的通用属性

* 宏的替换列表可以包含对其他宏的调用

* 预处理器只会替换完整的记号，而不会替换记号的片段。与处理前期会忽略嵌在标识符、字符常量、字符串字面量\
之中的宏名
  
* 宏定义的作用范围通常到出现这个宏的文件末尾

* 宏不可以被定义两遍，除非新的定义和旧的定义时一样的

* 宏可以使用#undef指令取消定义

#### 预定义宏

| 名字     | 描述                   |
| -------- | --------------------- |
| __LINE__ | 被编译的文件中的行号     |
| __FILE__ | 被编译的文件名          |
| __DATE__ | 编译的格式(格式 mm dd yyyy) |
| __TIME__ | 编译的时间(格式 hh:mm:ss) |
| __STDC__ | 如果编译器符合C标准那么值为1 |

#### C99预定义宏

| 名字             | 描述                                     |
| --------------- | ---------------------------------------- |
| __STDC_HOSTED__ | 如果是托管式实现，值为1；如果是独立式实现，值为0 |
| __STDC_VERSION__ | 支持的C标准版本                           |
| __STDC_IEC_559__ | 如果支持IEC 60559浮点算术运算，值为1        |
| __STDC_IEC_559_COMPLEX__ | 如果支持IEC 60559复数算术运算，值为1 |
| __STDC_ISO_10646__ | 如果wchar_t的值与指定年月的ISO 10646标准相匹配，值为yyyymmL |

#### __func__

每个函数都可以访问，其作用相当于在函数体一开始包含如下声明

```c
static const char __func__[] = "function-name";
```

e.g.

```c
#define FUNCTION_CALLED() printf("%s called\n", __func__);
#define FUNCTION_RETURNS() printf("%s returns\n", __func__);

void f(void)
{
    FUNCTION_CALLED();
    ...
    FUNCTION_RETURNS();
}
```

### 条件编译

#### #if 和 #endif

```c
#if 常量表达式
#endif
```

遇到#if指令时，会计算常量表达式的值，如果是0那么#if和#enbif之间的行会被删除

#### defined

```c
#if defined(DEBUG)
...
#endif
```

#### #ifdef和#ifndef

```c
#ifdef 标识符
等价于
#if defined(标识符)
```

#### #elif和#else

#### 使用条件编译

* 编写在多台机器或多种操作系统之间可以移植的程序

```c
#if defined(WIN32)
...
#elif defined(MAC_OS)
...
#elif defined(LINUX)
...
#endif
```

* 编写可以用于不同的编译器编译的程序

```c
#if __STDC__
函数原型
#else 
老式的函数声明
#endif
```

* 为宏提供默认定义。条件编译可以检测一个宏当前是否已经被定义了

```c
#ifdef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif
```

* 临时屏蔽包含注释的代码

### 其他指令

#### #error

```c
#error 消息
```

#### #line

```c
#line n

#line n "文件"
```

#### #program