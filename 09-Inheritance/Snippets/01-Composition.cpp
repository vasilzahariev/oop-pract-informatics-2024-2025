#include <iostream>

/*  Композиция
    *   Компоизицията е една от основните видове съотношения между обекти в C++. Това се води "has-a" отношение.
    *   Тя е вид асоциация, при която един клас (композитен клас) съдържа обекти на друг клас (компонентни класове).
    *   Това е полезно, когато искаме да изградим сложни структури от по-прости компоненти.
    *   Например, можем да имаме клас "Triangle", който съдържа три обекта от клас "Point2D".
*/

class Point2D {
public:
    Point2D() {
        std::cout << "Point2D::Point2D() called" << std::endl;
    }

    Point2D(int x, int y) : m_x{ x }, m_y{ y } {
        std::cout << "Point2D::Point2D(int x, int y) called" << std::endl;
    }

    ~Point2D() {
        std::cout << "Point2D::~Point2D() called" << std::endl;
    }

private:
    int m_x{};
    int m_y{};
};

class Triangle {
public:
    Triangle() {
        std::cout << "Triangle::Triangle() called" << std::endl;
    }
   
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        :   m_a{ x1, y1 },
            m_b{ x2, y2 },
            m_c{ x3, y3 } {
        std::cout << "Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) called" << std::endl;
    }

    ~Triangle() {
        std::cout << "Triangle::~Triangle() called" << std::endl;
    }

private:
    Point2D m_a{};
    Point2D m_b{};
    Point2D m_c{};
};

int main () {
    Triangle triangleOnStack;
    // Triangle triangleWithParameters(1, 2, 3, 4, 5, 6);

    // Triangle* dynamicallyAllocatedTriangle = new Triangle();

    return 0;
}