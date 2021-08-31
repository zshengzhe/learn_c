### `<assert.h>` 诊断

```c
void assert(scalar expression);
```

如果参数的值不为0，assert什么也不做；如果参数的值为0，assert会向stderr写一条消息，并调用abort函数终止程序

### `<errno.h>` 错误

```c
errno = 0;
y = sqrt(x);
if (errno != 0) {
    fprintf(stderr, "sqrt error: program terminated.\n");
    exit(EXIT_FAILURE);
}
```

#### perror函数和strerror函数

### `<signal.h>` 信号处理

#### 信号宏

| 宏名     | 含义                          |
| ------- | ----------------------------- |
| SIGABRT | 异常终止（可能由于调用abort导致） |
| SIGFPE  | 在算术运算中发生错误             |
| SIGILL  | 无效指令                       |
| SIGINT  | 中断                          | 
| SIGSEGV | 无效存储访问                   |
| SIGTERM | 终止请求                       |