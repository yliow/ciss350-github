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
    Node * p3 = new Node(3, p5);
    p5->left_ = p3;
    Node * p0 = new Node(0, p5);
    p5->right_ = p0;
    Node * p1 = new Node(0, p3);
    p3->right_ = p1;
    Node * p2 = new Node(2, p0);
    p0->left_ = p2;
    Node * p4 = new Node(4, p0);
    p0->right_ = p4;
    Node * p6 = new Node(6, p2);
    p2->left_ = p6;
    
    std::cout << (*p5) << '\n';
    std::cout << (*p3) << '\n';
    std::cout << (*p0) << '\n';
    std::cout << (*p1) << '\n';
    std::cout << (*p2) << '\n';
    std::cout << (*p4) << '\n';
    std::cout << (*p6) << '\n';
    
    return 0;
}
