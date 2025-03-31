#include <iostream>
#include <cstring>
#include <cassert>

/* The Rule of Three (голямата 4ка)
    *   Правило на тройката (Rule of Three) е принцип в C++,
        който гласи, че ако класът изисква собствена реализация на
        деструктор, копиращ конструктор или оператор за присвояване,
        то той вероятно изисква реализация на всички три.

    *   Правилото на тройката е свързано с управлението на ресурси
        (например динамично разпределена памет) и е важно за избягване
        на проблеми с паметта, като изтичане на памет.

    *   Ако нямаме тези три метода, компилаторът автоматично генерира
        стандартни версии на тях, които не правят нищо специално.
        Тези стандртни методи ще извършват shallow copy на данните.
        Shallow copy представлява копиране на всеки член на класа,
        без да се взима предвид, че те могат да сочат към динамично
        разпределена памет. Това ще ни върши работа за прости класове,
        но не и за класове, които управляват динамично разпределена памет.
        В такъв случай дефинираме 3те метода и реализираме deep copy.
        Deep copy първо освобождава динамично разпределената памет на
        обекта, а след това копира данните от другия обект в текущия като заделя
        нужната памет и копира данните в нея.
    
    *   Във ФМИ това правило често се нарича "голямата 4ка", защото включват и
        конструктора по подразбиране.
*/

/* Копиращ конструктор (Copy Constructor)
    *   Копиращ конструктор е конструктор, който се използва за инициализиране на
        обект с вече съществуващ обект от същия тип. След изпълнението на
        копиращия конструктор, новосъздаденият обект трябва да бъде копие на
        обекта, предаден като инициализатор.
*/

/* Оператор за присвояване (Assignment Operator)
    *   Операторът за присвояване е оператор, който позволява на един обект да
        бъде присвоен на друг обект от същия тип. Той е полезен, когато искате
        да копирате стойностите на един обект в друг, след като и двата обекта
        вече са съществували.

    *   Операторът за присвояване трябва да се увери, че не се опитва да
        копира самия себе си (self-assignment).

    *   Операторът за присвояване трябва да освободи ресурсите на текущия
        обект, преди да копира ресурсите от другия обект.
*/

class Person {
public:
    Person();
    Person(const char* name, std::uint16_t age);
    Person(const Person& other); // Копиращ конструктор
    Person& operator=(const Person& other); // Оператор за присвояване
    ~Person(); // Деструктор

    void setName(const char* name);
    const char* getName() const;

    void setAge(std::uint16_t age);
    std::uint16_t getAge() const;

    void print() const;

private:
    char* m_name{ nullptr };
    std::uint16_t m_age{ 0 };

    void copyData(const Person& other);
    void deleteData();
};

int main() {
    Person person1("John Doe", 30); // Извиква се конструктор с параметри
    Person person2 = person1; // Извиква се копиращ конструктор
    Person person3; // Извиква се конструктор по подразбиране

    person3 = person1; // Извиква се оператор за присвояване

    return 0;
}

Person::Person() {}

Person::Person(const char* name, std::uint16_t age) : m_age{ age } {
    this->setName(name);
}

Person::Person(const Person& other) {
    this->copyData(other);
}

Person& Person::operator=(const Person& other) {
    // Проверка за самоприсвояване
    if (this != &other) {
        this->deleteData();
        this->copyData(other);
    }

    // Връщаме текущия обект, за да можем да го използваме в изрази
    // като person1 = person2 = person3;
    return *this;
}

Person::~Person() {
    this->deleteData();
}

void Person::setName(const char* name) {
    if (this->m_name) {
        delete[] this->m_name;
    }

    this->m_name = new (std::nothrow) char[strlen(name) + 1];

    assert(this->m_name != nullptr);

    strcpy(this->m_name, name);
}

const char* Person::getName() const {
    return this->m_name;
}

void Person::setAge(std::uint16_t age) {
    this->m_age = age;
}

std::uint16_t Person::getAge() const {
    return this->m_age;
}

void Person::print() const {
    const char* nameToDisplay = this->m_name ? this->m_name : "<null>";

    std::cout << "Name: " << nameToDisplay << ", Age: " << this->m_age << std::endl;
}

void Person::copyData(const Person& other) {
    this->m_age = other.m_age;

    if (other.m_name) {
        this->setName(other.m_name);
    } else {
        this->m_name = nullptr;
    }
}

void Person::deleteData() {
    delete[] this->m_name;
    this->m_name = nullptr;
}
