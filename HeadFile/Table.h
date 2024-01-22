#pragma once
#include "BasicWidget.h"
#include "Configure.h"
#include <vector>
#include"easyx.h"
#include "PushButton.h"
class Table : public BassicWidget
{
public:
    Table(int row = 0, int col = 0);
    ~Table();
    void setRowCount(int row);
    void setColCount(int col);
    void setHeader(const std::string& header);

    //添加数据
    void insertData(const std::string&data);

    void show();
    void drawTableGrid();
    void drawTableData();
    void drawButton();
    static std::vector<std::string> split(std::string str, char seperator = '\t');
    void updateTable();

    void handleButton(const ExMessage& msg);

private:
    int m_rows;
    int m_cols;

    //格子的宽度和高度
    int m_gridW;
    int m_gridH;

    //文字的宽度和高度
    int word_Width;
    int word_Height;

    //格子里放表头和信息
    std::string m_header;
    std::vector<std::string> m_datas;
private:
    //分页时候用
    int current_page;
    int total_page;
    int other_data;

    PushButton* prev_button;
    PushButton* next_button;
    PushButton* first_button;
    PushButton* end_button;
};