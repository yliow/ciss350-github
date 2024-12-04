#include <iostream>
#include <unordered_set>

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

std::ostream & operator<<(std::ostream & cout, const Node & n)
{
    cout << "<Node " << &n << ' '
         << "key:" << n.key_ << ", "
         << "left:" << n.left_ << ", "
         << "right:" << n.right_ << '>';
    return cout;
}

int main()
{
    /*
            +---------+
            |         |
            v         |
            0 -> 1 -> 2
            |
            v
            3

            4 -> 5
     */

    Node * p0 = new Node(0);
    Node * p1 = new Node(1);
    Node * p2 = new Node(2);
    Node * p3 = new Node(3);
    p0->left_ = p3; p0->right_ = p1;
    p1->left_ = p2;
    p2->right_ = p0;
    std::cout << "*p0: " << (*p0) << '\n';
    std::cout << "*p1: " << (*p1) << '\n';
    std::cout << "*p2: " << (*p2) << '\n';
    std::cout << "*p3: " << (*p3) << '\n';

    std::unordered_set< int > TODO;
    for (int i = 0; i < 4; ++i)
    {
        TODO.insert(i);
    }

    for (auto i: TODO)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
