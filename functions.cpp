#include <fstream>
#include <vector>
#include <cstring>
#include <string.h>
#include <iostream>
#include <iomanip> // для манипуляторов cout
#include "Book.h"
#include "Reader.h"

#define fieldBook 6 // количество полей класса Книга
#define fieldReader 12 // количество полей класса Читатель

void charline (int num, char ch) { // рисует линию из заданного char
	for(int j = 0; j < num; j++)
		std::cout << ch;
	std::cout << std::endl;
	}

void outputBooks(){ // выводит шапку для вывода книг
	charline (80, '=');
	std::cout<< std::setw(5) << std::left << "ID" << std::setw(40)<< std::left << "Author"
					<< std::setw(5)<< std::left << "Year" << std::setw(6)<< std::left << "Count"
					<< std::setw(40)<< std::left << "Title"<< std::endl;      //std::right
	charline (80, '=');
	}

void outputReaders(){ // выводит шапку для вывода читателей
	std::cout << std::endl;
	charline (80, '=');
	std::cout<< std::setw(5) << std::left << "ID" << std::setw(60)<< std::left << "Reader"
					<< std::setw(11)<< std::left << "DOB" << std::setw(4)<< std::left << "Book"
					<< std::endl;      //std::right
	charline (80, '=');
	}

int sizeOfBookVector () { // определяем кол-во книг в базе
	char line[40];
	int i = 0;
	std::ifstream sizeOfBook("Books.txt", std::ios::binary);
	if (!sizeOfBook.is_open()) { // если файл не открыт
		std::cout << "File cannot be opened!\n"; // сообщить об этом
		return -1;
		}
		else {
			while (sizeOfBook){
				sizeOfBook >> line;
				i++;
				}
	//std::cout << "Books in library - " << (i/fieldBook) << std::endl;
	sizeOfBook.close();
	return i/fieldBook;
	}
	}

int sizeOfReaderVector () { // определяем кол-во читателей в базе
	char line[40];
	int i = 0;
	std::ifstream sizeOfReader("Readers.txt", std::ios::binary);
	if (!sizeOfReader.is_open()) { // если файл не открыт
		std::cout << "File cannot be opened!\n"; // сообщить об этом
		return -1;
		}
		else {
			while (sizeOfReader){
				sizeOfReader>> line;
				i++;
				}
	//std::cout << "Books in library - " << (i/fieldBook) << std::endl;
		sizeOfReader.close();
		return i/fieldReader;
		}
	}

void createBooksVector (Book * Books) { // загружаем базу книг в ОЗУ
	char temp[40]="ololo";
	int i = 0; // счетчик книг
	std::ifstream create("Books.txt", std::ios::in | std::ios::binary);
	while (create){
		create.getline(temp, 40);
		Books[i].ID = atoi(temp);
		create.getline(Books[i].authorSN, 40);
		create.getline(Books[i].authorFN, 40);
		create.getline(temp, 40);
		Books[i].year = atoi(temp);
		create.getline(temp, 40);
		Books[i].count = atoi(temp);
		create.getline(Books[i].title, 40);
		i++;
		}
	create.close();
	std::cout << "Load Books complete!" << std::endl;
	}

void createReadersVector (Reader * Readers) { // загружаем базу читателей в ОЗУ
	char temp[30]="ololo";
	int i = 0; // счетчик книг
	std::ifstream createR("Readers.txt", std::ios::in | std::ios::binary);
	while (createR){
		createR.getline(temp, 30);
		Readers[i].ID = atoi(temp); // заносим ID
		createR.getline(Readers[i].SN, 30);  // заносим фамилию
		createR.getline(Readers[i].FN, 30); // заносим имя
		createR.getline(temp, 30);
		Readers[i].year = atoi(temp); // заносим год
		createR.getline(temp, 30);
		Readers[i].month = atoi(temp); // заносим месяц
		createR.getline(temp, 30);
		Readers[i].day = atoi(temp); // заносим день
		createR.getline(temp, 30);
		Readers[i].numberOfBooks = atoi(temp); // заносим кол-во книг
		createR.getline(temp, 30);
		Readers[i].books[0] = atoi(temp); // заносим ID книг
		createR.getline(temp, 30);
		Readers[i].books[1] = atoi(temp);
		createR.getline(temp, 30);
		Readers[i].books[2] = atoi(temp);
		createR.getline(temp, 30);
		Readers[i].books[3] = atoi(temp);
		createR.getline(temp, 30);
		Readers[i].books[4] = atoi(temp);
		i++;
		}
	createR.close();
	std::cout << "Load Readers complete!" << std::endl;
	}

