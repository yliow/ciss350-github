#include <iostream>

// file: SLNode.h (SL = singly-linked)
class SLNode
{
public:
    SLNode(int key, SLNode * next)
        : key_(key), next_(next)
    {}
    // int key() const
    // {
    //     return key_;
    // }
    int key_;
    SLNode * next_;
private: // not used
};

std::ostream & operator<<(std::ostream & cout, const SLNode & n)
{
    cout << "<SLNode " << &n << " key:" << n.key_ << ", next:" << n.next_ << '>';
    return cout;
}


// file: SLList.h and SLList.cpp
class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}
    void insert_head(int key)
    {
    }
    SLNode * phead_;
};

std::ostream & operator<<(std::ostream & cout, const SLList & list)
{
    cout << "<SLList " << &list << ' ';
    SLNode * p = list.phead_;
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        p = p->next_;
    }
    cout << '>';
    return cout;
}

void print_list(SLNode * p)
{
    std::cout << "print_list ... \n";
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        p = p->next_;
    }
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
    
    // std::cout << (*p5) << '\n';
    // std::cout << (*p1) << '\n';
    // std::cout << (*p3) << '\n';
    // std::cout << (*p0) << '\n';

    print_list(p5);

    SLList list;
    std::cout << list << '\n';

    std::cout << "inserting head with 1 ...\n";
    list.insert_head(1);
    std::cout << list << '\n';

    return 0;
}
