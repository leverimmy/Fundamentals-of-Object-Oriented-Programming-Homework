#ifndef CP_CHARFACE_H
#define CP_CHARFACE_H

class CP_CharFace {
public:
    char m_char_outline;
    char m_char_eye;
    char m_char_mouth;

    CP_CharFace(char outline = '*', char eye = '#', char mouth = '=') : m_char_outline(outline), m_char_eye(eye), m_char_mouth(mouth) {}
    ~CP_CharFace() {}
    
    void mb_drawFace();
};
#endif