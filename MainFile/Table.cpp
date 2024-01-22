#include "Table.h"
#include <iostream>
#include <algorithm>
Table::Table(int row, int col):
        BassicWidget(0,0,0,0),m_rows(row),m_cols(col),current_page(0),
        total_page(0),other_data(0)
{
    prev_button =  new PushButton("上一页");
    next_button =  new PushButton("下一页");;
    first_button =  new PushButton("第一页");;
    end_button =  new PushButton("结尾页");;
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

    //文字宽度和高度
    word_Width = ::textwidth("是否有改善住房需求");
    word_Height = ::textheight(m_header.c_str());
    //表格比文字略宽
    m_gridW = word_Width+10;
    m_gridH = word_Height+10;

    //表格总宽度和总高度，可能用不上，防止以后扩展需要
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
    //画横线
    for (size_t i = 0; i < m_rows + 1; i++) {
        line(m_x, m_y + i * m_gridH, m_x + m_cols * m_gridW, m_y + i * m_gridH);
    }
    //画竖线
    for (size_t i = 0; i < m_cols + 1; i++) {
        line(m_x + i * m_gridW, m_y, m_x + i * m_gridW, m_y + m_rows * m_gridH);
    }
    if(total_page>0){
        drawButton();
    }
}

void Table::drawTableData()
{
    //数据不足整整一页的时候
    if(m_rows>m_datas.size() && !m_datas.empty()){
        m_rows = m_datas.size();
    }

    settextstyle(32, 0, _T("微软雅黑"));

    int beginPos = current_page*m_rows;
    int endPos = beginPos + m_rows;

    if(current_page == total_page){
        endPos = beginPos + other_data;
    }

    for (size_t i = beginPos, r = 0; i < endPos; r++,i++) {         //行
        const auto& line_data = split(m_datas[i],'\t');
        for (size_t j = 0; j < line_data.size(); j++) {	  //列


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
        //查找指定分割字符的位置
        pos = str.find(seperator);
        //取出字符
        auto string_children = str.substr(0, pos);
        //把剩下的字符传给str
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
    sprintf_s(str,"第%d页 / 共%d页",current_page+1,total_page+1);
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

