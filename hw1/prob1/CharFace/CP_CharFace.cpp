#include <iostream>
using namespace std;
#include "CP_CharFace.h"

void CP_CharFace::mb_drawFace() {
    cout << "  " << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << endl;
    cout << " " << m_char_outline << "        " << m_char_outline << endl;
    cout << m_char_outline << "  " << m_char_eye << "    " << m_char_eye << "  " << m_char_outline << endl;
    cout << m_char_outline << "  " << m_char_eye << "    " << m_char_eye << "  " << m_char_outline << endl;
    cout << m_char_outline << "          " << m_char_outline << endl;
    cout << m_char_outline << "  " << m_char_mouth << m_char_mouth << m_char_mouth << m_char_mouth << m_char_mouth << m_char_mouth << "  " << m_char_outline << endl;
    cout << " " << m_char_outline << "        " << m_char_outline << endl;
    cout << "  " << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << m_char_outline << endl;
}