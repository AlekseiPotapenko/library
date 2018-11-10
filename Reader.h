#include <iostream>

class Reader {
public:
	int ID;   // порядковый номер
	char SN[30]= {' '};
	char FN[30]= {' '};
	int year = 0;
	int month = 0;
	int day = 0;
	int numberOfBooks = 0;
	int books[5]; // массив с порядковыми номерами книг
	void show ();
	};
