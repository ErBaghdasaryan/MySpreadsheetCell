#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <string>
#include "Cell.h"


class Spreadsheet {
public:
        Spreadsheet(int r, int c);
        ~Spreadsheet();
public:
        void setCellAt(int row, int collum, Cell cell);
        void setCellAt(int row, int collum, const std::string& cell);
        Cell getCellAt(int row, int collum);
        void addRow(int row);
        void removeRow(int row);
        void addCollum(int collum);
        void removeCollum(int collum);
        void swapRows(int firstRow, int secondRow);
        void swapCollums(int firstCollum, int secondCollum);
private:
        Cell** m_cells;
        int rows;
        int collums;

};

#endif // SPREADSHEET_H