void backupBooksVector (Book * Books, int & n) { // бэкапим базу книг в файл
	std::ofstream backup("Books.txt", std::ios::binary | std::ios::trunc);

	for (int i = 0; i < n; i++) {
		backup << Books[i].ID <<'\n';
		backup << Books[i].authorSN <<'\n';
		backup << Books[i].authorFN <<'\n';
		backup << Books[i].year <<'\n';
		backup << Books[i].count <<'\n';
		backup << Books[i].title <<'\n';
		}
	backup.close();
	charline (80, '=');
	std::cout <<"Backup books complete!" << std::endl;
	}

void backupReadersVector (Reader * Readers, int & m) { // бэкапим базу читателей в файл
	std::ofstream backupR("Readers.txt", std::ios::binary | std::ios::trunc);
	for (int i = 0; i < m; i++) {
		backupR << Readers[i].ID <<'\n';
		backupR << Readers[i].SN <<'\n';
		backupR << Readers[i].FN <<'\n';
		backupR << Readers[i].year <<'\n';
		backupR << Readers[i].month <<'\n';
		backupR << Readers[i].day <<'\n';
		backupR << Readers[i].numberOfBooks <<'\n';
		backupR << Readers[i].books[0] <<'\n';
		backupR << Readers[i].books[1] <<'\n';
		backupR << Readers[i].books[2] <<'\n';
		backupR << Readers[i].books[3] <<'\n';
		backupR << Readers[i].books[4] <<'\n';
		}
	backupR.close();
	charline (80, '=');
	std::cout <<"Backup readers complete!" << std::endl;
	}

void showAllBooks (Book * Books, int & n) { // показываем доступные книги
	outputBooks();
		if (0 == n) {
		std::cout << "No books in database." << '\n' << std::endl;
		system("pause");
		return;
		}
	for (int i = 0; i < n; i++) Books[i].show();
	//charline (80, '*');
	//std::cout << "Listing complete!" << std::endl;
	system("pause");
	}

void showAllReaders (Reader * Readers, int & m) { // показываем всех читателей
	outputReaders();
	if (0 == m) {
		std::cout << "No readers in database." << '\n' << std::endl;
		system("pause");
		return;
		}
	for (int i = 0; i < m; i++) Readers[i].show();
	//charline (80, '*');
	//std::cout << "Listing complete!" << std::endl;
	system("pause");
	}

void findBook (Book * Books, int & n) { // ищем книгу
	charline (80, '=');
	std::cout << "***** Search book in the library *****" << std::endl;
	charline (80, '=');
	std::cout << "Enter the author's last name or name or book title, max 40 char:" << std::endl;
	char info[40]= {};
	char info1[40]= {};
	int count = 0;
	//gets(info);
	std::cin.getline(info1, 40);   // для работы поиска по нескольким словам
	for ( int i = 0 ; i< 40; i++) {
		if (info1[i] == '\0') break;
		info[i] = info1[i];
		}

	//std::cout << "info = " << info << std::endl;  // отладочный cout
	outputBooks();  // рисуем шапку
	for (int i = 0; i < n; i++) {
		if (strcmp(Books[i].authorSN, info)==0) { Books[i].show(); count ++; continue; }
		if (strcmp(Books[i].authorFN, info)==0) { Books[i].show(); count ++; continue; }
		if (strcmp(Books[i].title, info)==0) { Books[i].show(); count ++; continue; }
		}
	if (count == 0) std::cout << "Book with such data is not found!" << '\n' << std::endl;
	//charline (80, '*');
	system("pause");
	}

void findReader (Reader * Readers, int & m) { // ищем читателя
	charline (80, '=');
	std::cout << "***** Search reader in the library *****" << std::endl;
	charline (80, '=');
	std::cout << "Enter the reader's last name or his name: ";
	std::vector <int> ids {};
	char info[25];
	int count = 0;
	gets(info);
	outputReaders();
	for (int i = 0; i < m; i++) {
		if (strcmp(Readers[i].SN,info) == 0) { Readers[i].show(); count ++; continue; }
		if (strcmp(Readers[i].FN,info) == 0) { Readers[i].show(); count ++; continue; }
		}

	if (count == 0) {
		std::cout << "Readers with such data is not found!" << '\n' << std::endl;
		charline (80, '-');
		}
	system("pause");
	}

