/*
array   5, 3, 1, 0
SLList  5->3->1->0
DLList  5<->3<->1<->0
        ^           ^
        |           |
        phead       ptail
DLList  ?<->5<->3<->1<->0<->?
        ^   head            ^
        |                   |
        pheadsentinel       ptailsentinel
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


class DLList
{
public:
    // initially
    // headsentinel       tailsentinel
    // ?<---------------->?
    // ^                  ^
    // |                  |
    // pheadsentinel_     ptailsentinel_
    DLList()
        : pheadsentinel_(new DLNode(-9999)),
          ptailsentinel_(new DLNode(9999))
    {
        pheadsentinel_->next_ = ptailsentinel_;
        ptailsentinel_->prev_ = pheadsentinel_;
    }
    // TOOD: ~DLList();
    //       DLList(const DLList &);
    //       DLList & operator=(const DLList &);
    void insert_head(int key)
    {
        /*
                 insert 42 into
                 ? <-----> 5 <----> 3 <-----> ......
                 phs
         */
        DLNode * p = pheadsentinel_;
        DLNode * r = pheadsentinel_->next_;
        DLNode * q = new DLNode(key, p, r);
        r->prev_ = q;
        p->next_ = q;
    }
    void delete_head()
    {
        if (pheadsentinel_->next_ != ptailsentinel_)
        {
            DLNode * p = pheadsentinel_;
            DLNode * q = p->next_;
            DLNode * r = q->next_;
            r->prev_ = p;
            p->next_ = r;
            delete q;
        }
        else
        {
            // maybe underflow exception??
        }
    }
    DLNode * pheadsentinel_;
    DLNode * ptailsentinel_;
};
std::ostream & operator<<(std::ostream & cout, const DLList & list)
{
    DLNode * p = list.pheadsentinel_->next_;
    cout << "<DLList " << &list << ' ' 
         << "pheadsentinel:" << list.pheadsentinel_ << ' '
         << "ptailsentinel:" << list.ptailsentinel_ << '\n';
    while (p != list.ptailsentinel_)
    {
        cout << "    " << (*p) << "\n";
        p = p->next_;
    }
    cout << '>';
    return cout;
}

int main()
{
    // DLNode * p5 = new DLNode(5);
    // std::cout << (*p5) << '\n';

    DLList list;
    std::cout << list << '\n';

    list.insert_head(1);
    std::cout << list << '\n';
    list.insert_head(0);
    std::cout << list << '\n';
    list.insert_head(3);
    std::cout << list << '\n';
    list.insert_head(5);
    std::cout << list << '\n';

    list.delete_head();
    std::cout << list << '\n';
    
    return 0;
}
