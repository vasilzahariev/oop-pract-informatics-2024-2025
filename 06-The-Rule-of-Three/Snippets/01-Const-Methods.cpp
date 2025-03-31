#include <iostream>

/* Константен метод
    *   Констанетен метод е метод, който гарантира, че няма да променя
        обекта, върху който е извикан и няма да извиква методи, които не са
        константни.
    
    *   За разлика от нормалните методи тези могат да бъдат извиквани от
        константни обекти. Константните методи могат да се извикват и от
        неконстантни обекти.
    
    *   Един метод го обявяваме за константен, като добавим ключовата дума const
        след списъка с параметри на метода. Например:
            void print() const;
    
    *   Константният метод може да модифицира и извиква неконстантни методи на обекти,
        които не са обекта, върху който е извикан.

    *   Добрата практика е, ако знаем, че един метод няма да променя данните на класа да го направим константен.

    *   Тъй като често ще се случва да подаваме на функции обекти като константни референции, е добре
        да знаем, че константните методи могат да се извикват и от константни обекти.
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
    const Date date(1, 1, 1970);

    date.print();

    // date.addYear(); -> Ще даде грешка, защото методът не е константен

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
