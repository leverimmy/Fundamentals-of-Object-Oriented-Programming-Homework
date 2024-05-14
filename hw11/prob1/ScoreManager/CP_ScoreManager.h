#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
#ifndef CP_SCOREMANAGER_H
#define CP_SCOREMANAGER_H

typedef map<int, int> ScoreSheet;

class CP_ScoreManager {
public:
    void readScoreSheetFromFile(const string& filename);
    void saveScoreSheetToFile(const string& filename);
    void addScore(int studentId, int score);
    void removeScore(int studentId);
    void removeAllScores();
    void modifyScore(int studentId, int newScore);
    void outputScore(int studentId) const;
    void displayAllScores() const;
private:
    ScoreSheet m_scoreSheet;
};
#endif
