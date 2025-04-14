#include <iostream>

class Digit {
public:
    Digit(int digit=0): m_digit{digit} {}

    Digit& operator++(); // prefix няма параметър
    Digit& operator--(); // prefix няма параметър

    Digit operator++(int); // postfix има int параметър
    Digit operator--(int); // postfix има int параметър

    int value() const { return m_digit; }

private:
    int m_digit{};
};

int main()
{
    Digit digit{ 5 };

    std::cout << digit.value();
    
    std::cout << "prefix ++ ->" << (++digit).value(); // Digit::operator++();
    std::cout << "postfix ++ ->" << (digit++).value(); // Digit::operator++(int);
    
    std::cout << digit.value();
    
    std::cout << "prefix -- ->" << (--digit).value(); // Digit::operator--();
    std::cout << "postfix -- ->" << (digit--).value(); // Digit::operator--(int);
    
    std::cout << digit.value();

    return 0;
}

Digit& Digit::operator++() {
    this->m_digit = (m_digit + 1) % 10; // Ако стигнем 10, връщаме стойността на 0

    return *this;
}

Digit& Digit::operator--() {
    this->m_digit = this->m_digit == 0 ? 9 : this->m_digit - 1; // Ако стигнем 0, връщаме стойността на 9

    return *this;
}

Digit Digit::operator++(int) {
    Digit temp{ *this };

    ++(*this);

    return temp;
}

Digit Digit::operator--(int) {
    Digit temp{ *this };

    --(*this);

    return temp;
}
