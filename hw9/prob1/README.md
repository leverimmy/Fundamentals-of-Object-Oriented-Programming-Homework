# 第 9 次作业: 第 1 题

## 验证部分

### 测试方法

为了确保 `CP_Sort` 类的各种功能正常工作，我们进行了以下测试：

1. **整数排序**：使用 `sort` 方法对整数进行排序，并检查排序结果是否正确。
2. **整数排序和去重**：使用 `sort_and_deduplicate` 方法对整数进行排序和去重，并检查结果是否正确。
3. **空向量排序和去重**：使用 `sort_and_deduplicate` 方法对空向量进行排序和去重，并检查结果是否为空。

### 测试展开

#### 1. 整数排序

```cpp
// 整数排序（不去重）
vector<int> integers = {5, 3, 7, 2, 8, 1, 7};
CP_Sort sorter(integers);
sorter.sort();
vector<int> sorted_integers = sorter.get();
assert(sorted_integers[0] == 1);
assert(sorted_integers[1] == 2);
assert(sorted_integers[2] == 3);
assert(sorted_integers[3] == 5);
assert(sorted_integers[4] == 7);
assert(sorted_integers[5] == 7);
assert(sorted_integers[6] == 8);
```

#### 2. 整数排序和去重

```cpp
// 整数排序（且去重）
vector<int> integers2 = {5, 3, 7, 2, 8, 1, 7};
CP_Sort sorter2(integers2);
sorter2.sort_and_deduplicate();
vector<int> sorted_deduplicated_integers = sorter2.get();
assert(sorted_deduplicated_integers[0] == 1);
assert(sorted_deduplicated_integers[1] == 2);
assert(sorted_deduplicated_integers[2] == 3);
assert(sorted_deduplicated_integers[3] == 5);
assert(sorted_deduplicated_integers[4] == 7);
assert(sorted_deduplicated_integers[5] == 8);
```

#### 3. 空向量排序和去重

```cpp
// 空向量排序和去重
vector<int> empty_vector;
CP_Sort sorter3(empty_vector);
sorter3.sort_and_deduplicate();
vector<int> sorted_deduplicated_empty_vector = sorter3.get();
assert(sorted_deduplicated_empty_vector.empty());
```

这些测试确保了 `CP_Sort` 类中的排序和去重功能的正确性。

### 测试结果

所有测试通过。通过后的输出如下：

```
All tests passed!
```

## 如何进行测试

在 `hw9/prob1/Sort/` 目录下，执行

```
g++ CP_Sort.h CP_Sort.cpp CP_SortTest.cpp -o CP_SortTest.exe
```

即可编译得到可执行文件 `CP_SortTest.exe`。运行该可执行文件进行测试。

## 如何编译及运行

在 `hw9/prob1/Sort/` 目录下，执行

```
g++ CP_Sort.cpp CP_SortMain.cpp -o CP_SortMain.exe
```

即可编译得到可执行文件 `CP_SortMain.exe`。运行该可执行文件后按照以下格式进行输入：

```
10
1 3 5 7 9 3 5 9 7 1
```

其中第一行为 $n$，表示输入整数个数；第二行为 $n$ 个数，表示输入的整数，使用空格隔开。

则输出将会为：

```
[1, 1, 3, 3, 5, 5, 7, 7, 9, 9]
[1, 3, 5, 7, 9]
请按任意键继续. . .
```

其中

- 第一行采用算法 (algorithm) 库的 `sort` 函数对这些整数进行排序（不去重），并输出排序结果。
- 第二行采用集合 (set) 对这些整数进行排序（并去重），输出排序结果。

