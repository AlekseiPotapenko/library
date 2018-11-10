#include <vector>
#include <fstream>
#include <cstring>  // сравнения строк
#include <string.h>
#include <cstdio>
#include <iostream>
#include <iomanip> // для манипуляторов cout
#include "Book.h"
#include "Reader.h"

#define fieldBook 6 // количество полей класса Книга
#define fieldReader 12 // количество полей класса Читатель

//------------------------------------------------------------------------------
 // Объявления функций
void charline (int num, char ch); // рисует линию из заданного char
void outputBooks(); // выводит шапку для вывода книг
void outputReaders(); // выводит шапку для вывода читателей
int sizeOfBookVector (); // определяем кол-во книг в базе
int sizeOfReaderVector (); // определяем кол-во читателей в базе
void createBooksVector (Book * Books); // загружаем базу книг в ОЗУ
void createReadersVector (Reader * Readers); // загружаем базу читателей в ОЗУ
void backupBooksVector (Book * Books, int & n); // бэкапим базу книг в файл
void backupReadersVector (Reader * Readers, int & m); // бэкапим базу читателей в файл
void showAllBooks (Book * Books, int & n); // показываем доступные книги
void showAllReaders (Reader * Readers, int & m); // показываем всех читателей
void findBook (Book * Books, int & n); // ищем книгу
void findReader (Reader * Readers, int & m); // ищем читателя
void addBook (Book * Books, int & k);  // добавляем новую книгу
void addReader (Reader * Readers, int & m);  // добавляем нового читателя
void readersBooks (Reader * Readers, Book * Books, int m);  // отобразить книги читателя
void issueBook (Reader * Readers, Book * Books);  // выдать книгу
void returnBook (Reader * Readers, Book * Books); // возврат книги

void menudraw (){ // отрисовка меню
	charline (80, '=');
	std::cout<< std::setw(69) << std::left << "1. List of all books" << '|'
					<< std::setw(10) << std::right << "enter 1 " << std::endl;
	std::cout<< std::setw(69) << std::left <<"2. List of all readers" << '|'
					<< std::setw(10) << std::right << "enter 2 " << std::endl;
	std::cout<< std::setw(69) << std::left <<"3. Search book" << '|'
					<< std::setw(10) << std::right << "enter 3 " << std::endl;
	std::cout<< std::setw(69) << std::left <<"4. Search reader" << '|'
					<<  std::setw(10) << std::right << "enter 4 " << std::endl;
	std::cout<< std::setw(69) << std::left<< "5. Add a book" << '|'
					<< std::setw(10) << std::right << "enter 5 " << std::endl;
	std::cout<< std::setw(69) << std::left<< "6. Add a reader" << '|'
					<< std::setw(10) << std::right << "enter 6 " << std::endl;
	std::cout<< std::setw(69) << std::left<< "7. Issue a book to the reader" << '|'
					<< std::setw(10) << std::right << "enter 7 " << std::endl;
	std::cout<< std::setw(69) << std::left<< "8. Return a book from the reader" << '|'
					<< std::setw(10) << std::right << "enter 8 " << std::endl;
	std::cout<< std::setw(69) << std::left<< "9. Reader's Book List" << '|'
					<< std::setw(10) << std::right << "enter 9 " << std::endl;
	charline (80, '=');
	std::cout<< std::setw(69) << std::left<< "For EXIT" << '|'
					<< std::setw(10) << std::right << "enter 0 " << std::endl;
	charline (80, '=');
	}

int main () {
//------------------------------------------------------------------------------
// Приветствие
	system("cls");
	charline (80, '=');
	std::cout<< "Welcome to the program 'Library' version 0.7 beta." << std::endl;
	charline (80, '=');
	system("pause");
	system("cls");

//------------------------------------------------------------------------------
// Инициализация библиотеки
	int n = sizeOfBookVector();
	std::cout << n << " books in library." << std::endl;
	int m = sizeOfReaderVector();
	std::cout << m << " readers in library." << std::endl;
	if ( m < 0 || n < 0 ) { // закрываем программу, если нет файлов БД
		charline (80, '=');
		std::cout<< "Books.txt or Readers.txt files were not found" << '\n'
						<< "in the root directory of the program!" << std::endl;
		charline (80, '=');
		system("pause");
		return -1;
		}

	std::vector<Book> Books(n+10);
	Book  * ptrBooks = &Books[0];
	std::vector<Reader> Readers(n+10);
	Reader  * ptrReaders = &Readers[0];
	createBooksVector(ptrBooks);
	createReadersVector(ptrReaders);

//------------------------------------------------------------------------------
// Отрисовка меню
int work = 1;
while (work) {

	menudraw ();

//------------------------------------------------------------------------------
// Определение нужной пользователю функции
	char temp[50] = {};
	int ch= 10;
	back: std::cout << "Enter your choice: ";
	std::cin >> temp;
	if (isdigit(temp[0])) {  // проверка ввода цифры
		ch = atoi (temp); // перевод строки в число
		} else goto back;
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	if (ch == 1) showAllBooks (ptrBooks, n);
	if (ch == 2) showAllReaders (ptrReaders, m);
	if (ch == 3) findBook (ptrBooks, n);
	if (ch == 4) findReader (ptrReaders, m);
	if (ch == 5) addBook(ptrBooks, n);
	if (ch == 6) addReader (ptrReaders, m);
	if (ch == 7) issueBook (ptrReaders, ptrBooks);
	if (ch == 8) returnBook (ptrReaders, ptrBooks);
	if (ch == 9) readersBooks (ptrReaders, ptrBooks, m);
	if (ch == 0) work = 0;
		else { // если число не в диапазоне, обнуляемся
			system("cls");
			};
	}

//------------------------------------------------------------------------------
// Бэкап библиотеки и выход из программы
	system("cls");
	backupReadersVector(ptrReaders, m);
	backupBooksVector(ptrBooks, n);

	charline (80, '=');
	std::cout<< "***** GOOD BYE *****" << std::endl;
	charline (80, '=');
	system("pause");
	return 0;
}
