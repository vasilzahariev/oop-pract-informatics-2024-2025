#include <iostream>
#include <cstring>

/* Ключовата дума static в C++ класове
    *   Статичните членове на класовете принадлежат на самия клас, а не на конкретен обект от класа.

    *   Статичните членове се споделят между всички обекти от класа.

    *   Статичните членове могат да бъдат достъпвани без да се създава обект от класа.
*/

class Student {
public:
    static int getStudentsCount() { // Статичен метод
        return Student::s_studentsCount;
    }

public:
    Student(const char* name): m_id(++Student::s_studentIdGenerator) {
        std::cout << "Student " << this->m_id << " created. Total students: " << ++Student::s_studentsCount << std::endl;

        strcpy(this->m_name, name);
    }

    Student(const Student& other) = delete; // Забраняваме копирането на обекти от този клас
    Student& operator=(const Student& other) = delete; // Забраняваме присвояването на обекти от този клас

    ~Student() {
        std::cout << "Student " << this->m_id << " destroyed. Total students: " << --Student::s_studentsCount << std::endl;
    }

    int getId() const {
        return this->m_id;
    }

    const char* getName() const {
        return this->m_name;
    }

private:
    static int s_studentIdGenerator; // Декларация на статичен член данни
    static inline int s_studentsCount{ 0 }; // Статичен член данни, инициализиран с 0
    static constexpr std::size_t k_maxNameSize{ 50 }; // Статичен константен член данни
  
private:
    const int m_id{};

private:
    char m_name[Student::k_maxNameSize]{};
};

int Student::s_studentIdGenerator = 0; // Дефиниция на статичен член данни

int main() {
    Student student1("John Doe");
    Student student2("Jane Doe");
    Student student3("Alice Smith");

    std::cout << "Student 1 ID: " << student1.getId() << ", Name: " << student1.getName() << std::endl;
    std::cout << "Student 2 ID: " << student2.getId() << ", Name: " << student2.getName() << std::endl;
    std::cout << "Student 3 ID: " << student3.getId() << ", Name: " << student3.getName() << std::endl;

    std::cout << "Total students: " << Student::getStudentsCount() << std::endl;

    return 0;
}
