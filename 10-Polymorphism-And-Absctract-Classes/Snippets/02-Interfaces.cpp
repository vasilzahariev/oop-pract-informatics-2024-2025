#include <iostream>
#include <cmath>

/* Интерфейс
    *   Интерфейс е абстрактен клас, който съдържа само чисто виртуални функции.
        Той не може да бъде инстанциран и служи само за дефиниране на интерфейс за производните класове.

    *   Интерфейсите се използват, когато искаме да дефинираме обща функционалност за различни класове,
        без да предоставяме конкретна реализация на функциите.
*/

class Shape {
public:
    virtual double getPerimeter() = 0;
    virtual double getArea() = 0;

    virtual ~Shape() = default;
};

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c) : m_a{ a }, m_b{ b }, m_c{ c } {}

    virtual double getPerimeter() override {
        return this->m_a + this->m_b + this->m_c;
    }

    virtual double getArea() override {
        double semiPerimeter = this->getPerimeter() / 2;
        
        return std::sqrt(semiPerimeter * (semiPerimeter - this->m_a) * 
                        (semiPerimeter - this->m_b) * (semiPerimeter - this->m_c));
    }

private:
    double m_a{};
    double m_b{};
    double m_c{};
};

class Circle : public Shape {
public:
    Circle(double r) : m_r{ r } {}

    virtual double getPerimeter() override {
        return 2 * PI * this->m_r;
    }

    virtual double getArea() override {
        return PI * this->m_r * this->m_r;
    }

private:
    static constexpr double PI{ 3.14 };
    double m_r{};
};

class Rectangle : public Shape {
public:
    Rectangle(double a, double b) : m_a{ a }, m_b{ b } {}

    virtual double getPerimeter() override {
        return 2 * (this->m_a + this->m_b);
    }

    virtual double getArea() override {
        return this->m_a * this->m_b;
    }

private:
    double m_a{};
    double m_b{};
};

int main () {
    Shape* shapes[3];
    shapes[0] = new Triangle(3, 4, 5);
    shapes[1] = new Circle(2);
    shapes[2] = new Rectangle(5, 4);

    for (int index{ 0 }; index < 3; ++index){
        std::cout << "Perimeter: " << shapes[index]->getPerimeter() << std::endl;
        std::cout << "Area: " << shapes[index]->getArea() << std::endl;
    }

    for (int index{ 0 }; index < 3; ++index) {
        delete shapes[index];
    }

    return 0;
}