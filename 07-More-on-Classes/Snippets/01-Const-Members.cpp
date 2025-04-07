#include <iostream>
#include <cstring>

/* Константен член данни
    *   Константните член данни на класовете не могат да се променят след инициализацията им.

    *   Те могат да бъдат инициализирани само в "member-initializer list" на конструктора и при делкарацията им.
        Не могат да бъдат инициализирани в тялото на конструктора.
        Не могат да бъдат инициализирани в методите на класа.
*/

struct Date {
    int day{};
    int month{};
    int year{};
};

class Student {
public:
    Student(int id, const Date& birthDate, const char* name, int age)
        : m_id(id), m_birthDate(birthDate), m_name(new char[strlen(name) + 1]), m_age(age) {
        strcpy(this->m_name, name);
    }
    Student(const Student& other) = delete; // Забраняваме копирането на обекти от този клас
    Student& operator=(const Student& other) = delete; // Забраняваме присвояването на обекти от този клас

    ~Student() {
        delete[] this->m_name;
        this->m_name = nullptr;
    }

private:
    const int m_id{};
    const Date m_birthDate{};

    char* m_name{};
    int m_age{};
};

int main() {
    Student student(1, {1, 1, 2000}, "John Doe", 20);

    return 0;
}
