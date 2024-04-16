#ifndef CP_DRAW_H
#define CP_DRAW_H

#include "CP_Circle.h"
#include "CP_Square.h"
#include "CP_Triangle.h"

extern void gb_draw(CDC& d, const CP_Circle& c, int style, int r, int g, int b);
extern void gb_draw(CDC& d, const CP_Square& s, int style, int r, int g, int b);
extern void gb_draw(CDC& d, const CP_Triangle& t, int style, int r, int g, int b);
#endif
