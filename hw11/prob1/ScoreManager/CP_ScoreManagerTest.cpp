#include <iostream>
#include <cassert>
#include "CP_ScoreManager.h"

int main() {
    CP_ScoreManager manager;

    // 空文件读取测试
    manager.readScoreSheetFromFile("empty.txt");
    assert(manager.toString() == "");

    // 正常文件读取测试
    manager.readScoreSheetFromFile("scores.txt");
    assert(manager.toString() == "101 85\n102 80\n103 75\n");

    // 文件写入测试
    manager.saveScoreSheetToFile("output.txt");
    assert(system("fc output.txt scores.txt") == 0); // Windows下的文件比较命令

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

    // 边界情况测试(极大极小学号和成绩值)
    manager.addScore(1, 100);
    manager.addScore(2147483647, 0); // 最大int值
    manager.addScore(0, 2147483647); // 最大int值
    assert(manager.toString() == "0 2147483647\n1 100\n101 90\n2147483647 0\n");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
