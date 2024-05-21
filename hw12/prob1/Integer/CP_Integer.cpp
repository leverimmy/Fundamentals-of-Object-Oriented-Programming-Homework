#include "CP_Integer.h"

CP_Integer::CP_Integer(const string &s) {
    try {
        int len = s.length();

        // 处理前导符号
        int m_sign = 1, l = 0;
        while (l < len && (s[l] == '+' || s[l] == '-')) {
            if (s[l] == '-') {
                m_sign = -m_sign;
            }
            l++;
        }
        if (l > 1) {
            throw CP_Too_Many_Leading_Operators_Exception();
        }

        // 处理空字符串
        if (l == len) {
            throw CP_Empty_String_Exception();
        }

        // 处理非法字符
        for (int i = 1; i < len; i++) {
            if (s[i] < '0' || s[i] > '9') {
                throw CP_Invalid_Character_Exception();
            }
        }
        if (s[0] != '+' && s[0] != '-' && (s[0] < '0' || s[0] > '9')) {
            throw CP_Invalid_Character_Exception();
        }

        // 处理前导 0
        if (s[l] == '0' && len - l > 1) {
            throw CP_Too_Many_Leading_Zeros_Exception();
        }
        
        // 限制范围
        if (len - l > 10) {
            throw CP_Out_Of_Range_Exception();
        }
        long long temp_result = 0;
        for (int i = l; i < len; i++) {
            temp_result = temp_result * 10 + s[i] - '0';
        }
        temp_result *= m_sign;
        if (temp_result > INT_MAX || temp_result < INT_MIN) {
            throw CP_Out_Of_Range_Exception();
        }

        // 通过所有检查
        m_exception = nullptr;
        m_x = temp_result;
    } catch (const CP_Invalid_Character_Exception &e) {
        m_exception = new CP_Invalid_Character_Exception();
    } catch (const CP_Too_Many_Leading_Zeros_Exception &e) {
        m_exception = new CP_Too_Many_Leading_Zeros_Exception();
    } catch (const CP_Out_Of_Range_Exception &e) {
        m_exception = new CP_Out_Of_Range_Exception();
    } catch (const CP_Too_Many_Leading_Operators_Exception &e) {
        m_exception = new CP_Too_Many_Leading_Operators_Exception();
    } catch (const CP_Empty_String_Exception &e) {
        m_exception = new CP_Empty_String_Exception();
    } catch (...) {
        m_exception = new CP_Unknown_Exception();
    }
    if (m_exception != nullptr) {
        m_x = 0;
        cout << m_exception->what() << endl;
    }
}

ostream &operator<<(ostream &os, const CP_Integer &cp) {
    if (cp.m_exception == nullptr) {
        os << cp.m_x;
    }
    return os;
}

int CP_Integer::get_x() const {
    return m_x;
}

CP_Exception_Base *CP_Integer::get_exception() const {
    return m_exception;
}
