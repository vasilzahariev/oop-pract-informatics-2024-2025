#include <iostream>

class Cents {
public:
    Cents(int cents = 0): m_cents{ cents } {}

    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

private:
    int m_cents{};
};

class Dollars {
public:
    Dollars(int dollars = 0): m_dollars{ dollars }{}

    operator Cents() const { return Cents { m_dollars * 100 }; }

private:
    int m_dollars{};
};

void printCents(Cents cents) {
    std::cout << cents; // cents will be implicitly cast to an int here
}

int main() {
    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here

    std::cout << '\n';

    return 0;
}
