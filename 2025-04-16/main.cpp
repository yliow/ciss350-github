#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

std::ostream & operator<<(std::ostream & cout,
                          const std::list< int > & xs)
{
    cout << '{';
    for (auto & e: xs)
    {
        cout << e << " ";
    }
    cout << '}';
    return cout;
}

class Graph
{
public:
    Graph(int n)
        : n_(n), adjlist_(3)
    {}
    void add(int u, int v)
    {
        adjlist_[u].push_front(v);
    }
//private:
    int n_; // number of nodes
    std::vector< std::list< int > > adjlist_;
};

std::ostream & operator<<(std::ostream & cout, const Graph & G)
{
    cout << "<Graph\n";
    int i = 0;
    for (auto e: G.adjlist_)
    {
        cout << "    " << i << ": " << e << '\n';
        ++i;
    }
    cout << '>';
    return cout;
}

int main()
{
    // std::list< int > xs;
    // xs.push_back(42);
    // xs.push_back(0);
    // xs.push_front(3);

    // std::cout << xs << '\n';
    // auto it = std::find(xs.begin(), xs.end(), 42);
    // if (it == xs.end()) std::cout << "not found\n";
    // else
    // {
    //     std::cout << "found\n";
    //     std::cout << (*it) << '\n';
    // }

    Graph G(3);
    G.add(0, 0);
    std::cout << G << '\n';
    
    
    return 0;
}
