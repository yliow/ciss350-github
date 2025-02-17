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

class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}
//private:
    SLNode * phead_;
};
std::ostream & operator<<(std::ostream & cout, const SLList &  list)
{
    SLNode * p = list.phead_;
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        p = p->next_;
    }
    return cout;
}

int main()
{
    SLNode * p5 = new SLNode(5);
    SLNode * p3 = new SLNode(3);
    SLNode * p0 = new SLNode(0);
    SLNode * p1 = new SLNode(1);

    // std::cout << (*p5) << '\n';
    // std::cout << (*p3) << '\n';
    // std::cout << (*p0) << '\n';
    // std::cout << (*p1) << '\n';

    p5->next_ = p3;
    p3->next_ = p0;
    p0->next_ = p1;
    // std::cout << (*p5) << '\n';
    // std::cout << (*p3) << '\n';
    // std::cout << (*p0) << '\n';
    // std::cout << (*p1) << '\n';

    SLNode * phead = p5;

    // print the list with phead
    SLNode * p = phead;
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        // ---------
        p = p->next_;
    }
    
    delete p5;
    delete p3;
    delete p0;
    delete p1;


    SLList list;
    // list.add(5)
    std::cout << list << '\n';
    return 0;
}
