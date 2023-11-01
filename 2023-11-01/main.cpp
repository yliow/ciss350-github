#include <iostream>

// Node.h
class Node
{
public:
    Node(int key, Node * parent=NULL, Node * left=NULL, Node * right=NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    int key_;
    Node * parent_;
    Node * left_;
    Node * right_;
};

std::ostream & operator<<(std::ostream & cout, const Node & n)
{
    cout << "<Node " << &n
         << " key:" << n.key_
         << " parent:" << n.parent_
         << " left:" << n.left_
         << " right:" << n.right_
         << '>';
    return cout;
}

//          5
//     3        0
//       1    2   4
//           6
//
int main()
{
    Node * p5 = new Node(5);
    return 0;
}
