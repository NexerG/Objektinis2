run: main.o sortingas.o ivestis.o isvestis.o skaiciavimas.o
	g++ main.cpp sortingas.cpp ivestis.cpp isvestis.cpp skaiciavimas.cpp -o run

sortingas.o: sortingas.cpp
	g++ -c sortingas.cpp

ivestis.o: ivestis.cpp
	g++ -c ivestis.cpp

isvestis.o: isvestis.cpp
	g++ -c ivestis.cpp

skaiciavimas.o: skaiciavimas.cpp
	g++ -c skaiciavimas.cpp

Validacija.o: validacija.cpp
	g++ -c validacija.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: rm *.o run