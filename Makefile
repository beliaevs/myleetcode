CPPOPT=-std=c++17 -Wall -pedantic -Wextra

088.exe: 088.cpp
	g++ $(CPPOPT) 088.cpp -o 088.exe

clean:
	rm 088.exe

