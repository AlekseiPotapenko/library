#include <iostream>
#include <iomanip> // для манипуляторов cout

#include "Book.h"

void charline (int num, char ch);

	void Book::show () {
		std::cout << std::setw(5) << std::left << ID << std::setw(20)<< std::left << authorSN
						<< std::setw(20)<< std::left << authorFN
						<< std::setw(5)<< std::left << year << std::setw(6)<< std::left << count
						<< std::left << title << std::endl;
		charline (80, '-');
	};
