#include <iostream>
#include <iomanip> // для манипуляторов cout

#include "Reader.h"

void charline (int num, char ch);

void Reader::show () {
	std::cout << std::setw(5) << std::left << ID << std::setw(30)<< std::left << SN
					<< std::setw(30)<< std::left << FN
					<< std::setw(3)<< std::left << day
					<< std::setw(3)<< std::left << month
					<< std::setw(5)<< std::left << year
					<< std::setw(5)<< std::left << numberOfBooks
					<< std::endl;
	charline (80, '-');
	};
