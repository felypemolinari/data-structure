#include <iostream>
#include "lue.hpp"

using namespace std;

int main()
{
    LUE<int> list;
    bootLUE(list);
    
    insertEndLUE(list, 10);
    insertEndLUE(list, 20);
    insertLUE(list, 15);
    
    displayLUE(list);  // Output: 10 15 20 

    removeLUE(list, 10);

    displayLUE(list);
}