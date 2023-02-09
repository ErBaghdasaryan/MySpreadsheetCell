#include <string>
#include "Date.h"
#ifndef CELL_H
#define CELL_H

class Cell {
public: 
        Cell() = default;
        ~Cell() = default;
public:
        void setValue(const std::string& value);
        std::string getValue();
        int toInt() const;
        double toDouble() const;
        Date toDate();
        void reset();
private:
        std::string m_value;

};

#endif  // CELL_H