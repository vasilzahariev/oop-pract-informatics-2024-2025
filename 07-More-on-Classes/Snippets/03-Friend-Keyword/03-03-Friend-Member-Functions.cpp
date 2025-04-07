#include <iostream>

/* Friend member functions
    *   Приятелска член фунцкия на клас е член-функция на друг клас, която има достъп до
        частни и защитени членове на класа, в който е обявена като приятел.

    *   Понякога може да не искаме цял клас да има достъп до частни членове на друг клас,
        а само определени функции. В такъв случай можем да обявим конкретна функция за приятел.
*/

// forward declaration for class Storage
class Storage;

class Display {
public:
	Display(bool displayIntFirst)
		: m_displayIntFirst { displayIntFirst }
	{ }

	void displayStorage(const Storage& storage); // forward declaration for Storage needed for reference here

private:
	bool m_displayIntFirst{};
};

// full definition of Storage class
class Storage {
public:
	Storage(int nValue, double dValue)
		: m_nValue { nValue }, m_dValue { dValue }
	{ }

	// Make the Display::displayStorage member function a friend of the Storage class
	// Requires seeing the full definition of class Display (as displayStorage is a member)
	friend void Display::displayStorage(const Storage& storage);

private:
	int m_nValue{};
	double m_dValue{};
};

int main() {
    Storage storage{ 5, 6.7 };
    Display display{ false };
    
    display.displayStorage(storage);

    return 0;
}

// Now we can define Display::displayStorage
// Requires seeing the full definition of class Storage (as we access Storage members)
void Display::displayStorage(const Storage& storage) {
	if (this->m_displayIntFirst) {
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    } else {
        std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
}
