#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <deque>

bool divisible_by_5(int n) {
    return n % 5 == 0;
}

void task1() {
    std::list<int> l;
    unsigned int amount;
    int current;

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
}

void task2() {
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
    std::copy(v.begin(), v.end(), std::front_inserter(l));
    std::cout << "List with reverse order of elements from vector: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Использование адаптера front_inserter для добавления элементов в начало
    std::fill_n(std::front_inserter(l), 3, -2);
    std::cout << "List with new elements in the beginning: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void task3() {
    //Запись в файл
    std::vector<int> v_out = {1, -2, 3, -4, 5, -6};
    std::cout << "Our vector: ";
    for (auto it = v_out.begin(); it != v_out.end(); ++it)
        std:: cout << *it <<  " ";
    std::cout << std::endl;
    std::cout << "Copy our vector to \"file.txt\"" << std::endl;
    std::ofstream file1("..\\file.txt");
    std::copy(v_out.begin(), v_out.end(), std::ostream_iterator<int>(file1, " "));
    file1.close();

    // Чтение из файла
    std::vector<int> v_in;
    std::ifstream file2("..\\file.txt");
    std::copy(std::istream_iterator<int>(file2), std::istream_iterator<int>(), std::back_inserter(v_in));
    file2.close();
    std::cout << "Vector from \"file.txt\": ";
    for (auto it = v_in.begin(); it != v_in.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void task4() {
    std::vector<int> v = {-1, 2, -3, 4, -5, 6};
    std::cout << "Our vector: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::deque<int> d;
    std::copy(v.begin(), v.end(), std::back_inserter(d));
    std::cout << "Deque with elements from vector: ";
    for (auto it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void task5() {
    int n, temp;
    std::list<int> l;
    std::cout << "Input amount of your numbers:" << std::endl;
    std::cin >> n;
    std::cout << "Input your numbers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        l.push_back(temp);
    }
    std::cout << "Reverse order of elements from list: ";
    for (auto it = l.rbegin(); it != l.rend(); ++it)
        std::cout << *it << " ";
}

int main() {
    std::cout << "Task 1:" << std::endl;
    task1();
    std::cout << "-----------------" << std::endl;

    std::cout << "Task 2:" << std::endl;
    task2();
    std::cout << "-----------------" << std::endl;

    std::cout << "Task 3:" << std::endl;
    task3();
    std::cout << "-----------------" << std::endl;

    std::cout << "Task 4:" << std::endl;
    task4();
    std::cout << "-----------------" << std::endl;

    std::cout << "Task 5:" << std::endl;
    task5();
    std::cout << "-----------------" << std::endl;
    return 0;
}