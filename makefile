main : main.o functions.o
	g++ main.o functions.o -o main
main.o : main.cpp Book.h Reader.h
	g++ -c main.cpp -o main.o
functions.o : functions.cpp
	g++ -c functions.cpp -o functions.o
clean :
	del *.o main.exe
