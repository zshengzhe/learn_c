### 流

流标识任意输入的源或任意输出的目的地

#### 文件指针

C程序对流的访问是通过文件指针实现的。此指针类型为`FILE *`

```c
FILE *fp1, *fp2;
```

#### 标准流和重定向

<stdio.h>提供了三个标准流。这3个标准流可以直接使用

| 文件指针 | 流      | 默认的含义 |
| ------- | ------- | -------- |
| stdin   | 标准输入 | 键盘      |
| stdout  | 标准输出 | 屏幕      |
| stderr  | 标准错误 | 屏幕      |

`< 输入重定向`

```c
demo < in.dat
```

`> 输出重定向`

```c
demo > out.dat
```

### 文件操作

#### 打开文件

```c
FILE *fopen(const char * restrict filename, const char * restrict mode);
```

C99: restrict是C99关键字，表明filename和mode所指向的字符串的内存单元不共享

e.g.

```c
FILE *fp = fopen("in.dat", "r");
```

当文件无法打开时，fopen函数返回空指针

#### 模式

**文本文件的模式字符串**

| 字符串 | 含义                          |
| ----- | ---------------------------- |
| "r"   | 打开文件用于读                 |
| "w"   | 打开文件用于写（文件不需要存在）  |
| "a"   | 打开文件用于追加（文件不需要存在） |
| "r+"  | 打开文件用于读和写，从文件头开始  |
| "w+"  | 打开文件用于读和写（如果文件存在就截去）|
| "a+"  | 打开文件用于读和写（如果文件存在就追加）|

**二进制文件的模式字符串**

| 字符串         | 含义                          |
| ------------- | ---------------------------- |
| "rb"          | 打开文件用于读                 |
| "wb"          | 打开文件用于写（文件不需要存在）  |
| "ab"          | 打开文件用于追加（文件不需要存在） |
| "r+b" 或 "rb+" | 打开文件用于读和写，从文件头开始  |
| "w+b" 或 "wb+" | 打开文件用于读和写（如果文件存在就截去）|
| "a+b" 或 "ab+" | 打开文件用于读和写（如果文件存在就追加）|

#### 关闭文件

```c
int fclose(FILE *stream);
```

如果成功关闭了文件，fclose函数会返回零；否则，它将返回错误代码EOF

e.g.

```c
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.dat"

int main(void)
{
    FILE *fp = fopen(FILE_NAME, "r");
    
    if (fp == NULL) {
        printf("Can't open %s\n", FILE_NAME);
        exit(EXIT_FAUILURE);
    }
    
    ...
    
    fclose(fp);
    
    return 0;
}
```

#### 为打开的流附加文件

```c
FILE *freopen(const char * restrict filename, 
            const char * restrict mode, 
            FILE * restrict stream);
```

#### 临时文件

```c
FILE *tmpfile(void);
char *tmpnam(char *s);
```

#### 文件缓冲

```c
int fflush(FILE *stream);
void setbuf(FILE * restrict stream, char * restrict buf);
int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);
```

#### 其他文件操作

```c
int remove(const char *filename);
int rename(const char *old, const char *new);
```

### 格式化的输入/输出

#### ...printf函数

```c
int fprintf(FILE * restrict stream, const char * restrict format, ...);
int printf(const char * restrict format, ...);
```

...printf函数的转换说明由字符%和跟随其后的最多5个不同的选项构成

```c
%#012.5Lg
```

|     | 标志 | 最小字段宽度 | 精度 | 长度修饰符 | 转换说明符 |
| --- | ---- | ---------- | --- | --------- | -------- |
| %   | #0   | 12         | .5  | L         | g        |

+ **标志** 标志-导致在字段内做对齐，而其他标志则会影响数的显示形式

| 标志 | 含义                                                                                             |
| --- | ----------------------------------------------------------------------------------------------- |
| -   | 在字段内左对齐（默认右对齐）                                                                         |
| +   | 有符号转换得到的数总是以`+`或`-`开头（通常，只有负数前面附上减号）                                        |
| 空格 | 有符号转换得到的非负数前加空格（`+`标志优先于空格标志）                                                 |
| #   | 以0开头的八进制数，以`0x`或`0X`开头的十六进制非零数。浮点数始终有小数点。不能删除由`g`或`G`转换输出的数的尾部零 |
| 0   | 用前导零在数的字段宽度内进行填充。如果转换是d、i、o、u、x或X，而且指定了精度，那么可以忽略标志0（-标志优先于0标志） |

+ **最小字段宽度**

+ **精度**

+ **长度修饰符**

+ **转换说明符**

| 转换修饰符 | 含义     |
| -------- | ------- |
| d、i     | 把int类型值转换为十进制形式 |
| o、u、x、X | 把无符号整数转换为八进制(0)、十进制(u)或十六进制(x、X)形式 |
| f、F     | 把double类型值转换为十进制形式，并且把小数点防止在正确的位置上。默认精度小数点后6位 |
| e、E     | 把double类型值转换为科学计数法形式 |
| g、G     | 把double类型值转换为`f`形式或`e`形式 |
| a、A     |  |
| c        | 显示无符号字符的int类型值 |
| s        | 写出由实参指向的字符 |
| p        | 把`void *`类型值转换为可打印形式 |
| n        | 相应的实参必须是指向int型对象的指针 |
| %        | 写字符% |

#### ...scanf函数

```c
int fscanf(FILE * restrict stream, const char * restrict format, ...);
int scanf(const char * restrict format, ...);
```

如果发生输入失败（即没有输入字符可以读）或者匹配失败（即输入字符和格式串不匹配），scanf函数会提前返回

**转换说明符**

| 转换说明符 | 含义     |
| -------- | ------- |
| d        | 匹配十进制整数，假使相应实参是`int *`类型 |
| i        | 匹配整数，假使相应实参是`int *`类型 |
| o        | 匹配八进制整数，假使相应实参是`unsigned int *`类型 |
| u        | 匹配十进制整数，假使相应实参是`unsigned int *`类型 |
| x、X     | 匹配十六进制整数，假使相应实参是`unsigned int *`类型 |
| a、A、e、E、f、F、g、G | 匹配浮点数，假使相应实参是`float *`类型 |
| c        | 匹配n个字符，这里n是最大字段宽度 |
| s        | 匹配一串非空字符，然后在末尾添加空字符，假使相应的实参是指向字符数组的指针 |
| p        | 匹配指针值，假使相应实参是`void *`类型 |
| n        |  |
| %        | 匹配字符% |

### 字符的输入/输出

#### 输出函数

```c
int fputc(int c, FILE *stream);
int putc(int c, FILE *stream);
int putchar(int c);
```

#### 输入函数

```c
int fgetc(FILE *stream);
int getc(FILE *stream);
int getchar(void);
int ungetc(int c, FILE *stream);
```

### 行的输入/输出

#### 输出函数

```c
int fputs(const char * restrict s, FILE * restrict stream);
int puts(const char *s);
```
#### 输入函数

```c
char *fgets(char * restrict s, int n, FILE * restrict stream);
char *gets(char *s);
```

### 块的输入/输出

```c
size_t fread(void * restrict ptr, 
             size_t size, size_t nmemb,
             FILE * restrict stream);
size_t fwrite(const void * restrict ptr, 
              size_t size, size_t nmemb,
              FILE * restrict stream);
```
