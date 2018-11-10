#include <iostream>

class Book {
public:
	int ID; // порядковый номер
	char authorSN[20]= {' '};
	char authorFN[20]= {' '};
	int year; // год издания
	int count; // количество экземпляров
	char title[40]= {' '};
	void show ();
	};
