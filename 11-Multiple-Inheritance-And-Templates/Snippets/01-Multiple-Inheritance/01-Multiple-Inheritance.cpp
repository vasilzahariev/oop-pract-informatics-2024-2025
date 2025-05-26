#include <iostream>
#include <string>
#include <string_view>

/*  Множествено наследяване
    *   За разлика от повечето езици за програмиране C++ позволява множествено наследяване.
        Множественото наследяване е механизъм, при който един клас може да наследява от повече от един базов клас.

    *   Синтаксис:
        class DerivedClass : public BaseClass1, public BaseClass2 {
            // ...
        };

    *   Важно е да се отбележи, че множественото наследяване може да доведе до сложни ситуации,
        особено когато два или повече базови класа имат членове с едно и също име. 
        В такива случаи е необходимо да се използва операторът ::, 
        за да се уточни кой член от кой базов клас се използва.
*/

class Person {
public:
    Person(std::string_view name, int age)
        : m_name{ name }, m_age{ age } {
        std::cout << "Person()\n";
    }

    virtual ~Person() {
        std::cout << "~Person()\n";
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

    void print() const {
        std::cout << "Name: " << m_name << ", Age: " << m_age << '\n';
    }

private:
    std::string m_name{};
    int m_age{};
};

class Employee {
public:
    Employee(std::string_view employer, double wage)
        : m_employer{ employer }, m_wage{ wage } {
        std::cout << "Employee()\n";
    }

    virtual ~Employee() {
        std::cout << "~Employee()\n";
    }

    const std::string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }

    void print() const {
        std::cout << "Employer: " << m_employer << ", Wage: " << m_wage << '\n';
    }

private:
    std::string m_employer{};
    double m_wage{};
};

class Teacher : public Person, public Employee {
public:
    Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
        : Person{ name, age }, Employee{ employer, wage }, m_teachesGrade{ teachesGrade } {
        std::cout << "Teacher()\n";
    }

    virtual ~Teacher() {
        std::cout << "~Teacher()\n";
    }

private:
    int m_teachesGrade{};
};

int main() {
    Teacher t{ "Mary", 45, "Boo", 14.3, 8 };

    std::cout << std::endl;

    // t.print(); // Компилаторът ще ни каже, че "print" е двусмислена, защото имаме print в двата базови класа и няма да може да се оправи кое точно да извикаме.
    t.Person::print();
    t.Employee::print();

    std::cout << std::endl;

    return 0;
}