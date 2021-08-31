## Format String

| 占位符 | 显示变量 | 说明 |
| ----- | ------- | --- |
| %d    | int     |     |
| %f    | float double | 默认小数点后6位 |
| %.pf  | float double | 强制小数点后p位 |
| %e    | float double | 指数形式的浮点数 p为0 不显示小数点 |
| %m.pX | p       | m=最小字符宽度, 如果显示的数值所需的字符数少于m, 右对齐 |
| %-m.pX | p      | 左对齐 |
| \n    |         | 换行符 |
| \a    |         | 警报   |
| \b    |         | 回退符 |
| \t    |         | 水平制表符 |

## 关键字

| 关键字    |          |          |          |
| -------- | -------- | -------- | -------- |
| auto     | enum     | restrict | unsigned |
| break    | extern   | return   | void     |
| case     | float    | short    | volatile |
| char     | for      | signed   | while    |
| const    | goto     | sizeof   | _Bool    |
| continue | if       | static   | _Complex |
| default  | inline   | struct   | _Imaginary |
| do       | int      | switch   |          |
| double   | long     | typedef  |          |
| else     | register | union    |          |

## 注意

+ float后不要忘了 f

e.g. 2.0f

