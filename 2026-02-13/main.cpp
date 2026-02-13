#include <iostream>

class SLNode
{
public:
    SLNode(int key, SLNode * next = NULL)
        : key_(key), next_(next)
    {}
    int key_;
    SLNode * next_;
};

int main()
{
    // 5 -> 3 -> 1 -> 0
    // int x[] = {5,3,1,0}
    SLNode n5(5);
    SLNode n3(3); n5.next_ = &n3;
    SLNode n1(1); n3.next_ = &n1;
    SLNode n0(0); n1.next_ = &n0;
    
    return 0;
}
