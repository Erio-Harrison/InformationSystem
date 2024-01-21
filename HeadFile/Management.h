#pragma once
#include "Configure.h"
#include "Window.h"
#include <vector>
#include "PushButton.h"
#include "Member.h"
#include "Table.h"
#ifndef INFORMATIONMANAGEMENT_MANAGEMENT_H
#define INFORMATIONMANAGEMENT_MANAGEMENT_H


class Management
{
    enum Operator {
        Display,
        Add,
        Delete,
        Search,
        Modify,
        Menu = 66
    };
public:
    Management();
    //begin
    void run();

    int menu();

    //1.Show all objects
    void display();

    //2.Add
    void add();

    //3.Delete
    void erase();

    //4.Modify
    void modify();

    //5.Search
    void search();

    void drawBackGround();
    void eventLoop();

    void readFile(const std::string& filename);
    void saveFile(const std::string& filename);

private:
    IMAGE m_bk;
    ExMessage m_msg;

    std::vector<PushButton*> menu_buttons;
private:
    std::string m_header;
    std::vector<Member> members;
private:
    Table* show_table;
};


#endif //INFORMATIONMANAGEMENT_MANAGEMENT_H