CXX = g++ -std=c++11

output: main.o menu.o Gameplay.o Space.o Ocean.o Beach.o Forest.o Volcano.o
	$(CXX) main.o menu.o Gameplay.o Space.o Ocean.o Beach.o Forest.o Volcano.o -o output

main.o: main.cpp
	$(CXX) -c main.cpp
	
menu.o: menu.hpp menu.cpp
	$(CXX) -c menu.cpp

Gameplay.o: Gameplay.hpp Gameplay.cpp
	$(CXX) -c Gameplay.cpp

Space.o: Space.hpp Space.cpp
	$(CXX) -c Space.cpp

Ocean.o: Ocean.hpp Ocean.cpp
	$(CXX) -c Ocean.cpp

Beach.o: Beach.hpp Beach.cpp
	$(CXX) -c Beach.cpp

Forest.o: Forest.hpp Forest.cpp
	$(CXX) -c Forest.cpp

Volcano.o: Volcano.hpp Volcano.cpp
	$(CXX) -c Volcano.cpp

clean:
	rm *.o output.exe

