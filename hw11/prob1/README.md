# 第 11 次作业: 第 1 题

## 模型部分

程序的基本思路是使用 C++ 标准库中的 `std::map` 容器来存储学生成绩信息，其中学生 ID 作为键，成绩作为值。

我将其封装成了一个类 `CP_ScoreManager`，添加了一系列成员函数用于对成绩表单进行增、删、改、查等操作。

## 验证部分

### 测试方法

为了确保 `CP_ScoreManager` 类的各种功能正常工作，我设计了以下测试:

1. **文件读写测试**：测试从文件读取成绩表单以及将成绩表单写入文件的功能。
2. **成绩操作测试**：测试添加、删除、修改和查询成绩的功能，包括存在和不存在的学号情况。
3. **边界测试**：测试极大极小学号和成绩值的情况。

### 测试展开

#### 1. 文件读写测试

```cpp
// 空文件读取测试
manager.readScoreSheetFromFile("empty.txt");
assert(manager.toString() == "");

// 正常文件读取测试
manager.readScoreSheetFromFile("scores.txt");
assert(manager.toString() == "101 85\n102 80\n103 75\n");

// 文件写入测试
manager.saveScoreSheetToFile("output.txt");
assert(system("fc output.txt scores.txt") == 0); // Windows下的文件比较命令
```

#### 2. 成绩操作测试

```cpp
// 成绩添加测试
manager.addScore(104, 90);
assert(manager.toString() == "101 85\n102 80\n103 75\n104 90\n");

// 成绩删除测试(存在的学号)
manager.removeScore(102);
assert(manager.toString() == "101 85\n103 75\n104 90\n");

// 成绩删除测试(不存在的学号)
manager.removeScore(999);
assert(manager.toString() == "101 85\n103 75\n104 90\n");

// 全部成绩删除测试
manager.removeAllScores();
assert(manager.toString() == "");

// 成绩修改测试(存在的学号)
manager.addScore(101, 85);
manager.modifyScore(101, 90);
assert(manager.toString() == "101 90\n");

// 成绩修改测试(不存在的学号)
manager.modifyScore(999, 80);
assert(manager.toString() == "101 90\n");

// 成绩查询测试(存在的学号)
assert(manager.outputScore(101) == "Score for student ID 101 is 90.\n");

// 成绩查询测试(不存在的学号)
assert(manager.outputScore(999) == "Student ID 999 not found in the current score sheet.\n");

// 显示所有成绩测试
assert(manager.displayAllScores() == "Current score sheet:\nStudent ID:\t101\tScore:\t90\n");
```

#### 3. 边界测试

```cpp
// 边界情况测试(极大极小学号和成绩值)
manager.addScore(1, 100);
manager.addScore(2147483647, 0); // 最大int值
manager.addScore(0, 2147483647); // 最大int值
assert(manager.toString() == "0 2147483647\n1 100\n101 90\n2147483647 0\n");
```

这些测试确保了 `CP_ScoreManager` 类中各种功能的正确性，包括文件读写、成绩操作以及边界情况处理。

### 测试结果

所有测试均通过，输出如下：

```
Score sheet has been read from the file and added to the current score sheet.
Score sheet has been read from the file and added to the current score sheet.
Current score sheet has been saved to the file.
正在比较文件 output.txt 和 SCORES.TXT
FC: 找不到差异

Student ID 104 Score 90 has been added to the current score sheet.
Student ID 102 and its score have been removed from the current score sheet.
Student ID 999 not found in the current score sheet.
The current score sheet has been cleared.
Student ID 101 Score 85 has been added to the current score sheet.
Score for student ID 101 has been modified to 90.
Student ID 999 not found in the current score sheet.
Student ID 1 Score 100 has been added to the current score sheet.
Student ID 2147483647 Score 0 has been added to the current score sheet.
Student ID 0 Score 2147483647 has been added to the current score sheet.
All tests passed!
```

## 如何进行测试

在 `hw11/prob1/ScoreManager/` 目录下，执行

```
g++ CP_ScoreManager.cpp CP_ScoreManagerTest.cpp -o CP_ScoreManagerTest.exe
```

即可编译得到可执行文件 `CP_ScoreManagerTest.exe`。运行该可执行文件进行测试。

## 如何编译及运行

在 `hw11/prob1/ScoreManager/` 目录下，执行

```
g++ CP_ScoreManager.cpp .\CP_ScoreManagerMain.cpp -o CP_ScoreManagerMain.exe
```

即可编译得到可执行文件 `CP_ScoreManagerMain.exe`。运行该可执行文件后按照提示格式输出即可。
