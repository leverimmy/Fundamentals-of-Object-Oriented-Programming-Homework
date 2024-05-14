#include <iostream>
#include <string>
using namespace std;
#include "CP_ScoreManager.h"

int main() {
    CP_ScoreManager score_manager;

    while (true) {
        int command, studentId, score;
        string filename;
        cout << "--------------------------------\n";
        cout << "Score Manager\n";
        cout << "Enter command number:\n";
        cout << "1. Read score sheet from file\n";
        cout << "2. Add score\n";
        cout << "3. Remove score\n";
        cout << "4. Remove all scores\n";
        cout << "5. Modify score\n";
        cout << "6. Output score\n";
        cout << "7. Display all scores\n";
        cout << "8. Save score sheet to file\n";
        cout << "-1. Exit\n";
        cout << "--------------------------------\n";
        cout << "Command: ";
        cin >> command;

        switch (command) {
            case 1:
                cout << "Enter filename: ";
                cin >> filename;
                score_manager.readScoreSheetFromFile(filename);
                break;
            case 2:
                cout << "Enter student ID and score:\n";
                cout << "Student ID: ";
                cin >> studentId;
                cout << "Score: ";
                cin >> score;
                score_manager.addScore(studentId, score);
                break;
            case 3:
                cout << "Enter student ID: ";
                cin >> studentId;
                score_manager.removeScore(studentId);
                break;
            case 4:
                score_manager.removeAllScores();
                break;
            case 5:
                cout << "Enter student ID and new score: ";
                cout << "Student ID: ";
                cin >> studentId;
                cout << "Score: ";
                cin >> score;
                score_manager.modifyScore(studentId, score);
                break;
            case 6:
                cout << "Enter student ID: ";
                cin >> studentId;
                score_manager.outputScore(studentId);
                break;
            case 7:
                score_manager.displayAllScores();
                break;
            case 8:
                cout << "Enter filename: ";
                cin >> filename;
                score_manager.saveScoreSheetToFile(filename);
                break;
            case -1:
                cout << "Program exited." << endl;
                system("pause");
                return 0;
            default:
                cout << "Invalid command number. Please try again." << endl;
                break;
        }
    }
}
