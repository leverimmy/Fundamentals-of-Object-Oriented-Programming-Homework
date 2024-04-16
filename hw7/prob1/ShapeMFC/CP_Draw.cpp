#include "pch.h"
#include "CP_Draw.h"

void gb_draw(CDC& d, const CP_Circle& c, int style, int r, int g, int b) {
    CPen pen(style, 1, RGB(r, g, b));
    CPen* oldPen = d.SelectObject(&pen);

    int radius = (int)(c.m_radius + 0.5);
    int x = (int)(c.m_center.m_x + 0.5);
    int y = (int)(c.m_center.m_y + 0.5);

    d.Ellipse(x - radius, y - radius, x + radius, y + radius);

    d.SelectObject(oldPen); // »Ö¸´Ô­ÓÐ»­±Ê
}

void gb_draw(CDC& d, const CP_Square& s, int style, int r, int g, int b) {
    CPen pen(style, 1, RGB(r, g, b));
    CPen* oldPen = d.SelectObject(&pen);
    d.MoveTo((int)(s.m_center.m_x - s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y - s.m_side_length / 2 + 0.5));
    d.LineTo((int)(s.m_center.m_x + s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y - s.m_side_length / 2 + 0.5));

    d.MoveTo((int)(s.m_center.m_x + s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y - s.m_side_length / 2 + 0.5));
    d.LineTo((int)(s.m_center.m_x + s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y + s.m_side_length / 2 + 0.5));

    d.MoveTo((int)(s.m_center.m_x + s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y + s.m_side_length / 2 + 0.5));
    d.LineTo((int)(s.m_center.m_x - s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y + s.m_side_length / 2 + 0.5));

    d.MoveTo((int)(s.m_center.m_x - s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y + s.m_side_length / 2 + 0.5));
    d.LineTo((int)(s.m_center.m_x - s.m_side_length / 2 + 0.5),
        (int)(s.m_center.m_y - s.m_side_length / 2 + 0.5));

    d.SelectObject(oldPen); // »Ö¸´Ô­ÓÐ»­±Ê
}

void gb_draw(CDC& d, const CP_Triangle& t, int style, int r, int g, int b) {
    CPen pen(style, 1, RGB(r, g, b));
    CPen* oldPen = d.SelectObject(&pen);

    d.MoveTo((int)(t.m_center.m_x + 0.5),
        (int)(t.m_center.m_y - t.m_side_length / sqrt(3) + 0.5));
    d.LineTo((int)(t.m_center.m_x + t.m_side_length / 2 + 0.5),
        (int)(t.m_center.m_y + t.m_side_length / (2 * sqrt(3)) + 0.5));

    d.MoveTo((int)(t.m_center.m_x + t.m_side_length / 2 + 0.5),
        (int)(t.m_center.m_y + t.m_side_length / (2 * sqrt(3)) + 0.5));
    d.LineTo((int)(t.m_center.m_x - t.m_side_length / 2 + 0.5),
        (int)(t.m_center.m_y + t.m_side_length / (2 * sqrt(3)) + 0.5));

    d.MoveTo((int)(t.m_center.m_x - t.m_side_length / 2 + 0.5),
        (int)(t.m_center.m_y + t.m_side_length / (2 * sqrt(3)) + 0.5));
    d.LineTo((int)(t.m_center.m_x + 0.5),
        (int)(t.m_center.m_y - t.m_side_length / sqrt(3) + 0.5));

    d.SelectObject(oldPen); // »Ö¸´Ô­ÓÐ»­±Ê
}