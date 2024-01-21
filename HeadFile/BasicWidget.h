#pragma once
class BassicWidget {
public:
    BassicWidget(int x, int y, int width, int height);
    int width();
    int height();
    void sizeFix(int width, int height);

    int x();
    int y();
    void move(int x, int y);

    virtual void show() = 0;

protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};