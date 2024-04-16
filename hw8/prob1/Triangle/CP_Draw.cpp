#include "pch.h"
#include "CP_Draw.h"

void gb_draw(CDC& d, const CP_Triangle& t, int style, int r, int g, int b) {
    CPen pen(style, 1, RGB(r, g, b));
    CPen* oldPen = d.SelectObject(&pen);

    d.MoveTo((int)(t.m_a.m_x + 0.5), (int)(t.m_a.m_y + 0.5));
    d.LineTo((int)(t.m_b.m_x + 0.5), (int)(t.m_b.m_y + 0.5));

    d.MoveTo((int)(t.m_b.m_x + 0.5), (int)(t.m_b.m_y + 0.5));
    d.LineTo((int)(t.m_c.m_x + 0.5), (int)(t.m_c.m_y + 0.5));

    d.MoveTo((int)(t.m_c.m_x + 0.5), (int)(t.m_c.m_y + 0.5));
    d.LineTo((int)(t.m_a.m_x + 0.5), (int)(t.m_a.m_y + 0.5));

    d.SelectObject(oldPen); // »Ö¸´Ô­ÓÐ»­±Ê
}