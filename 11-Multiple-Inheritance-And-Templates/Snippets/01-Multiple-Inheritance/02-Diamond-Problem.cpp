#include <iostream>

/*  Диамантен проблем
    *   Най-популярния проблем с множественото наследяване е т.нар. "диамантен проблем".
        Той възниква, когато един наследник клас (3то ниво наследник) наследява от два или повече родителски класа, 
        които от своя страна наследяват от един и същ базов клас.
        В този случай, ако класа 3то ниво наследник се опита да достъпи член на най-базовият клас, 
        компилатора не знае от кой от базовите класа да вземе информацията.
        За да избегне неяснотата, компилатора генерира грешка.

    *   Името "диамантен проблем" идва от формата на наследяването, която прилича на диамант.
                PoweredDevice
                  /      \
                 /        \
              Scanner   Printer
                 \        /
                  \      /
                   Copier

    *   В примера по-долу, класовете Scanner и Printer наследяват от PoweredDevice.
        Когато създадем обект от класа Copier ще се създадат два обекта от PoweredDevice. Това е проблем,
        защото не знаем кой от двата обекта да използваме.
*/

/*  Виртуален базов клас
    *   Виртуалния базов клас позволява да имаме само един базов обект.
        Този базов обект е споделен в цялото дърво на наследяване и се конструира само веднъж.
        За да направим базовия клас виртуален, просто добавяме ключовата дума virtual преди името на класа.
        
    *   Синтаксис:
            class DerivedClass : virtual public BaseClass {
                // ...
            };
    
    *   Виртуалния базов клас е решение на диамантения проблем.
        
    *   При употреба на виртуален базов клас отговорник за създаването
        на най-базовия клас (PoweredDevice) е конструктора на най-долния клас (Copier).
        Важно е да се отбележи, че това е единственият път, в който конструкторът на Copier
        ще може да извика конструктора на недиректен реодител.
*/

class PoweredDevice {
public:
    PoweredDevice(int power) {
		std::cout << "PoweredDevice: " << power << '\n';
    }

    virtual ~PoweredDevice() {
        std::cout << "~PoweredDevice()\n";
    }
};

class Scanner: virtual public PoweredDevice { // PoweredDevice вече е виртуален базов клас
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power } { // Този ред е необходим за създаването на Scanner обекти, но в случая е игнориран
		std::cout << "Scanner: " << scanner << '\n';
    }

    virtual ~Scanner() {
        std::cout << "~Scanner()\n";
    }
};

class Printer: virtual public PoweredDevice { // PoweredDevice вече е виртуален базов клас
public:
    Printer(int printer, int power)
        : PoweredDevice{ power } { // Този ред е необходим за създаването на Scanner обекти, но в случая е игнориран
		std::cout << "Printer: " << printer << '\n';
    }

    virtual ~Printer() {
        std::cout << "~Printer()\n";
    }
};

class Copier: public Scanner, public Printer {
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, // Тука създаваме PoweredDevice обекта
        Scanner{ scanner, power }, Printer{ printer, power } {
        std::cout << "Copier: " << scanner << ", " << printer << '\n';
    }

    virtual ~Copier() {
        std::cout << "~Copier()\n";
    }
};

int main() {
    Copier copier{ 1, 2, 3 };

    return 0;
}
