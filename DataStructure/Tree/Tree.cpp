#include <iostream>

#include "Set.h"

int main()
{
    auto iniList = { 10,5,1,6,17,14,21 };
    Set s;
    for (int elem : iniList)
        s.insert(elem);

    s.traverseByPreorder();
    std::cout << "\n";

    s.traverseByInorder();
    std::cout << "\n";

    s.traverseByPostorder();
    std::cout << "\n";

}