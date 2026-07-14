#include "table.h"

#include <iostream>

int main() {
    Table<int> table(2, 3);
   
    table[0][0] = 1;
    table[0][1] = 2;
    table[0][2] = 3;
    table[1][0] = 4;
    table[1][1] = 5;
    table[1][2] = 6;

    std::cout << "table[0][1] = " << table[0][1] << std::endl; 
    std::cout << "table[1][2] = " << table[1][2] << std::endl; 

    auto [rows, cols] = table.Size();
    std::cout << "Size: " << rows << "x" << cols << std::endl;

    const Table<int>& const_table = table;
    std::cout << "const_table[0][0] = " << const_table[0][0] << std::endl; 

    return 0;
}