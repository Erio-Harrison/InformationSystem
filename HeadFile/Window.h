#pragma once
#include "easyx.h"
#include "Configure.h"
class Window {
public:
    Window(int width, int height, int flag);
    int exec();
    void setWindowTitle(const std::string& title);

    static int width();
    static int height();
    static void clear();
    static void beginDraw();
    static void flushDraw();
    static void endDraw();

    //����������������
    inline static bool hasMsg() { return peekmessage(&m_msg, EX_MOUSE|EX_KEY); };
    inline static const ExMessage& getMsg() { return m_msg; }

private:
    HWND m_handle;					//���ھ��
    inline static ExMessage m_msg;	//�����Ϣ�ͼ�����Ϣ
};