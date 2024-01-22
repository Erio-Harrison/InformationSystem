#include "Table.h"
#include <iostream>
#include <algorithm>
Table::Table(int row, int col):
        BassicWidget(0,0,0,0),m_rows(row),m_cols(col),current_page(0),
        total_page(0),other_data(0)
{
    prev_button =  new PushButton("��һҳ");
    next_button =  new PushButton("��һҳ");;
    first_button =  new PushButton("��һҳ");;
    end_button =  new PushButton("��βҳ");;
}
Table::~Table() {
    delete prev_button;
    delete next_button;
    delete first_button;
    delete end_button;
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

    //���ֿ�Ⱥ͸߶�
    word_Width = ::textwidth("�Ƿ��и���ס������");
    word_Height = ::textheight(m_header.c_str());
    //���������Կ�
    m_gridW = word_Width+10;
    m_gridH = word_Height+10;

    //����ܿ�Ⱥ��ܸ߶ȣ������ò��ϣ���ֹ�Ժ���չ��Ҫ
    m_width = m_gridW*m_cols;
    m_height = m_gridH*m_rows;

}
void Table::insertData(const std::string& data)
{
    m_datas.push_back(data);
    updateTable();
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
    if(total_page>0){
        drawButton();
    }
}

void Table::drawTableData()
{
    //���ݲ�������һҳ��ʱ��
    if(m_rows>m_datas.size() && !m_datas.empty()){
        m_rows = m_datas.size();
    }

    settextstyle(32, 0, _T("΢���ź�"));

    int beginPos = current_page*m_rows;
    int endPos = beginPos + m_rows;

    if(current_page == total_page){
        endPos = beginPos + other_data;
    }

    for (size_t i = beginPos, r = 0; i < endPos; r++,i++) {         //��
        const auto& line_data = split(m_datas[i],'\t');
        for (size_t j = 0; j < line_data.size(); j++) {	  //��


            int dataX = m_x + j * m_gridW +(m_gridW-::textwidth(line_data[j].c_str()))/2;
            int dataY = m_y + r * m_gridH +5;
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

void Table::updateTable() {
    if(m_rows>=m_datas.size()){
        total_page = 0;
        other_data = m_datas.size();
    }else{
        total_page = m_datas.size()/m_rows;
        other_data = m_datas.size()%m_rows;
    }

}

void Table::drawButton() {
    prev_button->move(m_x,m_height + 75);
    next_button->move(prev_button->x()+prev_button->width(),prev_button->y());
    first_button->move(next_button->x()+next_button->width(),next_button->y());
    end_button->move(first_button->x()+first_button->width(),first_button->y());

    prev_button ->show();
    next_button ->show();
    first_button ->show();
    end_button ->show();

    char str[30] = {0};
    sprintf_s(str,"��%dҳ / ��%dҳ",current_page+1,total_page+1);
    outtextxy(end_button->x() + end_button->width() +100,end_button->y(),str);
}

void Table::handleButton(const ExMessage &msg) {
    prev_button ->eventloop(msg);
    next_button ->eventloop(msg);
    first_button ->eventloop(msg);
    end_button ->eventloop(msg);

    if(prev_button->isclicked()){
        if(current_page!=0){
            current_page--;
        }
    }
    if(next_button->isclicked()){
        if(current_page!=total_page){
            current_page++;
        }
    }
    if(first_button->isclicked()){
        current_page =0;
    }
    if(end_button->isclicked()){
        current_page = total_page;
    }

}

