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

    //�������
    void insertData(const std::string&data);

    void show();
    void drawTableGrid();
    void drawTableData();

    static std::vector<std::string> split(std::string str, char seperator = '\t');

private:
    int m_rows;
    int m_cols;

    //���ӵĿ�Ⱥ͸߶�
    int m_gridW;
    int m_gridH;

    //������ű�ͷ����Ϣ
    std::string m_header;
    std::vector<std::string> m_datas;
};