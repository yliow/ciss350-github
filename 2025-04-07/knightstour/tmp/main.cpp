#include <iostream>
#include <vector>

int main()
{
    std::vector< int > v(10, -1);

    std::cout << v.size() << '\n';
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << '\n';
    }
    
    return 0;
}
