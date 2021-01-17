Tourney: main.o game.o menu.o character.o harrypotter.o barbarian.o vampire.o bluemen.o medusa.o doublelink.o node.o
	g++ main.o game.o menu.o character.o harrypotter.o barbarian.o vampire.o bluemen.o medusa.o doublelink.o node.o -o Tourney

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

character.o: character.cpp
	g++ -c character.cpp
	
barbarian.o: barbarian.cpp
	g++ -c barbarian.cpp

vampire.o: vampire.cpp
	g++ -c vampire.cpp

harrypotter.o: harrypotter.cpp
	g++ -c harrypotter.cpp

bluemen.o: bluemen.cpp
	g++ -c bluemen.cpp

medusa.o: medusa.cpp
	g++ -c medusa.cpp

doublelink.o: doublelink.cpp
	g++ -c doublelink.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	rm *.o Tourney
