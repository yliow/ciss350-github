#include <iostream>

class Node
{
public:
    Node(int key,
         Node * parent=NULL,
         Node * left=NULL, Node * right=NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    int key_;
    Node * parent_;
    Node * left_;
    Node * right_;
};
std::ostream & operator<<(std::ostream & cout, const Node & n)
{
    cout << "<Node " << &n << ' '
         << "key:" << n.key_ << ", "
         << "parent:" << n.parent_ << ", "
         << "left:" << n.left_ << ", "
         << "right:" << n.right_ 
         << '>';
    return cout;
}

/*
             10

       20           8


    2           11

               1   6
 */

void preorder_print(Node * proot)
{
    if (proot == NULL)
    {
        std::cout << "* ";
    }
    else
    {
        std::cout << proot->key_ << ' ';
        preorder_print(proot->left_);
        preorder_print(proot->right_);
    }
}

int main()
{
    Node * p10 = new Node(10);
    Node * p20 = new Node(20);
    Node * p8 = new Node(8);
    Node * p2 = new Node(2);
    Node * p11 = new Node(11);
    Node * p1 = new Node(1);
    Node * p6 = new Node(6);
    p10->left_ = p20; p10->right_ = p8;
    p20->parent_ = p10; p20->left_ = p2;
    p8->parent_ = p10; p8->left_ = p11;
    p2->parent_ = p20;
    p11->parent_ = p8; p11->left_ = p1; p11->right_ = p6;
    p1->parent_ = p11;
    p6->parent_ = p11;
    std::cout << (*p10) << '\n';
    std::cout << (*p20) << '\n';
    std::cout << (*p8) << '\n';
    std::cout << (*p2) << '\n';
    std::cout << (*p11) << '\n';
    std::cout << (*p1) << '\n';
    std::cout << (*p6) << '\n';

    Node * proot = p10;

    std::cout << "preorder at p10 ... "; preorder_print(p10); std::cout << '\n';
        
    return 0;
}
