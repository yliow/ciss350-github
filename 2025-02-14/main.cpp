#include <iostream>

class SLNode
{
public:
    SLNode(int key, SLNode * next=NULL)
        : key_(key), next_(next)
    {}
//private:
    int key_;
    SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout, const SLNode & node)
{
    cout << "<SLNode " << &node << ' '
         << "key:" << node.key_ << ", "
         << "next:" << node.next_
         << '>';
    return cout;
}

int main()
{
    SLNode * p5 = new SLNode(5);
    SLNode * p3 = new SLNode(3);
    SLNode * p0 = new SLNode(0);
    SLNode * p1 = new SLNode(1);

    delete p5;
    delete p3;
    delete p0;
    delete p1;
    return 0;
}
