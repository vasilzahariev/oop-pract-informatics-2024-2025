#include <iostream>

class Cents {
public:
    Cents(int cents): m_cents { cents } { }

    Cents operator+(int value) const;
    Cents& operator+=(int value);

    Cents operator-(const Cents& other) const;
    Cents& operator-=(const Cents& other);

    int getCents() const { return m_cents; }

private:
    int m_cents{};
};

int main() {
	const Cents cents1{ 6 };
	const Cents cents2{ cents1 + 2 };

	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}

Cents Cents::operator+(int value) const {
    return Cents { this->m_cents + value };
}

Cents& Cents::operator+=(int value) {
    this->m_cents += value;

    return *this;
}

Cents Cents::operator-(const Cents& other) const {
    return Cents { this->m_cents - other.m_cents };
}

Cents& Cents::operator-=(const Cents& other) {
    this->m_cents -= other.m_cents;

    return *this;
}
