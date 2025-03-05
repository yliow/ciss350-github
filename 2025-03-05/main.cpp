#include <iostream>

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

int max(int x, int y)
{
    return (x >= y ? x : y);
}

int height(Node * p)
{
    if (p == NULL)
    {
        std::cout << "base case ... returning -1\n";
        return -1;
    }
    else
    {
        std::cout << "recurisve case ... height at " << p->key_ << '\n';
        int leftheight = height(p->left_);
        int rightheight = height(p->right_);
        std::cout << "height at " << p->key_
                  << " returning " << max(leftheight, rightheight) + 1 << '\n';
        return max(leftheight, rightheight) + 1;
    }
}

/*
         10

     16       5
   2    20  8
             6
   
 */
int main()
{
    Node * p10 = new Node(10);
    Node * p16 = new Node(16, p10); p10->left_ = p16;
    Node * p5 = new Node(5, p10); p10->right_ = p5;
    Node * p2 = new Node(2, p16); p16->left_ = p2;
    Node * p20 = new Node(20, p16); p16->right_ = p20;
    Node * p8 = new Node(8, p5); p5->left_ = p8;
    Node * p6 = new Node(6, p8); p8->right_ = p6;

    std::cout << "*p10:" << (*p10) << '\n';
    std::cout << "*p2:" << (*p2) << '\n';

    std::cout << "height at 10:" << height(p10) << '\n';
    std::cout << "height at 5:" << height(p5) << '\n';
    
    // don't forget to deallocate
    return 0;
}
