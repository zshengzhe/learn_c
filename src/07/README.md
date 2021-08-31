### 基本类型

64位机的整数类型

| 类型                | 最小值  | 最大值  |
| ------------------ | ------ | ------ |
| short int          | 0x1000 | 0x7FFF | 
| unsigned short int | 0x0000 | 0xFFFF |
| int                | 0x1000 0000 | 0x7FFF FFFF |
| unsigned int       | 0x0000 0000 | 0xFFFF FFFF |
| long int           | 0x1000 0000 0000 0000 | 0x7FFF FFFF FFFF FFFF |
| unsigned long int  | 0x0000 0000 0000 0000 | 0xFFFF FFFF FFFF FFFF |

### 转义序列

| 名称   | 转义序列 |
| ------ | ------- |
| 警报符  | \a      |
| 回退符  | \b      |
| 换页符  | \f      |
| 换行符  | \n      |
| 回车符  | \r      |
| 水平制表符 | \t    |
| 垂直制表符 | \v    |
| 反斜杠  | \\      |
| 问号   | \?      |
| 单引号 | \'       |
| 双引号 | \"       |

### 类型转换

* **任一操作数的类型是浮点类型的情况**

float -> double -> long double

* **两个操作数的类型都不是浮点类型的情况**

int -> unsigned int -> long int -> unsigned long int

### C99中的隐式转换

(1) long long int、unsigned long long int

(2) long int、unsigned long int

(3) int、unsigned int

(4) short int、unsigned short int

(5) char、signed char、unsigned char

(6) _Bool

































