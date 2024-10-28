#include <iostream>

class Node
{
public:
    Node(int key, Node * parent=NULL, Node * left=NULL, Node * right=NULL)
        : key_(key), parent_(parent), left_(left), right_(right)
    {}
    int key_;
    Node * parent_;
    Node * left_, * right_; // k-ary: Node * children[10];
};

std::ostream & operator<<(std::ostream & cout, const Node & n)
{
    cout << "<Node " << &n << ' '
         << "key:" << n.key_ << ' '
         << "parent:" << n.parent_ << ' '
         << "left:" << n.left_ << ' '
         << "right:" << n.right_
         << '>';
    return cout;
}

void insert_left(Node *& p, Node *& c)
{
    p->left_ = c;
    c->parent_ = p;
}
void insert_right(Node *& p, Node *& c)
{
    p->right_ = c;
    c->parent_ = p;
}

void preorder_df_print(Node * proot)
{
    if (proot == NULL)
    {
        std::cout << "* ";
    }
    else
    {
        std::cout << proot->key_ << ' ';
        preorder_df_print(proot->left_);
        preorder_df_print(proot->right_);
    }
}

void inorder_df_print(Node * proot)
{
    if (proot == NULL)
    {
        std::cout << "* ";
    }
    else
    {
        preorder_df_print(proot->left_);
        std::cout << proot->key_ << ' ';
        preorder_df_print(proot->right_);
    }
}

// you can also use a stack and then use iteration
/*

  preorder_df_using_stack(Node * proot): (preorder df with iteration)

  let stk = stack (use std::stack)
  push proot into stk
  while stk is not empty:
     p = pop stk

     if p is NULL then
         special handing for empty tree
     else:
         ...... do something with node *p ...
         push p->right and p->left into stk


  if you change stk (a stack) to a queue, you get BF traversal
  of course change "push"/"pop" to enquue/dequeue
  
 */

int max(int x, int y)
{
    return (x >= y ? x : y);
}

int height(Node * proot)
{
    if (proot == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(height(proot->left_), height(proot->right_));
    }
}

int main()
{
    Node * p0 = new Node(0);
    Node * p5 = new Node(5, p0);
    insert_left(p0, p5);
    Node * p2 = new Node(2, p0);
    insert_right(p0, p2);
    Node * p1 = new Node(1, p5);
    insert_left(p5, p1);
    Node * p4 = new Node(4, p4);
    insert_right(p5, p4);
    Node * p6 = new Node(6, p2);
    insert_left(p2, p6);
    Node * p7 = new Node(7, p2);
    insert_right(p2, p7);
    Node * p3 = new Node(3, p4);
    insert_left(p4, p3);
    Node * p8 = new Node(8, p7);
    insert_right(p7, p8);
    Node * p9 = new Node(9, p8);
    insert_left(p8, p9);
    
    std::cout << (*p0) << '\n';
    std::cout << (*p5) << '\n';
    std::cout << (*p2) << '\n';
    std::cout << (*p1) << '\n';
    std::cout << (*p4) << '\n';
    std::cout << (*p6) << '\n';
    std::cout << (*p7) << '\n';
    std::cout << (*p3) << '\n';
    std::cout << (*p8) << '\n';
    std::cout << (*p9) << '\n';

    std::cout << '\n';
    std::cout << "preoder df: "; preorder_df_print(p0);
    std::cout << '\n';
    std::cout << "inorder df: "; inorder_df_print(p0);
    std::cout << '\n';

    std::cout << "\n\n";
    std::cout << "preoder df: "; preorder_df_print(p2);
    std::cout << '\n';
    std::cout << "inorder df: "; inorder_df_print(p2);
    std::cout << '\n';

    std::cout << "height at 0: " << height(p0) << '\n';
    std::cout << "height at 5: " << height(p5) << '\n';
    std::cout << "height at 1: " << height(p1) << '\n';
    std::cout << "height at NULL: " << height(NULL) << '\n';

    return 0;
}
