CPPOPT=-std=c++17 -Wall -pedantic -Wextra

all: 340.exe 088.exe

340.exe: 340.cpp
	g++ $(CPPOPT) 340.cpp -o 340.exe

088.exe: 088.cpp
	g++ $(CPPOPT) 088.cpp -o 088.exe

clean:
	rm 088.exe 340.exe

