#include <string>
#include "Spreadsheet.h"
#include <iostream>

Spreadsheet::Spreadsheet(int row, int collum) {
    this->rows = row;
    this->collums = collum;
    this->m_cells = new Cell*[row];
    for (int i = 0; i < row; ++ i) {
        m_cells[i] = new Cell[collum];
    }
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] m_cells[i];
    }
    delete[] m_cells;
}

void Spreadsheet::setCellAt(int row, int collum, Cell cell){
    this->m_cells[row][collum] = cell;
}

void Spreadsheet::setCellAt(int row, int collum, const std::string& string){
    this->m_cells[row][collum].setValue(string);
}

Cell Spreadsheet::getCellAt(int row, int collum){
    return m_cells[row][collum];
}

void Spreadsheet::addRow(int row) {
    Cell** newCell = new Cell*[this->rows + 1];
    for (int i = 0; i < row; i ++) {
        newCell[i] = m_cells[i];
    }
    newCell[row] = new Cell[collums];
    for (int i = row; i < this->rows; ++i){
        newCell[i + 1] = m_cells[i];
    }
    
    delete[] m_cells;
    m_cells = newCell;
    row++;
}

void Spreadsheet::removeRow(int row) {
    if (row >= 0 && row < this->rows) {
        delete[] m_cells[row];
        for (int i = row; i < this->rows - 1; ++i) {
            m_cells[i] = m_cells[i + 1];
        }
        this->rows --;
    }
}

void Spreadsheet::addCollum(int collum) {
    Cell** newCell = new Cell*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        newCell[i] = new Cell[this->collums + 1];
        for (int j = 0; j < collum; j++) {
            newCell[i][j] = m_cells[i][j];
        }
        for (int j = collum; j < this->collums; j++) {
            newCell[i][j+1] = m_cells[i][j];
        }
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = newCell;
    this->collums ++;
}

void Spreadsheet::removeCollum(int collum) {
    if (collum >= 0 && collum < this->collums) {
        Cell** newCell = new Cell*[this->rows];
        for(int i = 0; i < this->rows; ++i) {
            newCell[i] = new Cell[this->collums - 1];
            for(int j = 0; j < collum; j++){
                newCell[i][j] = m_cells[i][j];
            }
            for(int j = collum + 1; j < this->collums; j++) {
                newCell[i][j - 1] = m_cells[i][j];
            }
            delete[] m_cells[i];
        }
        delete[] m_cells;
        m_cells = newCell;
        this->collums --;
    }
}

void Spreadsheet::swapRows(int firstRow, int secondRow) {
    if(firstRow >= 0 && firstRow < this->rows){
        if(secondRow >= 0 && secondRow < this->rows){
            for (int i = 0; i < this->rows; ++i){
                Cell tmp = m_cells[i][firstRow];
                m_cells[i][firstRow] = m_cells[i][secondRow];
                m_cells[i][secondRow] = tmp;
            }
        }
    }
}

void Spreadsheet::swapCollums(int firstCollum, int secondCollum){
    if(firstCollum >= 0 && firstCollum < this->collums){
        if(secondCollum >= 0 && secondCollum < this->collums){
            Cell* tmp = m_cells[firstCollum];
            m_cells[firstCollum] = m_cells[secondCollum];
            m_cells[secondCollum] = tmp;
        }
    }
}





