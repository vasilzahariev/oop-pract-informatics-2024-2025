#include <iostream>
#include <string>

/*  Pure Virtual Functions
    -   C++ позволява да се дефинират специален вид виртуални функции, наречени чисто виртуални функции.
    -   Чисто виртуалните функции не разполагат с реализация в базовия клас и задължават производния клас да предостави собствена реализация.
    -   Чисто виртуалните функции се дефинират с добавяне на "= 0" в края на декларацията на функцията.
*/

/*  Абстрактни класове
    -   Абстрактен клас ще наричаме клас, който съдържа поне една чисто виртуална функция.
        Такъв тип клас не може да бъде инстанциран.
    -   Абстрактните класове служат за основа на производни класове, които предоставят конкретна реализация на чисто виртуалните функции.
*/

class Animal {
public:
    Animal(const std::string& name, int age) : m_name{ name }, m_age{ age } {}

    virtual void whoAmI() const {
        std::cout << "Name: " << this->m_name << std::endl;
        std::cout << "Age: " << this->m_age << std::endl;
    }

    virtual void makeSound() const = 0;

    virtual ~Animal() = default;

private:
    std::string m_name{};
    int m_age{};
};

class Dog : public Animal {
public:
    Dog(const std::string& name, int age) : Animal{ name, age } {}

    virtual void makeSound() const override {
        std::cout << "Bau" << std::endl;
    }

    virtual void whoAmI() const override {
        Animal::whoAmI();
        std::cout << "A am a dog" << std::endl;
    }

    virtual ~Dog() = default;
};

class Pitbull : public Dog {
public:
    Pitbull() : Dog{ "Pit", 2 } {}

    virtual void makeSound() const override final {
        std::cout << "Bau, Bau" << std::endl;
    }

    virtual void whoAmI() const override final {
        Dog::whoAmI();
        std::cout << "Pitbull" << std::endl;
    }

    virtual ~Pitbull() = default;
};

class Cat : public Animal {
public:
    Cat(const std::string& name, int age) : Animal{ name, age } {}

    virtual void makeSound() const override {
        std::cout << "Mqu" << std::endl;
    }

    virtual void whoAmI() const override {
        Animal::whoAmI();
        std::cout << "I am a cat" << std::endl;
    }

    virtual ~Cat() = default;
};

class Glarus : public Animal {
public:
    Glarus(const std::string& name, int age) : Animal{ name, age } {}

    virtual void makeSound() const override {
        std::cout << "Dai mi duneraaa" << std::endl;
    }

    virtual void whoAmI() const override {
        Animal::whoAmI();
        std::cout << "Az sam gadina" << std::endl;
    }

    virtual ~Glarus() = default;
};

int main () {
    Animal* animals[4];
    animals[0] = new Dog("Sharo", 3);
    animals[1] = new Pitbull();
    animals[2] = new Cat("Bela", 5);
    animals[3] = new Glarus("Gadina 365", 1); 

    for (int index{ 0 }; index < 4; ++index) {
        animals[index]->makeSound();
        animals[index]->whoAmI();
        std::cout << "-----------" << std::endl;
    }   

    for (int index{ 0 }; index < 4; ++index) {
        delete animals[index];
    }

    return 0;
}