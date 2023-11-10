#include <iostream>

// Node.h
class Node // BinaryTreeNode
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

// class Tree
// {
// public:
//     Node * proot;
// };

void preorder_DF_print(Node * proot)
{
    if (proot == NULL)
    {
        // tree is empty
        std::cout << "* ";
    }
    else
    {
        // tree is nonempty
        // do pre-order DF traversal
        // print root
        // print left subtree
        // print right subtree
        std::cout << proot->key_ << ' ';
        preorder_DF_print(proot->left_);
        preorder_DF_print(proot->right_);
    }    
}

void inorder_DF_print(Node * proot)
{
    if (proot == NULL)
    {
        // tree is empty
        std::cout << "* ";
    }
    else
    {
        // tree is nonempty
        // do in-order DF traversal
        // print left subtree
        // print root
        // print right subtree
        inorder_DF_print(proot->left_);
        std::cout << proot->key_ << ' ';
        inorder_DF_print(proot->right_);
    }    
}

void postorder_DF_print(Node * proot)
{
    if (proot == NULL)
    {
        // tree is empty
        std::cout << "* ";
    }
    else
    {
        // tree is nonempty
        // do post-order DF traversal
        // print left subtree
        // print right subtree
        // print root
        postorder_DF_print(proot->left_);
        postorder_DF_print(proot->right_);
        std::cout << proot->key_ << ' ';
    }    
}

int height(Node * proot)
{
    if (proot == NULL)
    {
        // base case
        std::cout << "base case ... return -1\n";
        return -1;
    }
    else
    {
        // recursive
        int leftheight = height(proot->left_);
        std::cout << "root:" << proot->key_ << " left height:"
                  << leftheight << '\n';
        int rightheight = height(proot->right_);
        std::cout << "root:" << proot->key_ << " right height:"
                  << rightheight << '\n';
        int maxheights = (leftheight >= rightheight ? leftheight : rightheight);
        std::cout << "root:" << proot->key_ << " height:"
                  << maxheights << '\n';

        return maxheights + 1;
    }
}

int max2(int x, int y)
{
    return (x >= y ? x : y);
}
int max(Node * proot)
{
    if (proot == NULL)
    {
        return -1;
    }
    else
    {
        int leftmax = max(proot->left_);
        int rightmax = max(proot->right_);
        return max2(max2(leftmax, rightmax), proot->key_);
    }
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
    Node * p1 = new Node(1, p3);
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

    preorder_DF_print(p5);
    std::cout << '\n';
    inorder_DF_print(p5);
    std::cout << '\n';
    postorder_DF_print(p5);
    std::cout << '\n';

    std::cout << "height at 5: " << height(p5) << '\n';
    // std::cout << "height at 3: " << height(p3) << '\n';
    // std::cout << "height at 1: " << height(p1) << '\n';
    // std::cout << "height at NULL: " << height(NULL) << '\n';
    return 0;
}