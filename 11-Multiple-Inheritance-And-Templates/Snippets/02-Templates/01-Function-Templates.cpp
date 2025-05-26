#include <iostream>
#include <string>

/*  Шаблони
    *   В C++ има начин за улесняване на създаването на функции (или класове), които могат да работят с различни типове данни.
        Този начин се нарича шаблони (templates).

    *   Шаблоните позволяват да пишем код, който описва как изглежда функция или клас независимо от типовете данни, които ще използва.
        Това позволява да не пишем множество функции или класове, които са почти идентични, но работят с различни типове данни.

    *   В шаблоните може да се използва един или повечете заместители на типове (placeholder types).
        Заместителният тип представлява тип, който не е известен в момента на дефиниране на шаблона, 
        но ще бъде предоставен по-късно, когато шаблонът се използва.
*/

/*  Шаблонни функции
    *   Шаблноните функции са специален вид функции, които могат да работят с различни типове данни.
        Те се дефинират с помощта на ключовата дума `template`, последвана от списък с параметри на шаблона.
    
    *   Първоначалната шаблнонна функция, която се използва за генериране на други функции, се нарича основен шаблон (primary template).
        Функциите, генерирани от основния шаблон, се наричат инстанциирани функции (instantiated functions).

    *   Когато създаваме основен шаблон на функция, използваме заместители на типове (type template parameters) за всички параметри,
        типове на връщане или типове, използвани в тялото на функцията, които искаме да бъдат зададени по-късно от потребителя на шаблона.

    *   В C++ има 3 вида шаблонни параметри:
        1. Типови шаблонни параметри (Type Template Parameters) - използват се за заместване на типове данни.
        2. Неномерирани шаблонни параметри (Non-type Template Parameters) - използват се за заместване на стойности, които не са типове.
        3. Шаблонни параметри на шаблони (Template Template Parameters) - използват се за заместване на други шаблони.
*/

class ComparableClass {
public:
    ComparableClass(int value) : m_value(value) {}

    bool operator>(const ComparableClass& other) const {
        return this->m_value > other.m_value;
    }

    friend std::ostream& operator<<(std::ostream& os, const ComparableClass& obj) {
        os << "ComparableClass(" << obj.m_value << ")";

        return os;
    }

private:
    int m_value{};
};

template <typename T>
T maxVal(T first, T second) {
    std::cout << "maxVal<T>(T, T)" << std::endl;

    return (first > second) ? first : second;
}

int maxVal(int first, int second) {
    std::cout << "maxVal(int, int)" << std::endl;

    return (first > second) ? first : second;
}

template <typename T>
void printWithNewLine(T value);

int main() {
    printWithNewLine<int>(maxVal<int>(10, 20)); // Извиква maxVal<T>(T, T) с int
    printWithNewLine<>(maxVal<>(10, 20)); // Извежда, че типът е int и извиква maxVal<T>(T, T) с int
    printWithNewLine<int>(maxVal(10, 20)); // Извиква maxVal(int, int)
    std::cout << std::endl;
    // Предпочитайте да извиквате шаблонните функции като нормални функции, 
    // освен ако не искате да укажете конкретен тип или да сте сигурни, че се извиква точно тази версия на функцията.

    printWithNewLine(maxVal(10.5, 20.5)); // Извикване с double
    std::cout << std::endl;

    printWithNewLine(maxVal('A', 'B')); // Извикване с char
    std::cout << std::endl;

    printWithNewLine<std::string>(maxVal<std::string>("apple", "banana")); // Извикване с string
    // printWithNewLine(maxVal("apple", "banana")); // Ако не укажем типа, компилаторът ще се опита да го изведе автоматично и в този случай ще бъде char*
    std::cout << std::endl;

    printWithNewLine(maxVal(ComparableClass(10), ComparableClass(20))); // Извикване с ComparableClass

    return 0;
}

template <typename T>
void printWithNewLine(T value) {
    std::cout << value << std::endl;
}
