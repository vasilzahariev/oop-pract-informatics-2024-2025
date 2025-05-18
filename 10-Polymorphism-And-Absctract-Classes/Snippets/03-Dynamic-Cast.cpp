#include <iostream>
#include <string>

class FMIPerson {
public:
    FMIPerson(const std::string& name, int age) : m_name{ name }, m_age{ age } {}

    virtual void whoAmI() const {
        std::cout << "My name is " << this->m_name << " and I am " << this->m_age << " years old." << std::endl;
    }

    virtual ~FMIPerson() = default;

private:
    std::string m_name{};
    int m_age{};
};

class Lecturer : public FMIPerson {
public:
    Lecturer(const std::string& name, int age, const std::string& subject, int yearsOfExperience)
        : FMIPerson{ name, age }, m_subject{ subject }, m_yearsOfExperience{ yearsOfExperience } {}

    virtual void whoAmI() const {
        FMIPerson::whoAmI();

        std::cout << "I am a lecturer in FMI, I teach " << this->m_subject << " and I have "
        << this->m_yearsOfExperience << " years of experience" << std::endl;
    }

private:
    std::string m_subject{};
    int m_yearsOfExperience{};
};

class Assistant : public FMIPerson {
public:
    Assistant(const std::string& name, int age, const std::string& subject, bool isPartTime)
        : FMIPerson{ name, age }, m_subject{ subject }, m_isPartTime{ isPartTime } {}

    virtual void whoAmI() const {
        FMIPerson::whoAmI();

        std::string assistantType = (this->m_isPartTime) ? "part-time" : "full-time";

        std::cout << "I am a " << assistantType << " assistant in FMI and I teach " 
        << this->m_subject << std::endl;
    }

private:
    std::string m_subject{};
    bool m_isPartTime{};
};

class Student : public FMIPerson {
public:
    Student(const std::string& name, int age, const std::string& major, int year, int group)
        : FMIPerson(name, age), m_major(major), m_year(year), m_group(group) {}

    virtual void whoAmI() const {
        FMIPerson::whoAmI();

        std::cout << "I am a " << this->m_year << "-year student in FMI, I study " 
        << this->m_major << " and I am group " << this->m_group << std::endl;
    }

private:
    std::string m_major{};
    int m_year{};
    int m_group{};
};

class FMI {
public:
    FMI() : m_fmi{ new FMIPerson*[FMI::INITIAL_CAPACITY] }, m_size{ 0 }, m_capacity{ FMI::INITIAL_CAPACITY } {}

    FMI(const FMI& other) {
        this->copy(other);
    }

    FMI& operator=(const FMI& other) {
        if (this != &other) {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    ~FMI() {
        this->deallocate();
    }

    void addFMIPerson(const std::string& name, int age) {
        this->add(new FMIPerson{ name, age });
    }    

    void addLecturer(const std::string& name, int age, const std::string& subject, int yearsOfExperience) {
        this->add(new Lecturer{ name, age, subject, yearsOfExperience });
    }

    void addAssistant(const std::string& name, int age, const std::string& subject, bool isPartTime) {
        this->add(new Assistant{ name, age, subject, isPartTime });
    }

    void addStudent(const std::string& name, int age, const std::string& major, int year, int group) {
        this->add(new Student{ name, age, major, year, group });
    }

    void printFMI() const {
        for (std::size_t index{ 0 }; index < this->m_size; ++index) {
            this->m_fmi[index]->whoAmI();
            std::cout << "-------------------" << std::endl;
        }
    }

private:
    static const std::size_t INITIAL_CAPACITY{ 2 };
    static const std::size_t INCREASE_STEP{ 2 };

    FMIPerson** m_fmi{ nullptr };
    std::size_t m_size{};
    std::size_t m_capacity{};

    void resize() {
        FMIPerson** newFMI{ new FMIPerson*[this->m_capacity * FMI::INCREASE_STEP] };

        for (std::size_t index{ 0 }; index < this->m_size; ++index) {
            newFMI[index] = this->m_fmi[index];
        }

        delete[] this->m_fmi;
        this->m_fmi = newFMI;
        this->m_capacity *= FMI::INCREASE_STEP;
    }

    void add(FMIPerson* person) {
        if (this->m_size == this->m_capacity) {
            this->resize();
        }

        this->m_fmi[this->m_size++] = person;
    }

    void copy(const FMI& other) {
        this->m_fmi = new FMIPerson*[other.m_capacity];
        
        for (std::size_t index{ 0 }; index < other.m_size; ++index) {
            Lecturer* lecturerPtr = dynamic_cast<Lecturer*>(other.m_fmi[index]);
            Assistant* assistantPtr = dynamic_cast<Assistant*>(other.m_fmi[index]);
            Student* studentPtr = dynamic_cast<Student*>(other.m_fmi[index]);

            // dynamic_cast returns nullptr if the cast is invalid
            if (lecturerPtr) {
                this->m_fmi[index] = new Lecturer(*lecturerPtr);
            } else if (assistantPtr) {
                this->m_fmi[index] = new Assistant(*assistantPtr);
            } else if (studentPtr) {
                this->m_fmi[index] = new Student(*studentPtr);
            } else {
                this->m_fmi[index] = new FMIPerson(*other.m_fmi[index]);
            }
        }

        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
    }

    void deallocate() {
        for (std::size_t index{ 0 }; index < this->m_size; ++index) {
            delete this->m_fmi[index];
        }

        delete[] this->m_fmi;
    }
};

int main () {
    FMI fmi;

    fmi.addFMIPerson("Chicho Gosho", 50);
    fmi.addLecturer("Evgeniya Velikova", 50, "Algebra", 30);
    fmi.addAssistant("Deyan Djundrekov", 27, "Algebra", false);
    fmi.addStudent("Sonya Nikolova", 20, "KN", 2, 4);
    fmi.addStudent("Stanislav Popgeorgiev", 19, "KN", 1, 4);
    fmi.addAssistant("Peter Kolev", 20, "OOP-Practicum", true);
    fmi.addLecturer("Borislav Draganov", 40, "DIS", 20);
    fmi.addFMIPerson("Lelya Ginche", 62);

    fmi.printFMI();

    FMI fmi2 = fmi;

    std::cout << "################" << std::endl;

    fmi2.printFMI();

    return 0;
}