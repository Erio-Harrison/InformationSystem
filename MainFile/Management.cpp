
#include "Management.h"
#include <iostream>
#include <conio.h>
#include "../HeadFile/Window.h"
#include <fstream>
#include <sstream>
using namespace std;
Management::Management()
{
    readFile("./images/member.txt");
    ::loadimage(&m_bk, "./images/BingWallpaper.jpg", Window::width(), Window::height());
    ::settextstyle(24, 0, "΢���ź�");

    //�����水ť��ʼ��
    menu_buttons.push_back(new PushButton("�鿴�ͻ�"));
    menu_buttons.push_back(new PushButton("��ӿͻ�"));
    menu_buttons.push_back(new PushButton("ɾ���ͻ�"));
    menu_buttons.push_back(new PushButton("�޸Ŀͻ�"));
    menu_buttons.push_back(new PushButton("���ҿͻ�"));
    menu_buttons.push_back(new PushButton("�˳�ϵͳ"));
    for (int i = 0; i < menu_buttons.size(); i++) {
        menu_buttons[i]->sizeFix(250, 50);
        int buttonX = (Window::width() - menu_buttons[i]->width()) / 2;
        int verSpace = (Window::height() - menu_buttons.size() * menu_buttons[i]->height()) / 2;
        int buttonY = verSpace + i * menu_buttons[i]->height();
        menu_buttons[i]->move(buttonX, buttonY);
    }

    //�鿴���
    show_table = new Table;
    show_table->setRowCount(16);
    show_table->setHeader(m_header);

    for (auto& member : members) {
        show_table->insertData(member.printData());
    }
    //�ñ�����
    show_table->move((Window::width()-show_table->width())/2, (Window::height()-show_table->height())/2);

}
//begin
void Management::run() {
    //Get the value from menu
    int op = Menu;
    Window::beginDraw();
    while (true) {
        Window::clear();
        drawBackGround();

        if (Window::hasMsg()) {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
                //��Esc����������
                case WM_KEYDOWN:
                    if (m_msg.vkcode == VK_ESCAPE) {
                        op = Menu;
                    }
                    break;
                default:
                    eventLoop();
                    break;
            }
        }

        switch (op)
        {
            case Menu:
                op = menu();
                break;
            case Management::Display:
                display();
                break;
            case Management::Add:
                add();
                break;
            case Management::Delete:
                erase();
                break;
            case Management::Search:
                search();
                break;
            case Management::Modify:
                modify();
                break;

            default:
                saveFile("./images/test.txt");
                exit(666);
                break;
        }
        Window::flushDraw();
    }
    Window::endDraw();

}

int Management::menu() {
    for (int i = 0; i < menu_buttons.size(); i++) {
        menu_buttons[i]->show();
        menu_buttons[i]->eventloop(m_msg);
        if (menu_buttons[i]->isclicked()) {
            return i;
        }
    }
    return Menu;
}

//1.Show all objects
void Management::display() {
    show_table->show();
}

//2.Add
void Management::add() {
    outtextxy(0, 0, "add");
    cout << "add" << endl;
}

//3.Delete
void Management::erase() {
    outtextxy(0, 0, "erase");
    cout << "erase" << endl;
}

//4.Modify
void Management::modify() {
    outtextxy(0, 0, "modify");
    cout << "modify" << endl;
}

//5.Search
void Management::search() {
    outtextxy(0, 0, "search");
    cout << "search" << endl;
}

void Management::drawBackGround()
{
    ::putimage(0, 0, &m_bk);
}

void Management::eventLoop()
{
    show_table ->handleButton(m_msg);
}

void Management::readFile(const std::string& filename) {
    std::ifstream read(filename);
    if (!read.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // ��ȡ��һ�еı�ͷ
    std::getline(read, m_header);

    // ��ȡ����
    std::string line;
    while (std::getline(read, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream ss(line);
        Member member;
        if (ss >> member.name >> member.nowArea >> member.incomeLow >> member.incomeHigh >> member.improveOrNot) {
            members.push_back(member);
        }
    }
}


void Management::saveFile(const std::string& filename)
{
    fstream write("F:/repo/InformationSystem/images/test.txt", ios::out | ios::trunc);
    if (!write.is_open()) {
        cerr << filename << "open failed" << endl;
        return;
    }
    cout << "File opened successfully." << endl;
    //д��һ�еı�ͷ
    m_header += "\n";
    write.write(m_header.c_str(), m_header.size());
    //д����
    if (members.empty()) {
        cout << "No members to write." << endl;
    } else {
        cout << "Writing members data..." << endl;
        for (auto& member : members) {
            std::string information = member.printData();
            write.write(information.c_str(), information.size());
        }
    }
    write.close();
}
