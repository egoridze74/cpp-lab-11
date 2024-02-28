#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::vector<int> v = {13, 1337, 52, 21, 74};
    std::list<int> l;

    std::cout << "Original vector: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Использование адаптера back_inserter для добавления элементов в конец
    std::fill_n(std::back_inserter(v), 4, -1);
    std::cout << "Vector with new elements at the end: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Копирование элементов из вектора в список с помощью адаптера
    std::copy(v.begin(), v.end(), std::back_inserter(l));
    std::cout << "List with reverse order of elements";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Использование адаптера front_inserter для добавления элементов в начало
    std::fill_n(std::front_inserter(l), 3, -2);
    std::cout << "List with new elements in the beginnig: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
};