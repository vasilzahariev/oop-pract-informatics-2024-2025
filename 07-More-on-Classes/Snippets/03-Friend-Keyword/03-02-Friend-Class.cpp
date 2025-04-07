#include <iostream>

/* Приятелски клас
    *   Приятелски клас е клас, който има достъп до частни и защитени членове на друг клас.

    *   Приятелски клас е клас, който е деклариран като приятел на друг клас.

    *   Важно е да се отбележи, че приятелството не е двустранно. Тоест, ако клас A е приятел на клас B, 
        то клас B не е автоматично приятел на клас A.
    
    *   Класовото приятелство не е преходно. Тоест, ако клас A е приятел на клас B и клас B е приятел на клас C, 
        то клас A не е автоматично приятел на клас C.

    *   За вбъдеще ще е полезно да се знае, че приятелите не се наследяват. Тоест, ако клас A е приятел на клас B, 
        то клас C, който наследява клас B, не е автоматично приятел на клас A.
*/

class Storage {
public:
    Storage(int nValue, double dValue)
       : m_nValue{ nValue }, m_dValue{ dValue }
    { }

    // Правим Display приятел на Storage
    friend class Display;

private:
    int m_nValue{};
    double m_dValue{};
};

class Display {
public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    { }

    // Защото Display е приятел на Storage, членовете на Display могат да достъпват частните членове на Storage
    void displayStorage(const Storage& storage) const {
        if (this->m_displayIntFirst) {
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        } else { 
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
        }
    }

    void setDisplayIntFirst(bool b) {
        this->m_displayIntFirst = b;
    }

private:
    bool m_displayIntFirst{};
};

int main() {
    Storage storage{ 5, 6.7 };
    Display display{ false };

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage);

    return 0;
}
