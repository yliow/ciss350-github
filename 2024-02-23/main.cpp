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
         << "key:" << n.key_ << ' '
         << "next:" << n.next_ 
         << ">";
    return cout;
}

class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}
    void insert_head(int key)
    {
        phead_ = new SLNode(key, phead_);
    }
    SLNode * phead_;
};
std::ostream & operator<<(std::ostream & cout,
                          const SLList & list)
{
    cout << "<SLList " << &list << '\n';
    SLNode * p = list.phead_;
    while (p != NULL)
    {
        cout << "    " << (*p) << '\n';
        p = p->next_;
    }
    cout << ">";
    return cout;
}

// 5 -> 3 -> 0 -> 2
int main()
{
    SLNode n5(5);
    SLNode n3(3);
    SLNode n0(0);
    SLNode n2(2);
    n0.next_ = &n2;
    n3.next_ = &n0;
    n5.next_ = &n3;
    
    // std::cout << n5 << '\n';
    // std::cout << n3 << '\n';
    // std::cout << n0 << '\n';
    // std::cout << n2 << '\n';

    SLNode * phead = &n5;

    SLNode * p = phead;
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        p = p->next_;
    }
    
    // phead = &n5
    // SLList list // list.phead_
    SLList list;
    std::cout << list << '\n';
    list.insert_head(2);
    std::cout << list << '\n';
    list.insert_head(0);
    std::cout << list << '\n';
    list.insert_head(3);
    std::cout << list << '\n';
    list.insert_head(5);
    std::cout << list << '\n';
    
    return 0;
}
