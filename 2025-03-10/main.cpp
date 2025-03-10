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

int min(int x, int y)
{
    return (x <= y ? x : y);
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

int sum(Node * p)
{
    if (p == NULL)
    {
        std::cout << "base case ... return 0\n";
        return 0;
    }
    else
    {
        std::cout << "recursive case at " << p->key_ << '\n';
        int sumleft = sum(p->left_);
        std::cout << "recursive case at " << p->key_
                  << " sumleft:" << sumleft << '\n';
        int sumright = sum(p->right_);
        std::cout << "recursive case at " << p->key_
                  << " sumright:" << sumleft << '\n';
        int total = sumleft + sumright + p->key_;
        std::cout << "recursive case at " << p->key_
                  << " total:" << total << '\n';
        return total;
    }
}

Node * find(Node * p, int target)
{
    if (p == NULL) return NULL;
    else
    {
        if (p->key_ == target)
        {
            return p;
        }
        else
        {
            Node * q = find(p->left_, target);
            if (q != NULL) return q;
            else
            {
                return find(p->right_, target);
            }
        }
    }
}

int depth(Node * p, int target)
{
    if (p == NULL)
    {
        std::cout << "depth ... base case return -1\n";
        return -1;
    }
    else
    {
        std::cout << "depth ... recursive case key:" << p->key_ << '\n';
        int leftdepth = depth(p->left_, target);
        std::cout << "depth ... recursive case key:" << p->key_
                  << " leftdepth:" << leftdepth << '\n';
        int rightdepth = depth(p->right_, target);
        std::cout << "depth ... recursive case key:" << p->key_
                  << " rightdepth:" << rightdepth << '\n';
        if (leftdepth == -1)
        {
            if (rightdepth == -1)
            {
                std::cout << "depth ... recursive case key:" << p->key_
                          << " return -1\n";
                return -1;
            }
            else
            {
                std::cout << "depth ... recursive case key:" << p->key_
                          << " return rightdepth + 1:" << rightdepth + 1 << "\n";
                return rightdepth + 1;
            }
        }
        else // target is in left subtree
        {
            if (rightdepth == -1)
            {
                std::cout << "depth ... recursive case key:" << p->key_
                          << " return leftdepth + 1:" << leftdepth + 1 << "\n";
                return leftdepth + 1;
            }
            else // target in left and right subtree
            {
                std::cout << "depth ... recursive case key:" << p->key_
                          << " return min + 1:"
                          << min(leftdepth, rightdepth) + 1 << "\n";
                return min(leftdepth, rightdepth) + 1;
            }
        }
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

    // std::cout << "*p10:" << (*p10) << '\n';
    // std::cout << "*p2:" << (*p2) << '\n';

    // std::cout << "height at 10:" << height(p10) << '\n';
    // std::cout << "height at 5:" << height(p5) << '\n';

    int s = sum(p10);
    std::cout << "sum at 10: " << s << '\n';

    std::cout << "\n\n";
    
    s = sum(p16);
    std::cout << "sum at 16: " << s << '\n';

    std::cout << "find 8 at 10 ...\n";
    Node * p = find(p10, 8);
    std::cout << (*p8) << '\n';
    std::cout << p << '\n';

    int depth8 = depth(p10, 8);
    std::cout << "depth of 8 (from root 10): " << depth8 << '\n';
    
    // don't forget to deallocate
    return 0;
}
