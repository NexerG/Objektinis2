run:
	main.o sortingas.o ivestis.o isvestis.o skaiciavimas.o
	g++ MokiniuVidurkiuSkaiciuokle.cpp sortingas.cpp ivestis.cpp isvestis.cpp skaiciavimas.cpp -o run

sortingas.o: sortingas.cpp
	g++ -c sortingas.cpp

ivestis.o: ivestis.cpp
	g++ -c ivestis.cpp

isvestis.o: isvestis.cpp
	g++ -c isvestis.cpp

skaiciavimas.o: skaiciavimas.cpp
	g++ -c skaiciavimai.cpp

main.o: MokiniuVidurkiuSkaiciuokle.cpp
	g++ -c MokiniuVidurkiuSkaiciuokle.cpp

clean: rm *.o run