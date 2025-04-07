#include <iostream>
#include <cstring>
#include <stdexcept>

/* Грешки
    *   В програмирането на C++ грешките са неизменна част от работата. 
        Важно е да се знае как да се справим с тях, за да не се стигне до срив на програмата.
    
    *   В C++ имаме два основни начина за обработка на грешки:
        1.   Изключения (exceptions) - те са механизъм за обработка на грешки, 
             който позволява на програмата да продължи да работи, дори и при възникване на грешка.
        2.   Код за проверка на грешки (error checking code) - това е код, 
             който проверява дали е възникнала грешка и ако е, то я обработва по определен начин.

    *   Изключенията са по-елегантен начин за обработка на грешки, тъй като те позволяват на програмата да продължи да работи, дори и при възникване на грешка.
        Кодът за проверка на грешки е по-лесен за разбиране и поддръжка, но може да доведе до по-сложен код и по-трудна отстраняване на грешки.
    
    *   В C++ изключенията се обработват с помощта на ключовите думи try, catch и throw.
        *   try - блок от код, който може да предизвика изключение.
        *   catch - блок от код, който обработва изключението.
        *   throw - ключова дума, която предизвиква изключение.

    *   Изключенията могат да бъдат предизвикани от различни причини, като например:
        *   Неправилно използване на указатели (например, опит за достъп до невалиден адрес в паметта).
        *   Опит за деление на нула.
        *   Неправилно използване на динамична памет (например, опит за освобождаване на вече освободена памет).
        *   Неправилно използване на файлови операции (например, опит за отваряне на невалиден файл).
*/

class Person{
public:
    Person(const char* firstName, const char* surname, int age);
    Person(const Person&);
    Person& operator=(const Person&);

    ~Person();

private:
    char* m_firstName{};
    char* m_surname{};
    int m_age{};

private:
    void copyData(const Person& other);
    void deleteData();

    void setFirstName(const char* firstName);
    void setSurname(const char* surname);
    void setAge(int age);
};

int main () {
    try {
        Person p("Vasil", "Zahariev", 22);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

Person::Person(const char* firstName, const char* surname, int age) {
    this->setFirstName(firstName);
    this->setSurname(surname);
    this->setAge(age);
}

Person::Person(const Person& other) {
    try {
        this->copyData(other);
    } catch (std::exception err) {
        this->deleteData();
        
        throw err;
    }
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        this->deleteData();
        this->copyData(other);
    }

    return *this;
}

Person::~Person() {
    this->deleteData();
}

void Person::copyData(const Person& other) {
    this->setFirstName(other.m_firstName);
    this->setSurname(other.m_surname);
    this->setAge(other.m_age);
}

void Person::deleteData() {
    delete[] this->m_firstName;
    this->m_firstName = nullptr;

    delete[] this->m_surname;
    this->m_surname = nullptr;
}

void Person::setFirstName(const char* firstName) {
    if (firstName == nullptr || strcmp(firstName, "") == 0) {
        throw std::invalid_argument("Invalid first name");
    }

    try {
        this->m_firstName = new char[strlen(firstName) + 1];
        strcpy(this->m_firstName, firstName);
    } catch (const std::bad_alloc& ba) {
        this->deleteData();
        
        throw ba;
    }
}

void Person::setSurname(const char* surname) {
    if (surname == nullptr || strcmp(surname, "") == 0) {
        throw std::invalid_argument("Invalid surname");
    }

    try {
        this->m_surname = new char[strlen(surname) + 1];
        strcpy(this->m_surname, surname);
    } catch (const std::bad_alloc& ba) {
        this->deleteData();
        
        throw ba;
    }
}

void Person::setAge(int age) {
    if (age < 0 || age > 120) {
        throw std::invalid_argument("Invalid age");
    }

    this->m_age = age;
}
