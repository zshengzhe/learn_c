### 14.3节

#### 1

(a) 

```c
#define CUBE(x) ((x) * (x) * (x))
```

(b)

```c
#define MOD4(x) ((x) / 4)
```

(c)

```c
#define SMALL_PRODUCT(x, y) ((x) * (y) < 100 ? 1 : 0)
```

#### 2

```c
#define NELEMS(a) (sizeof(a) / sizeof(a[0]))
```

#### 3

(a) 4

(b) 4

(c)

```c
#define DOUBLE(x) (2 * (x))
```

#### 4

(a)

```c
#define AVG(x, y) (((x) + (y)) / 2)
```

(b)

```c
#define AREA(x, y) ((x) * (y))
```

#### 6

(a)

```c
#define DISP(f, x) (printf((#f) "(%g) = %g\n", (x), (f(x))));
```

(b)

```c
#define DISP(f, x, y) (printf((#f) "(%g, %g) = %g\n", (x), (y), (f((x), (y)))));
```

#### 8

