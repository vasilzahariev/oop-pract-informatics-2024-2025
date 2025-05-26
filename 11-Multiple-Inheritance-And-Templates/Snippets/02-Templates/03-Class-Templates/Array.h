#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <typename T>
class Array {
public:
    Array(int length);
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
    ~Array();

    int getLength() const { return m_length; }

    void erase();

    T& operator[](int index);

private:
    int m_length{};
    T* m_data{};
};

template <typename T>
Array<T>::Array(int length) {
    assert(length > 0);

    this->m_data = new T[length]{};
    this->m_length = length;
}

template <typename T>
Array<T>::~Array() {
    delete[] this->m_data;
}

template <typename T>
void Array<T>::erase() {
    delete[] this->m_data;

    this->m_data = nullptr;
    this->m_length = 0;
}

template <typename T>
T& Array<T>::operator[](int index) {
    assert(index >= 0 && index < m_length);

    return this->m_data[index];
}

#endif