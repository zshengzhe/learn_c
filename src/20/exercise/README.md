### 20.1

#### 1

(a)

```c
unsigned short i = 8; // 0x0000 1000
unsigned short j = 9; // 0x0000 1001

printf("%d", i >> 1 + j >> 1); // 0
```

(b)

```c
i = 1; // 0x0000 0001
printf("%d", i & ~i); // 0
```

(c)

```c
i = 2; // 0x0000 0010 ~i= 0x1
j = 1; // 0x0000 0001
k = 0;
printf("%d", ~i & j ^ k); // 1
```

(d)

```c
i = 7; // 0x0000 0111
j = 8; // 0x0000 1000
k = 9; // 0x0000 1001
printf("%d", i ^ j & k); // 0x0000 1111 = 15
```

#### 2

```c
i ^ (i & 1 << 4) 
```

#### 3

swap

#### 4

```c
#define MK_COLOR(r, g, b) ((long) (b) << 16 | (g) << 8 | (r))
```

#### 5

```c
#define GET_RED(l) (l & 0xff)
#define GET_GREEN(l) ((l >> 8) & 0xff)
#define GET_BLUE(l) ((l >> 16) & 0xff)
```

#### 6

```c
unsigned short swap_bytes(unsigned short i)
{
    return (i << 8) | (i >> 8);
}
```

#### 7

```c
unsigned int rotate_left(unsigned int i, int n)
{
    return (i << n) | (i >> (8 * sizeof(int) - n));
}

unsigned int rotate_right(unsigned int i, int n)
{
    return (i << (8 * sizeof(int) - n)) | (i >> n);
}
```

#### 8

(a) 

`~(~0 << n)` returns a number with its rightmost `n` bits set to 1 and all other
bits set to 0. For example, `~(~0 << 4)` would return 0000 1111.

(b) 

The function returns a range of `n` bits starting from position `m` in `i`.

#### 9

(a)

```c
int count_ones(unsigned char ch)
{
    int count = 0;
    do {
        if (ch & 0x1)
            count++;
        ch >>= 1;
    } while (ch != 0);

    return count;
}
```

(b)

```c
int count_ones(unsigned char ch)
{
    if (ch == 0)
        return 0;
    return count_ones(ch >> 1) + (ch & 0x1 ? 1 : 0);
}
```

#### 11

```c
if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
    printf("No modifier keys pressed\n");
```

#### 12

```c
unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
    return (high_byte << 8) + low_byte;
}
```

### 20.2

#### 14

```c
struct float_value {
    unsigned int fraction: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
};
```