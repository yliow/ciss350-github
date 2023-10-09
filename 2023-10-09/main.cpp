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


// 5->1->3->0
int main()
{
    SLNode * p5 = new SLNode(5, NULL);

    SLNode * p1 = new SLNode(1, NULL);
    p5->next_ = p1;
    
    SLNode * p3 = new SLNode(3, NULL);
    p1->next_ = p3;
    
    SLNode * p0 = new SLNode(0, NULL);
    p3->next_ = p0;
    
    std::cout << (*p5) << '\n';
    std::cout << (*p1) << '\n';
    std::cout << (*p3) << '\n';
    std::cout << (*p0) << '\n';
    
    return 0;
}
