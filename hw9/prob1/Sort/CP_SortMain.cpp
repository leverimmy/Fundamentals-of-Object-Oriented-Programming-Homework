#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
#include "CP_Sort.h"

int main(int argc, char* args[]) {

    vector<int> inputs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inputs.push_back(x);
    }

    CP_Sort my_solver(inputs);

    my_solver.sort();
    my_solver.print();
    my_solver.sort_and_deduplicate();
    my_solver.print();

    system("pause");
    return 0;
}
