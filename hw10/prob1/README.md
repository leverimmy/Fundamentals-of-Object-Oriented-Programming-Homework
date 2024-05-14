# 第 10 次作业: 第 1 题

## 验证部分

### 测试方法

为了确保 `CP_BigInt` 类的各种功能正常工作，我们进行了以下测试：

1. **加法运算：** 对加法运算进行测试
2. **减法运算：** 对减法运算进行测试。

每种运算一共进行五类测试：

- 正数相加
- 正数与负数相加
- 负数与正数相加
- 负数相加
- 零相加

### 测试展开

#### 1. 加法运算

```cpp
// 正数相加
assert(CP_BigInt("123") + CP_BigInt("998") == CP_BigInt("1121"));

// 正数与负数相加
assert(CP_BigInt("123") + CP_BigInt("-998") == CP_BigInt("-875"));

// 负数与正数相加
assert(CP_BigInt("-998") + CP_BigInt("123") == CP_BigInt("-875"));

// 负数相加
assert(CP_BigInt("-998") + CP_BigInt("-123") == CP_BigInt("-1121"));

// 零相加
assert(CP_BigInt("000") + CP_BigInt("000") == CP_BigInt("0"));
assert(CP_BigInt("000") + CP_BigInt("-0001") == CP_BigInt("-1"));
assert(CP_BigInt("+0001") + CP_BigInt("-0001") == CP_BigInt("0"));
```

#### 2. 减法运算

```cpp
// 正数相减
assert(CP_BigInt("123") - CP_BigInt("998") == CP_BigInt("-875"));

// 正数与负数相减
assert(CP_BigInt("123") - CP_BigInt("-998") == CP_BigInt("1121"));

// 负数与正数相减
assert(CP_BigInt("-998") - CP_BigInt("123") == CP_BigInt("-1121"));

// 负数相减
assert(CP_BigInt("-998") - CP_BigInt("-123") == CP_BigInt("-875"));

// 零相减
assert(CP_BigInt("000") - CP_BigInt("000") == CP_BigInt("0"));
assert(CP_BigInt("000") - CP_BigInt("-0001") == CP_BigInt("1"));
assert(CP_BigInt("+0001") - CP_BigInt("-0001") == CP_BigInt("2"));
```

这些测试确保了 `CP_BigInt` 类中加法和减法运算的正确性。

### 测试结果

所有测试通过。通过后的输出如下：

```
All tests passed!
```

## 如何进行测试

在 `hw10/prob1/BigInt/` 目录下，执行

```
g++ CP_BigInt.cpp CP_BigIntTest.cpp -o CP_BigIntTest.exe
```

即可编译得到可执行文件 `CP_BigIntTest.exe`。运行该可执行文件进行测试。

## 如何编译及运行

在 `hw10/prob1/BigInt/` 目录下，执行

```
g++ CP_BigInt.cpp CP_BigIntMain.cpp -o CP_BigIntMain.exe
```

即可编译得到可执行文件 `CP_BigIntMain.exe`。运行该可执行文件后按照以下格式进行输入：

```
+0000 -1
```

其中第一个数为 $a$，第二个数为 $b$ 个数，表示输入的两个整数，使用空格隔开。

则输出将会为：

```
0 + -1 = -1
0 - -1 = 1
请按任意键继续. . .
```

表示了二者的和与差。

