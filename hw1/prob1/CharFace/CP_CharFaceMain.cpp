#include <iostream>
using namespace std;
#include "CP_CharFace.h"

int main(int argc, char* args[]) {
    CP_CharFace char_face_object('O', '#', '=');
    char_face_object.mb_drawFace();

    system("pause");
    return 0;
}