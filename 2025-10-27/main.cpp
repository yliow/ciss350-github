#include <iostream>

/*

                   11

          3                  20

      7      9           1

                12
 */

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

std::ostream & operator<<(std::ostream & cout, const Node & node)
{
    cout << "<Node " << &node << ' '
         << "key:" << node.key_ << ", "
         << "parent:" << node.parent_ << ", "
         << "left:" << node.left_ << ", "
         << "right:" << node.right_ << '>';
    return cout;
}

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
    Node * n11 = new Node(11);
    Node * n3 = new Node(3); n3->parent_ = n11; n11->left_ = n3;
    Node * n20 = new Node(20); n20->parent_ = n11; n11->right_ = n20;
    Node * n7 = new Node(7); n7->parent_ = n3; n3->left_ = n7;
    Node * n9 = new Node(9); n9->parent_ = n3; n3->right_ = n9;
    Node * n1 = new Node(1); n1->parent_ = n20; n20->left_ = n1;
    Node * n12 = new Node(12); n12->parent_ = n9; n9->right_ = n12;
    
    std::cout << (*n11) << '\n';
    std::cout << (*n3) << '\n';
    std::cout << (*n20) << '\n';
    std::cout << (*n7) << '\n';
    std::cout << (*n9) << '\n';
    std::cout << (*n1) << '\n';
    std::cout << (*n12) << '\n';

    Node * proot = n11;

    preorder_print(proot); std::cout << '\n';
    
    return 0;
}
