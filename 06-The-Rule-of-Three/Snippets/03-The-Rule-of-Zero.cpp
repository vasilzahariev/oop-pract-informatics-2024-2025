#include <iostream>

/* The rule of zero
    *   Правилото на нулата (Rule of Zero) гласи, че ако класът не
        управлява ресурси, то не е необходимо да дефинира деструктор,
        копиращ конструктор или оператор за присвояване. Вместо това,
        компилаторът автоматично генерира стандартни версии на тези методи,
        които ще работят правилно.
*/

class Date {
public:
    Date();
    Date(std::uint16_t day, std::uint16_t month, std::uint16_t year);
    
    std::uint16_t getDay() const;
    std::uint16_t getMonth() const;
    std::uint16_t getYear() const;
    
    void print() const;
    
    void addYear();
    
private:
    std::uint16_t m_day{};
    std::uint16_t m_month{};
    std::uint16_t m_year{};
};

int main() {
    return 0;
}

Date::Date() :
    m_day(1),
    m_month(1),
    m_year(1970) {
}

Date::Date(std::uint16_t day, std::uint16_t month, std::uint16_t year) :
    m_day(day),
    m_month(month),
    m_year(year) {
}

std::uint16_t Date::getDay() const {
    return this->m_day;
}

std::uint16_t Date::getMonth() const {
    return this->m_month;
}

std::uint16_t Date::getYear() const {
    return this->m_year;
}

void Date::print() const {
    std::cout << this->m_day << '.' << this->m_month << '.' << this->m_year << '\n';
}

void Date::addYear() {
    ++this->m_year;
}
