#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
#include "CP_Sort.h"

int main() {
    // Test case 1: Sort integers
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

    // Test case 2: Sort and deduplicate integers
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

    // Test case 3: Sort and deduplicate empty vector
    vector<int> empty_vector;
    CP_Sort sorter3(empty_vector);
    sorter3.sort_and_deduplicate();
    vector<int> sorted_deduplicated_empty_vector = sorter3.get();
    assert(sorted_deduplicated_empty_vector.empty());

    // All tests passed
    cout << "All tests passed!" << endl;
    return 0;
}
