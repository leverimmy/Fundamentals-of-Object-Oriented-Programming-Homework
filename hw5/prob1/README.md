# 第 5 次作业: 第 1 题

## 模型部分

设 $a = x + y\;\mathrm{i}\,,b = z + w\;\mathrm{i}$，则有

$$
\begin{align*}
a + b & = (x + z) + (y + w)\;\mathrm{i}, \\
a - b & = (x - z) + (y - w)\;\mathrm{i}, \\
a \cdot b & = (x + y\;\mathrm{i})(z + w\;\mathrm{i}) \\
& = (xz - yw) + (yz + xw)\;\mathrm{i}, \\
\dfrac{a}{b} & = \dfrac{(x + y\;\mathrm{i})(z - w\;\mathrm{i})}{(z + w\;\mathrm{i})(z - w\;\mathrm{i})} \\
& = \dfrac{(xz + yw) + (yz - xw)\;\mathrm{i}}{z^2 + w^2} \\
& = \dfrac{xz + yw}{z^2 + w^2} + \dfrac{(yz - xw)}{z^2 + w^2}\;\mathrm{i}.
\end{align*}
$$

## 验证部分

给出的测试案例如下：

```c++
assert(CP_Complex(1, 2) + CP_Complex(3, 4) == CP_Complex(4, 6));
assert(CP_Complex(0, 2) - CP_Complex(3, 4) == CP_Complex(-3, -2));
assert(CP_Complex(1, 0) * CP_Complex(3, 4) == CP_Complex(3, 4));
assert(CP_Complex(2, 4) / CP_Complex(0, 2) == CP_Complex(2, -1));

CP_Complex t1, t2, t3, t4;
t1 = t2 = t3 = t4 = CP_Complex(1, 2);
assert(t1++ == CP_Complex(1, 2));
assert(++t2 == CP_Complex(2, 2));
assert(t3-- == CP_Complex(1, 2));
assert(--t4 == CP_Complex(0, 2));
```

其中：

1. 第一条 `assert` 语句验证的是复数的加法，两个加数没有任何限制；
2. 第二条 `assert` 语句验证的是复数的减法，考虑了被减数是**纯虚数**的情况；
3. 第三条 `assert` 语句验证的是复数的乘法，考虑了其中一个乘数是**实数**的情况；
4. 第四条 `assert` 语句验证的是复数的除法，考虑了除数是**纯虚数**的情况；
5. 第五至八条 `assert` 语句验证的是复数类的前置、后置“++”和“--”运算符的正确性。


## 如何编译及运行

在 `hw5/prob1/Complex/` 目录下，执行

```cmd
g++ CP_Complex.h CP_Complex.cpp CP_ComplexMain.cpp -o CP_ComplexMain.exe
```

即可编译得到可执行文件 `CP_Complex.exe`。运行该可执行文件，输入

```
1 2
3 4
5 6
7 8
```

其中每行输入分别对应 $a, b, c, d$；即可得到满足作业要求的输出：

```
a = 1 + 2ib = 3 + 4i
c = 5 + 6id = 7 + 8i
a + b = 4 + 6i
a - b = -2 + -2i
c * d = -13 + 82i
c / d = 0.734513 + 0.0176991i
a++ = 1 + 2i
++b = 4 + 4i
c-- = 5 + 6i
--d = 6 + 8i
请按任意键继续. . . 
```
