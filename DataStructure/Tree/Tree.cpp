#include <iostream>

#include "Set.h"

int main()
{
    auto iniList = { 10,5,1,6,17,14,21 };
    Set s;
    for (int elem : iniList)
        s.insert(elem);
    
    std::cout << s.height()<<"\n";
    std::cout << s.height2()<<"\n";


    s.erase(10);
    
    s.traverseByPreorder();
    std::cout << "\n";
    
    s.traverseByInorder();
    std::cout << "\n";
    
    s.traverseByPostorder();
    std::cout << "\n";


    //Set s;
    //s.insert(10);
    //s.erase(10);
    s.clear();
}