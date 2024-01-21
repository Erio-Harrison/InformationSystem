#pragma once
#include "BasicWidget.h"
#include "Configure.h"
class PushButton : public BassicWidget
{
public:
    PushButton(const std::string& text,int x = 0, int y = 0, int width = 100, int height = 30);
    void show() override;
    bool isin();
    bool isclicked();
    void eventloop(const ExMessage& msg);

    //用于修改按钮背景颜色和鼠标路过时的颜色
    void setBackGroundColor(COLORREF color);
    void setHoverColor(COLORREF color);


private:
    const std::string m_text;
    ExMessage m_msg;

private:
    COLORREF cur_c = RGB(232, 232, 236);
    COLORREF normal_c = RGB(232, 232, 236);
    COLORREF hover_c = RED;
};