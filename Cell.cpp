#include "Cell.h"
#include <sstream>
#include "Date.h"


void Cell::setValue(const std::string& str){
    this->m_value = str;
}

std::string Cell::getValue(){
    return this->m_value;
}

int Cell::toInt() const{
    int result;
    std::istringstream(m_value) >> result;
    return result;
}

double Cell::toDouble() const{
    double result;
    std::istringstream(this->m_value) >> result;
    return result;
}

Date Cell::toDate() {
    Date result = Date::from_string(m_value);
}

void Cell::reset() {
    this->m_value = "";
}
