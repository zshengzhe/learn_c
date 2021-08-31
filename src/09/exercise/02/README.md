```c
#include <stdbool.h>

bool check(int x, int y, int n)
{
    if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1)
        return true;
    return false;
}
```