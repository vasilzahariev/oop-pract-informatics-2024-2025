#include <iostream>

class IntList {
public:
    // За неконстантни обекти: може да се използва за присвояване
    int& operator[] (int index){
        return this->m_list[index];
    }

    // For const objects: can only be used for access
    // За константни обекти: може да се използва само за достъп
    // Тази функция може да се върне и по стойност, ако типът е евтин за копиране
    const int& operator[] (int index) const {
        return this->m_list[index];
    }

    int& operator[] (char indexAsChar) {
        if (indexAsChar < '0' || indexAsChar > '9') {
            throw std::out_of_range("Index out of range");
        }

        return (*this)[static_cast<int>(indexAsChar - '0')];
    }

private:
    int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
};

int main() {
    IntList list{};
    list[2] = 3; // non-const version of operator[]
    std::cout << list[2] << '\n';

    const IntList clist{};
    // clist[2] = 3; // compile error: clist[2] returns const reference, which we can't assign to
    std::cout << clist[2] << '\n';

    return 0;
}