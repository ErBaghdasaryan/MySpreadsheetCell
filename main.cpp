#include <iostream>
#include <string>
#include "Cell.h"
#include "Date.h"
#include "Spreadsheet.h"

int main() {
   Cell obj;
   Spreadsheet spreadsheet(5, 8);
   spreadsheet.setCellAt(3, 4, obj);
   obj.toDate();
   Date date(11, 11, 2001);
   obj.setValue("19.11.2001");

}

