#include <iostream>
#include <cassert>
#include "CP_Integer.h"

int main() {
    
    // 测试正常情况
    CP_Integer cp1("123");
    assert(cp1.get_x() == 123 && nullptr == cp1.get_exception());
    CP_Integer cp2("-123");
    assert(cp2.get_x() == -123 && nullptr == cp2.get_exception());
    CP_Integer cp3("0");
    assert(cp3.get_x() == 0 && nullptr == cp3.get_exception());
    CP_Integer cp4("2147483647");
    assert(cp4.get_x() == 2147483647 && nullptr == cp4.get_exception());
    CP_Integer cp5("-2147483648");
    assert(cp5.get_x() == -2147483648 && nullptr == cp5.get_exception());

    // 测试非法字符
    CP_Integer cp6("123a");
    assert(dynamic_cast<CP_Invalid_Character_Exception*>(cp6.get_exception()) != nullptr);

    // 测试前导 0
    CP_Integer cp7("00123");
    assert(dynamic_cast<CP_Too_Many_Leading_Zeros_Exception*>(cp7.get_exception()) != nullptr);

    // 测试前导符号
    CP_Integer cp8("++++123");
    assert(dynamic_cast<CP_Too_Many_Leading_Operators_Exception*>(cp8.get_exception()) != nullptr);
    CP_Integer cp9("--123");
    assert(dynamic_cast<CP_Too_Many_Leading_Operators_Exception*>(cp9.get_exception()) != nullptr);

    // 测试空字符串
    CP_Integer cp10("");
    assert(dynamic_cast<CP_Empty_String_Exception*>(cp10.get_exception()) != nullptr);

    // 测试范围
    CP_Integer cp11("2147483648");
    assert(dynamic_cast<CP_Out_Of_Range_Exception*>(cp11.get_exception()) != nullptr);
    CP_Integer cp12("-2147483649");
    assert(dynamic_cast<CP_Out_Of_Range_Exception*>(cp12.get_exception()) != nullptr);

    // 测试成功
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
