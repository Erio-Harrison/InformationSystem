#include "../HeadFile/Window.h"
#include "Configure.h"
Window::Window(int width, int height, int flag)
{
    m_handle = ::initgraph(width, height, flag);
    ::setbkmode(TRANSPARENT);
}

int Window::exec()
{
    return getchar();
}

void Window::setWindowTitle(const std::string& title)
{
    ::SetWindowText(m_handle, title.c_str());
}

int Window::width()
{
    return ::getwidth();
}

int Window::height()
{
    return ::getheight();
}

void Window::clear()
{
    ::cleardevice();
}

void Window::beginDraw()
{
    ::BeginBatchDraw();
}

void Window::flushDraw()
{
    ::FlushBatchDraw();
}

void Window::endDraw()
{
    ::EndBatchDraw();
}
