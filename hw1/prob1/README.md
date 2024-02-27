# 第 1 次作业: 第 1 题

## 代码说明

### 头文件

- `CP_CharFace.h`

  定义人脸类（`CP_CharFace`），采用指定的三个字符绘画像素人脸。

  |       变量       |       意义       |
  | :--------------: | :--------------: |
  | `m_char_outline` | 脸的轮廓所用字符 |
  |   `m_char_eye`   |   眼睛所用字符   |
  |  `m_char_mouth`  |   嘴巴所用字符   |

### 源文件

- `CP_CharFace.cpp`

  实现类 `CP_CharFace` 的成员函数 `mb_drawFace`，实现采用指定三个字符画像素人脸。

- `CP_CharFaceMain.cpp`

  定义主函数，程序入口。在主函数中，创建类 `CP_CharFace` 的实例对象 `char_face_object`，并通过调用其成员函数实现画像素人脸的功能。

## 如何编译及运行

在 `hw1/prob1/CharFace/` 目录下，执行

```cmd
g++ CP_CharFace.h CP_CharFace.cpp CP_CharFaceMain.cpp -o CP_CharFaceMain.exe
```

即可编译得到可执行文件 `CP_CharFaceMain.exe`。运行该可执行文件即可得到满足作业要求的输出。

## 输出结果

```
  OOOOOOOO
 O        O
O  #    #  O
O  #    #  O
O          O
O  ======  O
 O        O
  OOOOOOOO
请按任意键继续. . .
```

**图案的含义**：这是一幅由 `O` 作为脸的轮廓，`#` 作为眼睛，`=` 作为嘴巴，三者构成的像素人脸。