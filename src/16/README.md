### 结构变量

#### 结构变量的初始化

```c
struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hane;
} part1 = {528, "Disk drive", 10},
  part2 = {914, "Printer cable", 5};
```

#### 指定初始化

```c
{.number = 528, .name = "Disk drive", .on_hand = 10}
```

#### 复合字面量

```c
print_part((struct part) {528, "Disk drive", 10});
```