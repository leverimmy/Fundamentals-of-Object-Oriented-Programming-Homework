# 第 2 次作业: 第 1 题

## 模型部分

### 最大公约数的求法

设 $x = qy + p$，其中 $x \ge y, y > p$，现在证明
$$
\mathop{\text{gcd}}(x, y) = \mathop{\text{gcd}}(y, p).
$$
对于 $x$ 与 $y$ 的任意公因数 $r$，有 $r | x$ 且 $r | y$，又因为 $x = qy + p$，所以 $r|p$。因此 $r$ 是 $y$ 和 $p$ 的公因数。由 $r$ 的任意性知 $\mathop{\text{gcd}}(x, y) | \mathop{\text{gcd}}(y, p)$。同理可得 $\mathop{\text{gcd}}(y, p) | \mathop{\text{gcd}}(x, y)$。由于它们互相整除，所以 $\mathop{\text{gcd}}(x, y) = \mathop{\text{gcd}}(y, p)$。

在代码中，我使用递归的方式来求解二者的最大公约数：

```cpp
int CP_GCDLCM::gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
```

其中 `x % y` 即为式中的 $p$。

### 最小公倍数的求法

由唯一分解定理知任意正整数 $x$ 可被唯一表示为质数幂的乘积：
$$
x = \prod_{i = 1}p_i^{\alpha_i},
$$
其中 $p_1 = 2, p_2 = 3, p_3 = 5, \cdots$。

假设需要求 $x = \prod_{i = 1}p_i^{\alpha_i}$ 和 $y = \prod_{i = 1}p_i^{\beta_i}$ 的最小公倍数。则由定义知
$$
\begin{align*}
\mathop{\text{lcm}}(x, y) = \prod_{i = 1}p_i^{\max(\alpha_i, \beta_i)}, \\
\mathop{\text{gcd}}(x, y) = \prod_{i = 1}p_i^{\min(\alpha_i, \beta_i)}.
\end{align*}
$$
注意到 $\alpha_i + \beta_i = \max(\alpha_i, \beta_i) + \min(\alpha_i, \beta_i)$，故
$$
\begin{align*}
xy &= \prod_{i = 1}p_i^{\alpha_i}\cdot \prod_{i = 1}p_i^{\beta_i} \\
& = \prod_{i = 1}p_i^{\alpha_i + \beta_i} \\
& = \prod_{i = 1}p_i^{\max(\alpha_i, \beta_i)} \cdot \prod_{i = 1}p_i^{\min(\alpha_i, \beta_i)} \\
& = \mathop{\text{lcm}}(x, y)\cdot\mathop{\text{gcd}}(x, y),
\end{align*}
$$
因此 $\mathop{\text{lcm}}(x, y) = \dfrac{xy}{\mathop{\text{gcd}}(x, y)}$。

## 如何编译及运行

在 `hw2/prob1/GCDLCM/` 目录下，执行

```
g++ CP_GCDLCM.h CP_GCDLCM.cpp CP_GCDLCMMain.cpp -o CP_GCDLCMMain.exe
```

即可编译得到可执行文件 `CP_GCDLCMMain.exe`。运行该可执行文件，输入

```
10 4
```

即可得到满足作业要求的输出：

```
2
20
请按任意键继续. . . 
```

其中第一行表示输入的两个正整数的最大公约数，第二行表示输入的两个正整数的最小公倍数。

## 验证部分

在本次作业中，我设计了五组数据：

| 测试点编号 |             测试数据             | 最大公约数 |      最小公倍数       |
| :--------: | :------------------------------: | :--------: | :-------------------: |
|     1      |        $x = 1, y = 1001$         |    $1$     |        $1001$         |
|     2      | $x = 1000000007, y = 1000000009$ |    $1$     | $1000000016000000063$ |
|     3      |      $x = 40000, y = 40000$      |  $40000$   |        $40000$        |
|     4      |      $x = 4551, y = 147723$      |   $123$    |       $5465751$       |
|     5      |     $x = 124634, y = 460282$     |   $1234$   |      $46488482$       |

其中覆盖了：

- 两个数中有一个为正整数 $1$ 的特殊情况（测试点 1）；
- 两个数互质的特殊情况（测试点 1，2）；
- 两个数相乘会超出 `int` 表示范围，但在 `long long` 表示范围内的特殊情况（测试点 2）；
- 两个数相同的特殊情况（测试点 3）；
- 两个数分别随机的情况（测试点 4，5）。

我认为，这样的测试数据覆盖了绝大多数可能的极端情况；如果我的程序能在这些数据下通过，则大概率也能通过更普遍的输入数据。