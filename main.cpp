#include <iostream>
#include "minivector.hpp"

int main()
{
    minivector a;
    for (int i = 0; i < 5; i++)
        a.push_back(i);

    minivector b = std::move(a);

    std::cout << "b size: " << b.getSize() << "\n";  // should be 5
    std::cout << "a size: " << a.getSize() << "\n";  // should be 0

    b.print();

    std::cout<<b.at(0)<<std::endl;
    // std::cout<<b.at(5)<<std::endl;
    
    b.clear();
    std::cout << "b size: " << b.getSize() << "\n";  // should be 5
    std::cout << "b capacity: " << b.getCapacity() << "\n";  // should be 5

    minivector v;
    v.reserve(100);

    std::cout << v.getSize() << "\n";      // 0
    std::cout << v.getCapacity() << "\n";  // >= 100

    for (int i = 0; i < 100; i++)
        v.push_back(i);

    std::cout << v.getCapacity() << "\n";  // still 100

    v.push_back(100);


    std::cout << v.getSize() << "\n";  // still 100
    std::cout << v.getCapacity() << "\n";  // still 100

    v.shrink_to_fit();

    std::cout << v.getSize() << " " << v.getCapacity() << "\n";


    for (int x : v) {
    std::cout << x << " ";
}
    return 0;
}