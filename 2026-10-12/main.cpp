#include <iostream>

class SLNode
{
public:
    SLNode(int key, SLNode * next=NULL)
        : key_(key), next_(next)
    {}
    int key_;
    SLNode * next_;
};

int main()
{
    SLNode n5 = new SLNode(5);
    SLNode n3 = new SLNode(3); n5->next_ = n3;
    SLNode n1 = new SLNode(1); n3->next_ = n1;
    SLNode n0 = new SLNode(0); n1->next_ = n0;
    
    return 0;
}
