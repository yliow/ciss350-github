#include <iostream>

// file: SLNode.h
class SLNode
{
public:
    SLNode(int key, SLNode * next)
        : key_(key), next_(next)
    {}
    int key_;
    SLNode * next_;
private: // not used
};

std::ostream & operator<<(std::ostream & cout, const SLNode & n)
{
    cout << "<SLNode " << &n << " key:" << n.key_ << ", next:" << n.next_ << '>';
    return cout;
}


int main()
{
    SLNode * p = new SLNode(5, NULL);
    std::cout << (*p) << '\n';
    return 0;
}