void addBook (Book * Books, int & k) {  // добавляем новую книгу
	charline (80, '=');
	std::cout << "***** Adding a book to the library *****" << std::endl;
	charline (80, '=');

	Book temp;

	std::cout << "Enter author's second name, max. 20 char: ";
	gets(temp.authorSN);
	std::cout << "Enter author's first name, max. 20 char: ";
	gets(temp.authorFN);
	std::cout << "Enter title, max. 40 char: ";
	gets(temp.title);
	std::cout << "Enter year of publishing: ";
	std::cin >> temp.year;
	std::cout << "Enter the number of copies of the book: ";
	std::cin >> temp.count;

	char temp1[50] = {};
	back: std::cout << "Confirm your entries, y/n: ";
	std::cin >> temp1;
	if (isdigit(temp1[0])) {  // Подтверждение
		goto back;
		} else {
			if (temp1[0] != 'y') return; }
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	int m = k;
	int pointer = m;
	for (int i = 0; i < m; i++) {   // ищем совпадения в базе, при совпадении добавляем экземпляры
		if (strcmp(Books[i].authorSN, temp.authorSN) != 0) { pointer--; continue; }
		if (strcmp(Books[i].authorFN, temp.authorFN) != 0) { pointer--; continue; }
		if (strcmp(Books[i].title, temp.title) == 0) {
			charline (80, '*');
			std::cout << "The book is already in the library!" << '\n'
							<< "The specified number of copies of the book has been added." << std::endl;
			outputBooks();  // рисуем шапку
			Books[i].count += temp.count;
			Books[i].show();
			break;
			}
			else { pointer--; continue; }
		}

	if (pointer == 0) { // если книга не найдена, вносим
				k += 1;   // увеличиваем счетчик книг на 1
				temp.ID = k;
				Books[k-1].ID = temp.ID;
				for (int j = 0; j < 19; j++){
					if (temp.authorSN[j] == '\0') break;
					Books[k-1].authorSN[j] = temp.authorSN[j]; }
				for (int j = 0; j < 19; j++){
					if (temp.authorFN[j] == '\0') break;
					Books[k-1].authorFN[j] = temp.authorFN[j]; }
				Books[k-1].year = temp.year;
				Books[k-1].count = temp.count;
				for (int j = 0; j < 39; j++){
					if (temp.title[j] == '\0') break;
					Books[k-1].title[j] = temp.title[j]; }

				charline (80, '*');
				std::cout << "Book added to library!" << std::endl;
				}
	system("pause");
	}

void addReader (Reader * Readers, int & m) {  // добавляем нового читателя
	charline (80, '=');
	std::cout << "***** Adding a reader to the library *****" << std::endl;
	charline (80, '=');

	Reader temp;
	std::cin.clear(); // очистка потока ввода
	std::cout << "Enter reader's second name, max. 25 char: ";
	gets(temp.SN);
	std::cout << "Enter reader's first name, max. 25 char: ";
	gets(temp.FN);
	std::cout << "Enter DOB day month year, through the gap: ";
	std::cin >> temp.day >> temp.month >> temp.year;

	char temp1[50] = {};
	back: std::cout << "Confirm your entries, y/n: ";
	std::cin >> temp1;
	if (isdigit(temp1[0])) {  // Подтверждение
		goto back;
		} else {
			if (temp1[0] != 'y') return; }
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	int m_ = m;
	int pointer = m_;
	for (int i = 0; i < m_; i++) {  // ищем совпадения в базе
		if (strcmp(Readers[i].SN, temp.SN) != 0) { pointer--; continue; }
		if (strcmp(Readers[i].FN, temp.FN) != 0) { pointer--; continue; }
		if (Readers[i].year != temp.year)	{ pointer--; continue; }
		if (Readers[i].month != temp.month) { pointer--; continue; }
		if (Readers[i].day == temp.day) {
			charline (80, '*');
			std::cout << "The reader is already in the library!" << std::endl;
			outputReaders();  // рисуем шапку
			Readers[i].show();
			break;
			}
			else { pointer--; continue; }
		}

	if (pointer == 0) { // если читатель не найден, вносим в базу
		m += 1;   // увеличиваем счетчик читателей на 1
		temp.ID = m;
		Readers[m-1].ID = temp.ID;
		for (int j = 0; j < 29; j++){
			if (temp.SN[j] == '\0') break;
			Readers[m-1].SN[j] = temp.SN[j]; }
		for (int j = 0; j < 29; j++){
			if (temp.FN[j] == '\0') break;
			Readers[m-1].FN[j] = temp.FN[j]; }
		Readers[m-1].year = temp.year;
		Readers[m-1].month = temp.month;
		Readers[m-1].day = temp.day;
		charline (80, '*');
		std::cout << "Reader added to library!" << std::endl;
		}
	system("pause");
	}

