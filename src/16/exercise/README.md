### 16.1节

#### 1

合法

#### 2

(a)

```c
struct {
    double real;
    double imaginary;
} c1, c2, c3;
```

(b)

```c
struct {
    double real;
    double imaginary;
} c1 = {0.0, 1.0};, 
  c2 = {1.0, 0.0}, 
  c3;
```

(c)

```c
c1 = c2;
```

(d)

```c
c3.real = c1.real + c2.real;
c3.imaginary = c1.imaginary + c2.imaginary;
```

### 16.2节

#### 3

(a)

```c
typedef struct {
    double real;
    double imaginary;
} complex;
```

(b)

```c
complex c1, c2, c3;
```

(c)

```c
complex make_complex(double real, double imaginary)
{
    complex = {real, imaginary};
}
```

(d)

```c
complex add_complex(complex c1, complex c2)
{
    complex c3 = {c1.real + c2.real, c1.imaginary + c2.imaginary};
    return c3;
}
```

#### 5

```c
struct date {
    int month;
    int day;
    int year
};
```

(a)

```c
int day_of_year(struct date d)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = 0;
    // 计算平闰年
    if (d.month > 2) {
        if (d.year % 100 == 0)
            if (d.year % 400 == 0)
                result++;
        else if (d.year % 4 == 0)
            result++;
    }
    
    for (int i = 0; i < d.month; i++)
        result += days[i];
    return result + d.day;
}
```

(b)

```c
int compare_dates(struct date d1, struct date d2)
{
    if (d1.year > d2.year)
        return 1;
    else if (d1.year == d2.month) {
        int days1 = day_of_year(d1);
        int days2 = day_of_year(d2);
        if (days1 == days2)
            return 0;
        else if (days1 > days2)
            return 1;
        else 
            return -1;
    } else {
        return -1;
    }
        
}
```

#### 6

```c
struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long total_seconds)
{
    struct time t; 
    int one_hour = 60 * 60;
    int one_minute = 60;
    t.hours = total_seconds / one_hour;
    total_seconds %= one_hour;
    t.minutes = total_seconds / one_minute;
    total_seconds %= one_minute;
    t.seconds = total_seconds;
    return t;
}
```

#### 7

```c
struct fraction {
    int numberator;
    int denominator;
};
```

(a)

```c
struct fraction reduce_fraction(struct fraction f)
{
    int temp;
    int n = f.numerator, d = f.denominator;

    while (n % d != 0) {
        temp = d;
        d = n % d;
        n = temp;
    }
    f.numerator /= d;
    f.denominatro /= d;
    return f;
}
```

(b)

```c
struct fraction add(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    return reduce_fraction(f);
}
```

(c)

```c
struct fraction sub(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    return reduce_fraction(f);
}
```

(d)

```c
struct fraction mult(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;
    return reduce_fraction(f);
}
```

(e)

```c
struct fraction div(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;
    return reduce_fraction(f);
}
```