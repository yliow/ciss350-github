#include <iostream>
#include <exception>

// file: SLNode.h (SL = singly-linked)
class SLNode
{
public:
    SLNode(int key, SLNode * next)
        : key_(key), next_(next)
    {}
    // int key() const
    // {
    //     return key_;
    // }
    int key_;
    SLNode * next_;
private: // not used
};

std::ostream & operator<<(std::ostream & cout, const SLNode & n)
{
    cout << "<SLNode " << &n << " key:" << n.key_ << ", next:" << n.next_ << '>';
    return cout;
}


// file: SLList.h and SLList.cpp

class Underflow: public std::exception
{};

class SLList
{
public:
    SLList()
        : phead_(NULL)
    {}
    ~SLList()
    {
        std::cout << "in SLList::~SLList() ...\n";
        while (!is_empty())
        {
            delete_head();
        }
    }
    void insert_head(int key)
    {
        phead_ = new SLNode(key, phead_);
    }
    bool is_empty() const
    {
        return (phead_ == NULL);
    }
    void delete_head()
    {
        if (is_empty())
        {
            throw Underflow();
        }
        else
        {   
            SLNode * p = phead_;
            phead_ = phead_->next_;
            delete p;
        }
    }
    int head() const
    {
        return phead_->key_;
    }
    SLNode * phead_;
};

std::ostream & operator<<(std::ostream & cout, const SLList & list)
{
    cout << "<SLList " << &list << '\n';
    SLNode * p = list.phead_;
    while (p != NULL)
    {
        std::cout << "  " << (*p) << '\n';
        p = p->next_;
    }
    cout << '>';
    return cout;
}

void print_list(SLNode * p)
{
    std::cout << "print_list ... \n";
    while (p != NULL)
    {
        std::cout << (*p) << '\n';
        p = p->next_;
    }
}

// 5->1->3->0
int main()
{
    // SLNode * p5 = new SLNode(5, NULL);

    // SLNode * p1 = new SLNode(1, NULL);
    // p5->next_ = p1;
    
    // SLNode * p3 = new SLNode(3, NULL);
    // p1->next_ = p3;
    
    // SLNode * p0 = new SLNode(0, NULL);
    // p3->next_ = p0;
    
    // std::cout << (*p5) << '\n';
    // std::cout << (*p1) << '\n';
    // std::cout << (*p3) << '\n';
    // std::cout << (*p0) << '\n';

    // print_list(p5);

    int x = 0;


    if (x == 0)
    {
        SLList list;
        std::cout << list << '\n';
        
        std::cout << "inserting head with 1 ...\n";
        list.insert_head(1);
        std::cout << list << '\n';
        
        std::cout << "inserting head with 0 ...\n";
        list.insert_head(0);
        std::cout << list << '\n';
        
        std::cout << "inserting head with 3 ...\n";
        list.insert_head(3);
        std::cout << list << '\n';
        
        std::cout << "inserting head with 5 ...\n";
        list.insert_head(5);
        std::cout << list << '\n';

        // test delete when empty
        try
        {
            SLList l1;
            l1.delete_head();
        }
        catch (Underflow & e)
        {
            std::cout << "successfully caught delete head when empty\n";
        }
        
    } // list object dies ... list.~SLList() called

    // .....
    
    return 0;
}