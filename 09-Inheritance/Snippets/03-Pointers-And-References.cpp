#include <iostream>
#include <string>

class Person {
public:
    Person() : m_name{ "<unknown>" }, m_age{ 0 }, m_height{ 0 } {
        std::cout << "Person::Person() called" << std::endl;
    }

    Person(const std::string& name, int age, double height)
        :   m_name{ name },
            m_age{ age },
            m_height{ height } {
        std::cout << "Person::Person(const std::string&, int, double) called" << std::endl;
    }

    ~Person(){
        std::cout << "Person::~Person() called" << std::endl;
    }

protected:
    std::string m_name{};
    int m_age{};

private:
    double m_height{};
};

class Student : public Person {
public:
    Student() : facultyNumber{ "XXXX" }{
        std::cout << "Student::Student() called" << std::endl;
    }

    Student(const std::string& name, int age, double height, const std::string& facultyNumber)
        :   Person{ name, age, height }, 
            facultyNumber{ facultyNumber } {
        std::cout << "Student::Student(const std::string&, int, double, const std::string&) called" << std::endl;
    }

    ~Student() {
        std::cout << "Student::~Student() called" << std::endl;
    }

private:
    std::string facultyNumber{};
};

int main () {
    Student student{};
    
    Person* personPtr = new Student("Maria", 20, 160, "82208");
    Student* studentPtr = new Student("Sonya", 20, 175, "82213");

    Person* newPersonPtr = studentPtr;
    Student* newStudentPtr = (Student*)personPtr;

    Person& personRf = student;
    Student& studentRf = student;

    Person& newPersonRf = studentRf;
    Student& newStudentRf = (Student&)personRf;

    delete personPtr;
    delete studentPtr;

    return 0;
}