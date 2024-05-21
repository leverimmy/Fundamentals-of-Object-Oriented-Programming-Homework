#ifndef CP_EXCEPTION_H
#define CP_EXCEPTION_H

class CP_Exception_Base {
public:
    virtual ~CP_Exception_Base() = default;
    virtual const char* what() const = 0; // 添加虚函数
};

class CP_Invalid_Character_Exception : public CP_Exception_Base {
public:
    const char* what() const override { return "Invalid character"; }
};

class CP_Too_Many_Leading_Zeros_Exception : public CP_Exception_Base {
public:
    const char* what() const override { return "Too many leading zeros"; }
};

class CP_Out_Of_Range_Exception : public CP_Exception_Base {
public:
    const char* what() const override { return "Out of range"; }
};

class CP_Too_Many_Leading_Operators_Exception : public CP_Exception_Base {
public:
    const char* what() const override { return "Too many leading operators"; }
};

class CP_Empty_String_Exception : public CP_Exception_Base {
public:
    const char* what() const override { return "Empty string"; }
};

class CP_Unknown_Exception : public CP_Exception_Base {
public:
    const char* what() const override { return "Unknown exception"; }
};
#endif
