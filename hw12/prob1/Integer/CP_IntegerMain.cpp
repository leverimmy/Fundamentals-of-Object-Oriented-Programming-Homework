#include <iostream>
#include <string>
using namespace std;
#include "CP_Integer.h"

int main() {
    string input;
    while (cin >> input) {
        CP_Integer cp(input);
        cout << cp << endl;
    }
    // cin >> input;
    // CP_Integer cp(input);
    // cout << cp << endl;
    system("pause");
    return 0;
}
