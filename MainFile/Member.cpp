#include "Member.h"
#include "sstream"
Member::Member()
{
}

Member::Member(std::string name, std::string nowArea, uint32 incomeLow, uint32 incomeHight,std::string improveOrNot)
        :name(name),nowArea(nowArea),incomeLow(incomeLow), incomeHigh(incomeHigh),improveOrNot(improveOrNot)
{

}

std::string Member::printData()
{
    std::stringstream ss;
    ss << name << "\t" << nowArea  << "\t" << incomeLow << "\t" << incomeHigh  << "\t" << improveOrNot<<std::endl;
    return ss.str();
}
