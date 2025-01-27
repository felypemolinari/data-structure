#include <iostream>
//#include "lue.hpp"
#include "lde.hpp"

using namespace std;

// main lue
// int main()
// {
//     LUE<int> list;
//     bootLUE(list);
    
//     insertEndLUE(list, 10);
//     insertEndLUE(list, 20);
//     insertLUE(list, 15);
    
//     displayLUE(list);  // Output: 10 15 20 

//     removeLUE(list, 10);

//     displayLUE(list);
// }

// main lde
int main()
{
    LDE<int> list;
    bootLDE(list);

    insertEndLDE(list, 10);
    insertEndLDE(list, 20);
    insertLDE(list, 15);

    displayLDE(list, 'C'); // Output: 10 15 20
    cout << "\r\n";
    toRemoveLDE(list, 10);

    displayLDE(list, 'C');
}