#include "CP_ScoreManager.h"

// 从文件中读取成绩表单并添加到当前成绩表单中
void CP_ScoreManager::readScoreSheetFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int studentId, score;
        while (file >> studentId >> score) {
            m_scoreSheet[studentId] = score;
        }
        file.close();
        cout << "Score sheet has been read from the file and added to the current score sheet." << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// 将当前成绩表单保存到文件中
void CP_ScoreManager::saveScoreSheetToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : m_scoreSheet) {
            file << entry.first << " " << entry.second << endl;
        }
        file.close();
        cout << "Current score sheet has been saved to the file." << endl;
    } else {
        cout << "Unable to create file: " << filename << endl;
    }
}

// 添加学号和成绩到当前成绩表单中
void CP_ScoreManager::addScore(int studentId, int score) {
    m_scoreSheet[studentId] = score;
    cout << "Student ID " << studentId << " Score " << score << " has been added to the current score sheet." << endl;
}

// 从当前成绩表单中删除学号及其成绩
void CP_ScoreManager::removeScore(int studentId) {
    if (m_scoreSheet.count(studentId) > 0) {
        m_scoreSheet.erase(studentId);
        cout << "Student ID " << studentId << " and its score have been removed from the current score sheet." << endl;
    } else {
        cout << "Student ID " << studentId << " not found in the current score sheet." << endl;
    }
}

// 删除当前成绩表单中的所有学号及其成绩
void CP_ScoreManager::removeAllScores() {
    m_scoreSheet.clear();
    cout << "The current score sheet has been cleared." << endl;
}

// 修改当前成绩表单中学号对应的成绩
void CP_ScoreManager::modifyScore(int studentId, int newScore) {
    if (m_scoreSheet.count(studentId) > 0) {
        m_scoreSheet[studentId] = newScore;
        cout << "Score for student ID " << studentId << " has been modified to " << newScore << "." << endl;
    } else {
        cout << "Student ID " << studentId << " not found in the current score sheet." << endl;
    }
}

// 输出学号对应的成绩
void CP_ScoreManager::outputScore(int studentId) const {
    if (m_scoreSheet.count(studentId) > 0) {
        cout << "Score for student ID " << studentId << " is " << m_scoreSheet.at(studentId) << "." << endl;
    } else {
        cout << "Student ID " << studentId << " not found in the current score sheet." << endl;
    }
}

// 显示所有学号及其对应的成绩
void CP_ScoreManager::displayAllScores() const {
    cout << "Current score sheet:" << endl;
    for (const auto& entry : m_scoreSheet) {
        cout << "Student ID:\t" << entry.first << "\t Score:\t" << entry.second << endl;
    }
}
