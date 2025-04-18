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

std::ostream & operator<<(std::ostream & cout, const std::vector< int > & s)
{
    cout << '{';
    int i = 0;
    for (auto e: s)
    {
        cout << i << "->" << e << " ";
        ++i;
    }
    cout << '}';
    return cout;
}

class Graph
{
public:
    Graph(int n)
        : n_(n), adjlist_(n)
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

// use bt
bool gc(const Graph & G, int numcolors, std::vector< int > & solution)
{
    if (solution.size() == G.n_)
    {
        return true;
    }
    else
    {
        int n = solution.size(); // going to color n
        for (int c = 0; c < numcolors; ++c)
        {
            // check if n->c is a valid coloring
            // i.e. check if neighbor m has not been colored with c
            bool is_valid = true;
            for (int m = 0; m < n; ++m)
            {
                if (solution[m] == c)
                {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid)
            {
                solution.push_back(c);
                bool b = gc(G, numcolors, solution);
                if (b) return true;
                solution.pop_back()
            }
        }
        return false;
    }
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

    Graph G(4);
    G.add(0, 1); G.add(1, 0);
    G.add(0, 2); G.add(2, 0);
    G.add(1, 2); G.add(2, 1);
    std::cout << G << '\n';

    std::vector< int > solution;
    // solution[5] = 2 means 5 is colored with color 2
    
    bool b = gc(G, 2, solution);
    if (b)
    {
        std::cout << "success ...\n";
        std::cout << solution << '\n';
    }
    else
    {
        std::cout << "FAILURE ...\n";
    }
    
    return 0;
}
