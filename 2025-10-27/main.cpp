#include <iostream>

/*

                   11

          3                  20

      7      9           1

                11
 */

class Node
{
public:
    Node(int key, Node * left=NULL, Node * right=NULL)
        : key_(key), left_(left), right_(right)
    {}
    int key_;
    Node * left_;
    Node * right_;
};

std::ostream & operator<<(std::ostream & cout, const Node & node)
{
    cout << "<Node " << &node << ' '
         << "key:" << node.key_ << ", "
         << "left:" << node.left_ << ", "
         << "right:" << node.right_ << '>';
    return cout;
}

int main()
{
    Node * n11 = new Node(11);
    std::cout << (*n11) << '\n';
    return 0;
}
