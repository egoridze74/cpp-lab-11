#include <iostream>
#include <list>
#include <algorithm>


bool divisible_by_5(int n) {
    return n % 5 == 0;
}

int main() {
    std::list<int> l;
    int amount, current;
    std::cout << "Insert amount of your numbers:" << std::endl;
    std::cin >> amount;
    std::cout << "Insert your numbers:" << std::endl;
    for (int i = 0; i < amount; ++i) {
        std::cin >> current;
        l.push_back(current);
    }

    std::cout << "Minimal element in your numbers:" << std::endl;
    std::cout << *std::min_element(l.begin(), l.end())<< std::endl;

    std::cout << "First element that is divisible by 5:" << std::endl;
    auto result = std::find_if(l.begin(), l.end(), divisible_by_5);
    if (result == l.end())
        std::cout << "Not found" << std::endl;
    else
        std::cout << *result << std::endl;
    return 0;
}
