
#include "management.h"
#include "Window.h"


using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Window window(960, 680, EX_SHOWCONSOLE);
    window.setWindowTitle("信息管理系统");
    Management m;
    m.run();
    return window.exec();
}