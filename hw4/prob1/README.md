# 第 4 次作业: 第 1 题

## 模型部分

假设 $y$ 年 $m$ 月 $d$ 日，加上了 $\Delta d$ 天。则考虑新的日为 $d' = d + \Delta d$​：

- 当 $d' > 0$ 时：
  - 若 $m$ 月的总日数 $d_0 < d'$，则 $m \gets m+1,\; d' \gets d' - d_0$。
    - 若 $m > 12$，则 $y \gets y + 1,\; m \gets m - 12$。

其中 $m$ 和 $d_0$ 的对应规则如下：

| $m$  |    $d_0$     |
| :--: | :----------: |
| $1$  |     $31$     |
| $2$  | $28$ 或 $29$ |
| $3$  |     $31$     |
| $4$  |     $30$     |
| $5$  |     $31$     |
| $6$  |     $30$     |
| $7$  |     $31$     |
| $8$  |     $31$     |
| $9$  |     $30$     |
| $10$ |     $31$     |
| $11$ |     $30$     |
| $12$ |     $31$     |

当 $y$ 为闰年时 $m = 2$ 取 $d_0 = 29$；否则 $d_0$ 取 $28$。

当 $y \equiv 0 \pmod 4 \textrm{ or } (y \not\equiv 0 \pmod{100} \textrm{ and } y \equiv 0 \pmod{400})$ 时 $y$ 为闰年。

> 参考资料：
>
> - [Determination of the day of the week - Wikipedia](https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week)
> - [Leap year - Wikipedia](https://en.wikipedia.org/wiki/Leap_year)

## 如何编译及运行

在 `hw4/prob1/Date/` 目录下，执行

```cmd
g++ CP_Date.h CP_Date.cpp CP_DateMain.cpp -o CP_DateMain.exe
```

即可编译得到可执行文件 `CP_Date.exe`。运行该可执行文件，输入

```
10
```

即可得到满足作业要求的输出：

```
Year: 2024
Month: 3
Day: 29
请按任意键继续. . .
```
