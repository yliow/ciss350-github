#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set< int > xs;
    xs.insert(5);
    xs.insert(42);
    for (auto & e: xs)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    auto it = xs.find(42);
    std::cout << (*it) << '\n';

    it = xs.find(0);
    std::cout << (it == xs.end() ? "end reached\n" : "end not reached\n");

    xs.erase(42);
    for (auto & e: xs)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
