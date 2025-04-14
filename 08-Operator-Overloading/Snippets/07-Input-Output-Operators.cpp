#include <iostream>

class Point {
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
      : m_x{x}, m_y{y}, m_z{z} {}

    friend std::istream& operator>> (std::istream& out, Point& point);
    friend std::ostream& operator<< (std::ostream& out, const Point& point);

private:
    double m_x{};
    double m_y{};
    double m_z{};
};

int main() {
    std::cout << "Enter a point: ";

    Point point{ 1.0, 2.0, 3.0 };
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}

/* Бърза версия, която върши работа, но не гарантира коректност на входа:

std::istream& operator>> (std::istream& in, Point& point) {
    in >> point.m_x >> point.m_y >> point.m_z;

    return in;
}

*/

std::istream& operator>> (std::istream& in, Point& point) {
    double x{};
    double y{};
    double z{};

    in >> x >> y >> z;
    
    /* Може и ръчно да си проверим дали няма други условия (примерно може да искаме само позитивни координати):

    if (x < 0.0 || y < 0.0 || z < 0.0) {
        in.setstate(std::ios_base::failbit); // set failure mode manually
    }

    */

    // Проверяваме дали всичко е било прочетено коректно (тоест входният поток не е в режим на грешка)
    point = in ? Point{x, y, z} : Point{};

    return in;
}

std::ostream& operator<< (std::ostream& out, const Point& point) {
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}
