#include <iostream>
#include "DLList.h"

int main()
{
    DLNode * n5 = new DLNode(5);
    std::cout << (*n5) << '\n';

    DLList list;
    std::cout << list << '\n';
    
    list.insert_head(3);
    std::cout << list << '\n';
    list.insert_head(5);
    std::cout << list << '\n';
    list.insert_head(-1);
    std::cout << list << '\n';
    list.insert_head(0);
    std::cout << list << '\n';

    std::cout << '\n';
    list.delete_head();
    std::cout << list << '\n';
    
    return 0;
}
