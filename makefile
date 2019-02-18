
langtonsAnt: antMain.o Menu.o Ant.o
	g++ antMain.o Menu.o Ant.o -o langtonsAnt

antMain.o: antMain.cpp
	g++ -c antMain.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

clean:
	rm *.o langtonsAnt
