#include "../HeadFile/BasicWidget.h"

BassicWidget::BassicWidget(int x, int y, int width, int height):m_x(x),m_y(y),m_width(width),m_height(height)
{
}

int BassicWidget::width()
{
    return m_width;
}

int BassicWidget::height()
{
    return m_height;
}

void BassicWidget::sizeFix(int width, int height)
{
    this->m_width = width;
    this->m_height = height;
}

int BassicWidget::x()
{
    return m_x;
}

int BassicWidget::y()
{
    return m_y;
}

void BassicWidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}
