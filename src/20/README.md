### 位运算符

#### 移位运算符

| 符号 | 含义 |
| ---- | ---- |
| <<   | 左位移 |
| >>   | 右位移 |

**可移植性技巧** 为了可移植性，最好对无符号数进行移位运算

#### 按位求反、按位与、按位异或和按位或

| 符号 | 含义     |
| ---- | ------- |
| ~    | 按位求反 |
| &    | 按位与   |
| ^    | 按位异或 |
| |    | 按位或   |

优先级 

最高 `~` 反 \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `&` 与 \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `^` 异或 \
最低 | 或

#### 结构中的位域

```c
struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};
```

**可移植性技巧** 将所有位域声明为`unsigned int`或`signed int`

C语言不允许将&运算符用于位域。`scanf("%d, &fd.day); /*** WRONG ***/`

可以用scanf将输入读入到一个普通的变量中，然后再复制给fd.day

##### 定义依赖机器的类型

```c
typedef unsigned char BYTE;
typedef unsigned short WORD;
```

##### 用联合提供数据的多个视角

```c
union int_date {
    unsigned short i;
    struct file_date fd;
};

void print_date(unsigned short n)
{
    union int_date u;
    
    u.i = n;
    printf("%d/%d/%d\n", u.fd.month, u.fd.day, u.fd.year + 1980);
}
```