void readersBooks (Reader * Readers, Book * Books, int m) {  // отобразить книги читателя
	charline (80, '=');
	std::cout << "***** Output of the list of books of the reader *****" << std::endl;
	charline (80, '=');
	if (0 == m) {
		std::cout << "No readers in database." << '\n' << std::endl;
		system("pause");
		return;
		}

	char temp[50] = {};
	int id= -1;
	back: std::cout << "Enter reader ID number: ";
	std::cin >> temp;
	if (isdigit(temp[0])) {  // ПРОВЕРКА ВВОДА  первой ЦИФРЫ
		id = atoi (temp); // перевод строки в число
		} else goto back;
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	outputReaders();
	Readers[id-1].show();  // отрисовка книг читателя
	outputBooks();
	for (int i = 0 ; i< 5; i++){
		if (Readers[id-1].books[i] != 0) Books[(Readers[id-1].books[i]) - 1].show();
		}
	system("pause");
	}

void issueBook (Reader * Readers, Book * Books) {  // выдать книгу
	charline (80, '=');
	std::cout << "***** Issuing a book to the reader *****" << std::endl;
	charline (80, '=');
	//std::cout << "Enter reader ID number: ";
	int idR = -1, idB = -1;
	//std::cin >> idR;

	char temp[50] = {};
	back: std::cout << "Enter reader ID number: ";
	std::cin >> temp;
	if (isdigit(temp[0])) {  // ПРОВЕРКА ВВОДА  первой ЦИФРЫ
		idR = atoi (temp); // перевод строки в число
		} else goto back;
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	charline (80, '-');

	back1: std::cout << "Enter book ID number: ";
	std::cin >> temp;
	if (isdigit(temp[0])) {  // ПРОВЕРКА ВВОДА  первой ЦИФРЫ
		idB = atoi (temp); // перевод строки в число
		} else goto back1;
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	if (Books[idB-1].count == 0) { // проверяем наличие книги
		std::cout << "Copies of this book are over!" << std::endl;
		charline (80, '-');
		return;
		}
	if (Readers[idR-1].numberOfBooks == 5) { // проверяем сколько книг у читателя
		std::cout << "The reader has the maximum number of books!" << std::endl;
		charline (80, '-');
		return;
		}
	for (int i = 0; i < 5; i++) { // передаем читателю книгу
		if (Readers[idR-1].books[i] == 0) {
			Readers[idR-1].books[i] = idB;
			break;
			}
		}
	Readers[idR-1].numberOfBooks++;  // увеличиваем кол-во книг у читателя
	Books[idB-1].count--;  // уменьшаем кол-во экземпляров книги

	charline (80, '=');
	std::cout << "***** The book is issued to the reader! *****" << std::endl;
	charline (80, '=');
	system("pause");
	}

void returnBook (Reader * Readers, Book * Books) { // возврат книги
	//system("cls");
	charline (80, '=');
	std::cout << "***** Return of the book from the reader *****" << std::endl;
	charline (80, '=');
	int idR = -1, idB = -1;

	char temp1[50] = {};
	back: std::cout << "Enter reader ID number: ";
	std::cin >> temp1;
	if (isdigit(temp1[0])) {  // ПРОВЕРКА ВВОДА  первой ЦИФРЫ
		idR = atoi (temp1); // перевод строки в число
		} else goto back;
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	charline (80, '-');

	back1: std::cout << "Enter book ID number: ";
	std::cin >> temp1;
	if (isdigit(temp1[0])) {  // ПРОВЕРКА ВВОДА  первой ЦИФРЫ
		idB = atoi (temp1); // перевод строки в число
		} else goto back1;
	std::cin.ignore(100, '\n');
    std::cin.clear();    // очистка буфера после ввода

	int temp = 1; // флаг обнаружения книги у читателя
	for (int i = 0; i < 5; i++) { // обнуляем поле в id книги у читателя
		if (Readers[idR-1].books[i] == idB) {
			Readers[idR-1].books[i] = 0;
			temp--;
			break;
			}
		}
	if (temp) {
		charline (80, '-');
		std::cout << "The reader does not have this book!" << std::endl;
		charline (80, '-');
		return;
		}
	Books[idB-1].count++;  // увеличиваем кол-во экземпляров книги
	Readers[idR-1].numberOfBooks--;  // уменьшаем кол-во книг у читателя

	charline (80, '=');
	std::cout << "***** Book returned to library! *****" << std::endl;
	charline (80, '=');
	system("pause");
	}
