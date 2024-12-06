#include <iostream>
#include <unordered_set>
#include <stack>


class Node
{
public:
    Node(int key, Node * left=NULL, Node * right=NULL)
        : key_(key), left_(left), right_(right)
    {}
    int key_;
    Node * left_;
    Node * right_;
    // bool NOT_SCHEDULE;
    // bool SCHEDULE;
    // bool DONE;
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

    // TODO: Nodes not scheduled for visit
    // TO_VISIT: Nodes scheduled for visit and need to search fast
    // DONE: Nodes already processed (print)
    //
    // [TODO] ---> [TO VISIT] ----> [DONE]
    
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

    std::stack< Node * > TO_VISIT;
    std::unordered_set< int > TO_VISIT_KEYS;
    std::unordered_set< int > DONE;

    // pick someone to put into
    // say for now hardcode 0 as first node to visit
    TO_VISIT.push(p0); TO_VISIT_KEYS.insert(p0->key_); 

    // graph traversal:
    // while stack is not empty:
    //   v = pop stack
    //   process v
    //   for u in chilren of v:
    //       if u already schedule in stack or u is already process,
    //       ignore u. otherwise put u into the stack

    while (!TO_VISIT.empty())
    {
        Node * p = TO_VISIT.top();
        TO_VISIT.pop(); TO_VISIT_KEYS.erase(p->key_);
        std::cout << "*p: " << (*p) << '\n';
        DONE.insert(p->key_);

        // put children into stack (if nec)/
        if (p->left_ != NULL
            && TO_VISIT_KEYS.find(p->left_->key_) == TO_VISIT_KEYS.end() // p->left_ not in TO_VISIT
            && DONE.find(p->left_->key_) == DONE.end()                   // p->left is not in DONE
            )
        {
            std::cout << "p->left_->key_= " << p->left_->key_ << " added to stack\n"; 
            TO_VISIT.push(p->left_); TO_VISIT_KEYS.insert(p->left_->key_);
        }
        if (p->right_ != NULL
            && TO_VISIT_KEYS.find(p->right_->key_) == TO_VISIT_KEYS.end() // p->right_ not in TO_VISIT
            && DONE.find(p->right_->key_) == DONE.end()                   // p->right is not in DONE
            )
        {
            std::cout << "p->right_->key_= " << p->right_->key_ << " added to stack\n"; 
            TO_VISIT.push(p->right_); TO_VISIT_KEYS.insert(p->left_->key_);
        }
        char c;
        std::cout << "? ";
        std::cin >> c;
    }

    /*

      The above hardcoded the first node p0.
      You should put all the nodes into another pool.
      Then pick from the pool and go through the above alg.
      When the above loop ends, pick another node from the pool until the pool is empty.
      Of course update the pool as your perform the graph traversal.

      The graph traversal actually allows you to construct a tree inside the graph
      if the graph is connected.
      If the graph is not connnected, you have a set of trees.
      That's called a forest.
      
     */
    

    delete p0;
    delete p1;
    delete p2;
    delete p3;
    
    return 0;
}