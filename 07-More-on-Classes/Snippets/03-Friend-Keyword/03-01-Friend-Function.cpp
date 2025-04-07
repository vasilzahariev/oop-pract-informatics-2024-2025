#include <iostream>

/* Friend functions
    *   Приятелските функции имат достъп до частни членове на класовете, в които са декларирани.
    
    *   Приятелските функции не са членове на класовете, в които са декларирани.
    
    *   Приятелските функции не нарушават принципа на капсулация, защото самият клас определя
        кои функции да имат достъп до частните му членове.
*/

class Humidity; // forward declaration of Humidity

class Temperature {
public:
    explicit Temperature(int temp) : m_temp { temp } { }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity); // forward declaration needed for this line

private:
    int m_temp{ 0 };
};

class Humidity {
public:
    explicit Humidity(int humidity) : m_humidity { humidity } {  }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);

private:
    int m_humidity{ 0 };
};

int main() {
    Humidity hum{ 10 };
    Temperature temp{ 12 };

    printWeather(temp, hum);

    return 0;
}

void printWeather(const Temperature& temperature, const Humidity& humidity) {
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}
