#include <iostream>
#include <cstring>

/*  Виртуални функции
    *   При наследяването може да стигнем до ситуация, където имаме указател към базов клас,
        който сочи към обект на производен клас. В такъв случай, ако извикаме функция от базовия клас,
        то ще се извика версията на базовия клас, а не версията на производния клас.
        За да избегнем това, можем да използваме виртуални функции.

    *   Виртуалната функция е специален тип член-функция, която, когато бъде извикана,
        се разрешава до най-производната версия на функцията за действителния тип на обекта,
        към който се отнася или сочи.


    *   Наследена функция се счита за съвпадение, ако има същата конструкция (име, типове на параметрите и дали е const)
        и тип на връщане като базовата версия на функцията. Такива функции се наричат overrides (презаписващи).
        Ако класът наследник не презапише виртуалната функция на базовия клас, се използва версията на базовия клас.

    *   За да направим функция виртуална, просто поставяме ключовата дума "virtual" пред декларацията на функцията.

    *   Виртуален деструктор
        *   Виртуалният деструктор е деструктор, който е деклариран с ключовата дума virtual.
            Той позволява на обектите от производния клас да бъдат унищожавани правилно,
            когато се освобождават чрез указател към базовия клас.
        *   Виртуалният деструктор гарантира, че правилният деструктор на производния клас
            ще бъде извикан, когато обектът бъде унищожен.
        *   За най-сигурно е добре винаги да правим деструкторите на базовите класове виртуални.
    
    *   Чрез ключовата дума "override" можем да укажем, че функцията е презаписваща.
        *   Това е полезно, защото компилаторът ще провери дали функцията наистина презаписва виртуална функция
            от базовия клас и ще генерира грешка, ако не е така.
        *   Също така, ако базовият клас не е виртуален, компилаторът ще генерира грешка.
        *   Ако една функция е константа и презаписваща, то първо се поставя "const", а след това "override".
            Например: void print() const override;

    *   Чрез ключовата дума "final" можем да укажем, че функцията не може да бъде презаписвана в производния клас.
        *   Това е полезно, когато искаме да предотвратим наследяването на определена функция
            или когато искаме да запазим определено поведение на функцията.
        *   Също така, ако базовият клас не е виртуален, компилаторът ще генерира грешка.
        *   final може да се използва и за класове, за да предотврати наследяването на класовете. Това става по следния начин:
            class Base { ... };
            class Derived final : public Base { ... };
            class Derived2 : public Derived { ... }; // Грешка: не може да наследява от Derived

    *   Има един специален случай, в който презаписващата функция на производния клас може да има различен тип на връщане от базовия клас
        и все пак да се счита за съвпадение. Ако типът на връщане на виртуалната функция е указател или референция към някакъв клас,
        то презаписващите функции могат да върнат указател или референция към клас наследник. Те се наричат ковариантни типове на връщане.
*/

class Person {
public:
    Person() : m_name{ nullptr }, m_age{ 0 } {}
    
    Person(const char* name, int age) : m_name{ new char[strlen(name) + 1] }, m_age{ age} {
        strcpy(this->m_name, name);
    }

    Person(const Person& other) {
        this->copy(other);
    }

    virtual Person& operator=(const Person& other) {
        if (this != &other) {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    void setName(const char* name) {
        delete[] this->m_name;
        this->m_name = new char[strlen(name) + 1];
        strcpy(this->m_name, name);
    }

    virtual void print() const {
        std::cout << "Name: " << this->m_name << std::endl;
        std::cout << "Age: " << this->m_age << std::endl;
    }

    virtual ~Person() {
        this->deallocate();
    }

protected:
    char* m_name{ nullptr};
    int m_age{};

    void copy(const Person& other) {
        this->m_name = new char[strlen(other.m_name) + 1];
        strcpy(this->m_name, other.m_name);

        this->m_age = other.m_age;

        std::cout << "Person::copy(const Person&) called" << std::endl;
    }

    void deallocate()
    {
        delete[] this->m_name;
    }
};

class Student : public Person {
public:
    Student() : Person(), facultyNumber{ nullptr } {}
    
    Student(const char* name, int age, const char* facultyNumber) :
        Person{ name, age }, facultyNumber{ new char[strlen(facultyNumber) + 1] } {
        strcpy(this->facultyNumber, facultyNumber);
    }

    Student(const Student& other) : Person{ other } {
        this->copy(other);
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            this->deallocate();
            Person::deallocate();
            Person::copy(other);
            this->copy(other);
        }

        return *this;
    }

    ~Student() override {
        this->deallocate();
    }

    void print() const override {
        Person::print();

        std::cout << "FN: " << this->facultyNumber << std::endl;
    }

private:
    char* facultyNumber{ nullptr };

    void copy(const Student& other) {
        this->facultyNumber = new char[strlen(other.facultyNumber) + 1];
        strcpy(this->facultyNumber, other.facultyNumber);

        std::cout << "Student::copy(const Student&) called" << std::endl;
    }

    void deallocate() {
        delete[] this->facultyNumber;
    }
};

int main () {
    Student student{ "Mihail", 20, "72453" };

    Student studentCopyCtr(student);
    studentCopyCtr.setName("Mishou");

    Student studentOp{};
    studentOp = student;
    studentOp.setName("Pernichanina");

    student.print();
    studentCopyCtr.print();
    studentOp.print();

    return 0;
}
