#include "../HeadFile/PushButton.h"

PushButton::PushButton(const std::string& text, int x, int y, int width, int height)
        : BassicWidget(x, y, width, height), m_text(text)
{

}

void PushButton::show()
{
    setfillcolor(cur_c);
    ::fillroundrect(m_x, m_y, m_x + m_width, m_y + m_height,10,10);

    //设置文字的颜色
    settextcolor(BLACK);
    //把文字居中显示在按钮中间
    int charX = m_x + (m_width - textwidth(m_text.c_str())) / 2;
    int charY = m_y + (m_height - textheight(m_text.c_str())) / 2;
    ::outtextxy(charX, charY, m_text.c_str());
}

bool PushButton::isin()
{
    if (m_msg.x >= m_x && m_msg.x < m_x + m_width && m_msg.y >= m_y && m_msg.y < m_y + m_height) {
        return true;
    }
    return false;
}

bool PushButton::isclicked()
{

    if (isin()&&m_msg.message == WM_LBUTTONDOWN) {
        return true;
    }
    return false;

}

void PushButton::eventloop(const ExMessage& msg)
{
    m_msg = msg;
    if (!isin()) {
        cur_c = normal_c;
    }
    else {
        cur_c = hover_c;
    }
}

void PushButton::setBackGroundColor(COLORREF color)
{
    normal_c = color;
}

void PushButton::setHoverColor(COLORREF color)
{
    hover_c = color;
}
