# 第 6 次作业: 第 1 题

## 验证部分

### 测试方法

为了确保 `CP_StudentManagementSystem` 类的各种功能正常工作，我们进行了以下测试：

1. **添加学生信息：** 使用 `addStudent` 方法添加学生信息，并检查学生信息是否正确添加。
2. **获取学生信息：** 使用 `getAllStudents` 和 `getStudentScore` 方法获取所有学生信息以及指定学生的分数，并检查是否正确获取。
3. **删除学生信息：** 使用 `deleteStudentById` 和 `deleteStudentByScore` 方法删除指定学生，并检查是否删除成功。
4. **获取指定分数的学生ID：** 使用 `getStudentIdByScore` 方法获取指定分数的学生ID，并检查是否正确获取。
5. **清空所有学生信息：** 使用 `clearAllStudents` 方法清空所有学生信息，并检查是否成功清空。

### 测试展开

#### 1. 添加学生信息

```cpp
// 添加学生信息
my_system.addStudent(101, 85);
my_system.addStudent(102, 80);
my_system.addStudent(104, 80);
my_system.addStudent(105, 80);
my_system.addStudent(106, 80);
my_system.addStudent(103, 75);
```

#### 2. 获取学生信息

```cpp
// 获取所有学生信息
assert(my_system.getAllStudents().size() == 6);

// 获取指定学生的分数
assert(my_system.getStudentScore(101) == 85);
assert(my_system.getStudentScore(102) == 80);
assert(my_system.getStudentScore(103) == 75);
assert(my_system.getStudentScore(104) == 80);
assert(my_system.getStudentScore(105) == 80);
assert(my_system.getStudentScore(106) == 80);
```

#### 3. 删除学生信息

```cpp
// 删除学生信息
assert(my_system.getStudentScore(102) == 80); // 检查学生信息是否存在
my_system.deleteStudentById(102); // 删除学生
assert(my_system.getStudentScore(102) == -1); // 确保学生已被删除

assert(my_system.getStudentScore(103) == 75); // 检查学生信息是否存在
my_system.deleteStudentByScore(75); // 删除学生
assert(my_system.getStudentScore(103) == -1); // 确保学生已被删除
```

#### 4. 获取指定分数的学生ID

```cpp
// 获取指定分数的学生ID
vector<int> studentsWithScore80 = my_system.getStudentIdByScore(80);
assert(studentsWithScore80.size() == 3); // 确保学生数量正确
assert(studentsWithScore80[0] == 102); // 第一个学生ID应为102
assert(studentsWithScore80[1] == 104); // 第二个学生ID应为104
assert(studentsWithScore80[2] == 105); // 第三个学生ID应为105
```

#### 5. 清空所有学生信息

```cpp
// 清空所有学生信息
my_system.clearAllStudents();
assert(my_system.getAllStudents().empty()); // 确保学生列表为空
```

### 测试结果

所有测试通过。通过后的输出如下：

```
All tests passed!
```

## 如何进行测试

在 `hw6/prob1/StudentManagementSystem/` 目录下，执行

```
g++ .\CP_Student.h .\CP_StudentManagementSystem.cpp .\CP_StudentManagementSystem.h .\CP_StudentManagementSystemTest.cpp -o .\CP_StudentManagementSystemTest.exe
```

即可编译得到可执行文件 `CP_StudentManagementSystemTest.exe`。运行该可执行文件进行测试。

## 如何编译及运行

在 `hw6/prob1/StudentManagementSystem/` 目录下，执行

```
g++ CP_Student.h CP_StudentManagementSystem.h CP_StudentManagementSystem.cpp CP_StudentManagementSystemMain.cpp -o CP_StudentManagementSystemMain.exe
```

即可编译得到可执行文件 `CP_StudentManagementSystem.exe`。运行该可执行文件后按照提示进行输入。
