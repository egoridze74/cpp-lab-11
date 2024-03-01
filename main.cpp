#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool divisible_by_5(int n) {
    return n % 5 == 0;
}

void task1() {
    std::list<int> l;
    unsigned int amount;
    int current;

    std::cout << "TASK-1:"<< std::endl;
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
    std::cout << std::endl;
}

void task2() {
    std::vector<int> v = {13, 1337, 52, 21, 74};
    std::list<int> l;

    std::cout << "TASK-2:" << std::endl;
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
    std::copy(v.begin(), v.end(), std::front_inserter(l));
    std::cout << "List with reverse order of elements from vector: ";
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
}


int main() {
    //task1();
    task2();
    return 0;
}