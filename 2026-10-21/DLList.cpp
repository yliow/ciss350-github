#include <iostream>
#include "DLList.h"

DLNode::DLNode(int key, DLNode * prev, DLNode * next)
    : key_(key), prev_(prev), next_(next)
{}

std::ostream & operator<<(std::ostream & cout, const DLNode & node)
{
    std::cout << "<DLNode " << &node << ' '
              << "key:" << node.key_ << ", "
              << "prev:" << node.prev_ << ", "
              << "next:" << node.next_ << '>';
    return cout;
}

DLList::DLList()
    : pheadsentinel_(new DLNode(-9999)), ptailsentinel_(new DLNode(+9999))
{
    pheadsentinel_->next_ = ptailsentinel_;
    ptailsentinel_->prev_ = pheadsentinel_;
}

void DLList::insert_head(int key)
{
    DLNode * p = pheadsentinel_;
    DLNode * q = new DLNode(key);
    DLNode * r = pheadsentinel_->next_;
    p->next_ = q;
    q->next_ = r;
    r->prev_ = q;
    q->prev_ = p;
}

void DLList::delete_head()
{
    DLNode * p = pheadsentinel_;
    DLNode * q = p->next_;
    DLNode * r = q->next_;
    p->next_ = r;
    r->prev_ = p;
    delete q;
}

std::ostream & operator<<(std::ostream & cout, const DLList & list)
{
    cout << "<DList " << &list << '\n';
    DLNode * p = list.pheadsentinel_->next_;
    while (p != list.ptailsentinel_)
    {
        cout << "  " << (*p) << '\n';
        p = p->next_;
    }
    cout << '>';
    return cout;
}
