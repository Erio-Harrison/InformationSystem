#include "Table.h"
#include <iostream>
#include <graphics.h>
#include <algorithm>
Table::Table(int row, int col):
        BassicWidget(0,0,0,0),m_rows(row),m_cols(col)
{

}

void Table::setRowCount(int row)
{
    m_rows = row;
}

void Table::setColCount(int col)
{
    m_cols = col;
}

void Table::setHeader(const std::string& header)
{
    m_header = header;
    m_cols = std::count(m_header.begin(), m_header.end(), '\t')+1;
    m_gridW = ::textwidth("�����ס��");
    m_gridH = ::textheight(m_header.c_str());

}
void Table::insertData(const std::string& data)
{
    m_datas.push_back(data);
}
void Table::show()
{
    drawTableGrid();
    drawTableData();
}

void Table::drawTableGrid()
{
    setlinecolor(BLACK);
    //������
    for (size_t i = 0; i < m_rows + 1; i++) {
        line(m_x, m_y + i * m_gridH, m_x + m_cols * m_gridW, m_y + i * m_gridH);
    }
    //������
    for (size_t i = 0; i < m_cols + 1; i++) {
        line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_rows * m_gridH);
    }
}

void Table::drawTableData()
{
    settextstyle(32, 0, _T("΢���ź�"));

    for (size_t i = 0; i < m_datas.size(); i++) {         //��
        const auto& line_data = split(m_datas[i],'\t');
        for (size_t j = 0; j < line_data.size(); j++) {	  //��
            int dataX = m_x + j * m_gridW;
            int dataY = m_y + i * m_gridH;
            outtextxy(dataX, dataY, line_data[j].c_str());
        }
    }
}

std::vector<std::string> Table::split(std::string str, char seperator)
{
    std::vector<std::string> result;
    for (size_t pos = 0; pos != std::string::npos;) {
        //����ָ���ָ��ַ���λ��
        pos = str.find(seperator);
        //ȡ���ַ�
        auto string_children = str.substr(0, pos);
        //��ʣ�µ��ַ�����str
        str = std::string(str.c_str() + pos + 1);
        result.push_back(string_children);
    }
    return result;
}

