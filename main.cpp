#include <iostream>
#include "management.h"
#include "Window.h"
using namespace std;

int main() {
    Window window(960, 680, EX_SHOWCONSOLE);
    window.setWindowTitle("��Ϣ����ϵͳ");
    Management m;
    m.run();
    return window.exec();
}