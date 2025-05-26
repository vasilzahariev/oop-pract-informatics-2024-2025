#include <iostream>
#include "Array.h"

int main() {
	constexpr int length { 12 };
	Array<int> intArray { length };
	Array<double> doubleArray { length };

	for (int index{ 0 }; index < length; ++index) {
		intArray[index] = index;
		doubleArray[index] = index + 0.5;
	}

	for (int index{ length - 1 }; index >= 0; --index) {
        std::cout << intArray[index] << '\t' << doubleArray[index] << '\n';
    }

    doubleArray.erase();
    std::cout << "After erasing doubleArray, its length is: " << doubleArray.getLength() << '\n';

	return 0;
}