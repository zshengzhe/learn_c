### 动态存储分配

#### 内存分配函数

```c
#include <stdlib.h>
```

* malloc函数--分配内存块，但是不对内存块进行初始化

* calloc函数--分配内存块，并且对内存块清零

* realloc函数--调整先前分配的内存块大小

malloc函数不需要对分配的内存块进行清零，所以它比calloc函数更高效

### 动态分配字符串

```c
#include <stdlib.h>
#include <string.h>
char *concat(const char *s1, const char *s2)
{
    char *p = malloc(strlen(s1) + strlen(s2) + 1);
    if (p == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p, s1);
    strcat(p, s2);
    return p;
}
```

### 17.8 & 17.9