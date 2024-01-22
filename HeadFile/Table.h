#pragma once
#include "BasicWidget.h"
#include "Configure.h"
#include <vector>
#include"easyx.h"
class Table : public BassicWidget
{
public:
    Table(int row = 0, int col = 0);
    void setRowCount(int row);
    void setColCount(int col);
    void setHeader(const std::string& header);

    //添加数据
    void insertData(const std::string&data);

    void show();
    void drawTableGrid();
    void drawTableData();

    static std::vector<std::string> split(std::string str, char seperator = '\t');

private:
    int m_rows;
    int m_cols;

    //格子的宽度和高度
    int m_gridW;
    int m_gridH;

    //格子里放表头和信息
    std::string m_header;
    std::vector<std::string> m_datas;
};