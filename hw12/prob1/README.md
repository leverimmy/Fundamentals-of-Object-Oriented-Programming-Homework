# 第 12 次作业: 第 1 题

## 模型部分

`CP_Integer` 类是一个用于表示整数的类，它接受一个字符串作为构造函数参数，并根据该字符串构造对应的整数值。

在构造函数中，首先会对输入的字符串进行合法性检查，包括以下几个方面:

1. **检查是否包含非法字符**：字符串中只允许出现数字和正负号，任何其他字符都将被视为非法。
2. **检查前导零的数量**：字符串中允许存在一个前导零，但不允许多个前导零。
3. **检查前导符号的数量**：字符串中允许存在一个正号或负号，但不允许多个正号或负号。
4. **检查是否为空字符串**：空字符串是非法的，将被视为异常情况。
5. **检查是否超出整数范围**：如果字符串表示的数值超出了整数的表示范围，也将被视为异常情况。

如果在上述任何一个检查中发现异常情况，构造函数将抛出相应的异常，并将异常对象存储在类的私有成员变量 `m_exception` 中。否则，构造函数将成功构造出对应的整数值，并将其存储在私有成员变量 `m_x` 中。

`CP_Integer` 类还提供了其他成员函数，如 `get_x()` 用于获取整数值，`get_exception()` 用于获取异常对象(如果存在)。

其中 `m_exception` 可以为由 `CP_Exception_Base` 派生出的 `CP_Invalid_Character_Exception`、`CP_Too_Many_Leading_Zeros_Exception`、`CP_Out_Of_Range_Exception`、`CP_Too_Many_Leading_Operators_Exception`、`CP_Empty_String_Exception` 和 `CP_Unknown_Exception`。

## 验证部分

### 测试方法

为了确保 `CP_Integer` 类的各种功能正常工作，我设计了以下测试:

1. **测试正常情况**：
    - 测试用正数字符串构造 `CP_Integer` 对象
    - 测试用负数字符串构造 `CP_Integer` 对象
    - 测试用字符串 `"0"` 构造 `CP_Integer` 对象
    - 测试用最大正整数字符串构造 `CP_Integer` 对象
    - 测试用最小负整数字符串构造 `CP_Integer` 对象
2. **测试包含非法字符的异常情况**
3. **测试包含多个前导零的异常情况**
4. **测试包含多个前导符号的异常情况**
5. **测试空字符串的异常情况**
6. **测试超出整数范围的情况**

测试程序通过创建 `CP_Integer` 对象并检查其 `get_x()` 和 `get_exception()` 的返回值来验证构造是否成功。

- 对于正常情况，`get_x()` 应返回正确的整数值，`get_exception()` 应返回 `nullptr`。
- 对于异常情况，`get_exception()` 应返回相应异常类型的非空指针。

对于异常情况，测试程序使用 `dynamic_cast` 来检查返回的异常指针是否为期望的异常类型。

### 测试展开

#### 1. 正常情况测试

```cpp
// 测试正常情况
CP_Integer cp1("123");
assert(cp1.get_x() == 123 && nullptr == cp1.get_exception());
CP_Integer cp2("-123");
assert(cp2.get_x() == -123 && nullptr == cp2.get_exception());
CP_Integer cp3("0");
assert(cp3.get_x() == 0 && nullptr == cp3.get_exception());
CP_Integer cp4("2147483647");
assert(cp4.get_x() == 2147483647 && nullptr == cp4.get_exception());
CP_Integer cp5("-2147483648");
assert(cp5.get_x() == -2147483648 && nullptr == cp5.get_exception());
```

#### 2. 测试非法字符

```cpp
CP_Integer cp6("123a");
assert(dynamic_cast<CP_Invalid_Character_Exception*>(cp6.get_exception()) != nullptr);
```

#### 3. 测试前导 0

```cpp
// 测试前导 0
CP_Integer cp7("00123");
assert(dynamic_cast<CP_Too_Many_Leading_Zeros_Exception*>(cp7.get_exception()) != nullptr);
```

#### 4. 测试前导符号

```cpp
// 测试前导符号
CP_Integer cp8("++++123");
assert(dynamic_cast<CP_Too_Many_Leading_Operators_Exception*>(cp8.get_exception()) != nullptr);
CP_Integer cp9("--123");
assert(dynamic_cast<CP_Too_Many_Leading_Operators_Exception*>(cp9.get_exception()) != nullptr);
```

#### 5. 测试空字符串

```cpp
// 测试空字符串
CP_Integer cp10("");
assert(dynamic_cast<CP_Empty_String_Exception*>(cp10.get_exception()) != nullptr);
```

#### 6. 测试范围

```cpp
// 测试范围
CP_Integer cp11("2147483648");
assert(dynamic_cast<CP_Out_Of_Range_Exception*>(cp11.get_exception()) != nullptr);
CP_Integer cp12("-2147483649");
assert(dynamic_cast<CP_Out_Of_Range_Exception*>(cp12.get_exception()) != nullptr);
```

这些测试确保了 `CP_Integer` 类中各种功能的正确性。

### 测试结果

所有测试均通过，输出如下：

```
Invalid character
Too many leading zeros
Too many leading operators
Too many leading operators
Empty string
Out of range
Out of range
All tests passed!
```

## 如何进行测试

在 `hw12/prob1/Integer/` 目录下，执行

```
g++ CP_Integer.cpp CP_IntegerTest.cpp -o CP_IntegerTest.exe
```

即可编译得到可执行文件 `CP_IntegerTest.exe`。运行该可执行文件进行测试。

## 如何编译及运行

在 `hw12/prob1/Integer/` 目录下，执行

```
g++ CP_Integer.cpp .\CP_IntegerMain.cpp -o CP_IntegerMain.exe
```

即可编译得到可执行文件 `CP_IntegerMain.exe`。运行该可执行文件后按照提示格式输出即可。
