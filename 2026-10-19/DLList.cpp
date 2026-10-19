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
