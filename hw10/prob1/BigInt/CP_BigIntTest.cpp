#include <iostream>
#include <cassert>
#include <string>
using namespace std;
#include "CP_BigInt.h"

int main() {
    // 测试加法
    assert(CP_BigInt("123") + CP_BigInt("998") == CP_BigInt("1121"));
    assert(CP_BigInt("123") + CP_BigInt("-998") == CP_BigInt("-875"));
    assert(CP_BigInt("-998") + CP_BigInt("123") == CP_BigInt("-875"));
    assert(CP_BigInt("-998") + CP_BigInt("-123") == CP_BigInt("-1121"));
    assert(CP_BigInt("000") + CP_BigInt("000") == CP_BigInt("0"));
    assert(CP_BigInt("000") + CP_BigInt("-0001") == CP_BigInt("-1"));
    assert(CP_BigInt("+0001") + CP_BigInt("-0001") == CP_BigInt("0"));
    // 测试减法
    assert(CP_BigInt("123") - CP_BigInt("998") == CP_BigInt("-875"));
    assert(CP_BigInt("123") - CP_BigInt("-998") == CP_BigInt("1121"));
    assert(CP_BigInt("-998") - CP_BigInt("123") == CP_BigInt("-1121"));
    assert(CP_BigInt("-998") - CP_BigInt("-123") == CP_BigInt("-875"));
    assert(CP_BigInt("000") - CP_BigInt("000") == CP_BigInt("0"));
    assert(CP_BigInt("000") - CP_BigInt("-0001") == CP_BigInt("1"));
    assert(CP_BigInt("+0001") - CP_BigInt("-0001") == CP_BigInt("2"));
    // 测试完成
    cout << "All tests passed!" << endl;
    return 0;
}
