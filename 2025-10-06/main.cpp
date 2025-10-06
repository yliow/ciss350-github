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

std::ostream & operator<<(std::ostream & cout, const SLNode & n)
{
    cout << "<SLNode " << &n << ' '
         << "key:" << n.key_ << ", "
         << "next:" << n.next_ << '>';
    return cout;
}

int main()
{
    SLNode n5(5);
    std::cout << n5 << '\n';
    return 0;
}
