#include <iostream>
#include <cassert>

class Matrix {
public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();

private:
    double m_data[4][4]{};
};

int main() {
    Matrix matrix{};
    matrix(1, 2) = 4.5;

    std::cout << matrix(1, 2) << '\n';

    matrix();

    std::cout << matrix(1, 2) << '\n';

    return 0;
}

double& Matrix::operator()(int row, int col) {
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return this->m_data[row][col];
}

double Matrix::operator()(int row, int col) const {
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return this->m_data[row][col];
}

void Matrix::operator()() {
    for (int row{ 0 }; row < 4; ++row) {
        for (int col{ 0 }; col < 4; ++col) {
            this->m_data[row][col] = 0.0;
        }
    }
}
