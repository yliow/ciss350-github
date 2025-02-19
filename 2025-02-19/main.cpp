/*
array   5, 3, 1, 0
SLList  5->3->1->0
DLList  5<->3<->1<->0
 */
#include <iostream>

class DLNode
{
public:
    DLNode(int key, DLNode * prev=NULL, DLNode * next=NULL)
        : key_(key), prev_(prev), next_(next)
    {}
    int key_;
    DLNode * prev_;
    DLNode * next_;
};
std::ostream & operator<<(std::ostream & cout, const DLNode & node)
{
    cout << "<DLNode " << &node << ' '
         << "key:" << node.key_ << ", "
         << "prev:" << node.prev_ << ", "
         << "next:" << node.next_ << '>';
    return cout;
}

int main()
{
    DLNode * p5 = new DLNode(5);
    std::cout << p5 << '\n';
}
