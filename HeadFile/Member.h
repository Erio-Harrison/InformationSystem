#pragma once

#include <string>
#include "Configure.h"
using uint32 = unsigned int;
class Member {
public:
    Member();
    Member(std::string name, std::string nowArea, uint32 incomeLow, uint32 incomeHigh,std::string improveOrNot);
    std::string printData();
public:
    //姓名 现住地区 年收入 是否有改善住房打算
    std::string name;
    std::string nowArea;
    uint32 incomeLow;
    uint32 incomeHigh;
    std::string improveOrNot;
};