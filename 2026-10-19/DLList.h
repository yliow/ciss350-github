#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>

class DLNode
{
  public:
    DLNode(int, DLNode * = NULL, DLNode * = NULL);
    int key_;
    DLNode * prev_;
    DLNode * next_;
};

std::ostream & operator<<(std::ostream &, const DLNode &);

class DLList
{
  public:
    DLList();
    void insert_head(key);
    void delete_head();
    phead
};

std::ostream & operator<<(std::ostream &, const DLList &);

#endif
