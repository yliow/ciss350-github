#include <iostream>
#include "DLList.h"

int main()
{
    DLNode * n5 = new DLNode(5);
    std::cout << (*n5) << '\n';

    DLList list;
    list.insert_head(3);
    std::cout << list << '\n';
    return 0;
}
