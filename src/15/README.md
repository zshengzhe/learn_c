### 头文件

```c
#include <file_name>
搜寻系统头文件所在的目录，UNIX系统中，通常把头文件保存在 /usr/include

#include "file_name"
搜寻当前目录，然后搜寻系统头文件所在目录
```

```c
#include 记号

#if defined(IA32)
    #define CPU_FILE "ia32.h"
#elif defined(IA64)
    #define CPU_FILE "ia64.h"
#elif defined(AMD64)
    #define CPU_FILE "amd64.h"
#endif

#include CPU_FILE
```