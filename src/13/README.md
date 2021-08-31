```c
int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
```

### 使用C语言的字符串库

```c
<string.h>
```

#### strcpy

```c
char *strcpy(char *s1, const char *s2);
```

把字符串s2复制给s1（准确的讲，是strcpy函数把s2指向的字符串复制到s1指向的数组中）

#### strlen

```c
size_t strlen(const char *s);
```

#### strcat

```c
char *strcat(char *s1, const char *s2);
```

把字符串s2都内容追加到s1末尾，返回s1

#### strcmp

```c
int strcmp(const char *s1, const char *s2);
```

比较字符串s1和字符串s2，然后根据s1是小于、等于或大于s2

### 字符串惯用法

#### 搜索字符串的结尾

```c
size_t strlen(const char *s)
{
    size_t n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

// 简化
size_t strlen(const char *s)
{
    size_t = 0;
    for (; *s != '\0'; s++)
        n++;
    return n;
}

// 简化
size_t strlen(const char *s)
{
    size_t n = 0;
    for (; *s; s++)
        n++;
    return n;
}

// 简化
size_t strlen(const char *s)
{
    size_t n = 0;
    for (; *s++)
        n++;
    return n;
}

// 使用while语句替换
size_t strlen(const char *s)
{
    size_t n = 0;
    while (*s++)
        n++;
    return n;
}

// 速度快
size_t strlen(const char *s)
{
    const char *p = s;
    while (*s)
        s++;
    return s - p;
}
```

[惯用法] 搜索字符串结尾的空字符
```c
while (*s)
    s++;
```
```c
while (*s++)
    ;
```

#### 复制字符串

```c
char *strcpy(char *s1, const char *s2)
{
    char *p = s1;
    
    while (*p != '\0')
        p++;
    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}

// 简化
char *strcpy(char *s1, const char *s2)
{
    char *p = s1;
    
    while (*p)
        p++;
    while (*p++ = *s2++)
        ;
    return s1;
}
```