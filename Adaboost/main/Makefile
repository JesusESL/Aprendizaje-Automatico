adalib_path=../adalib

all: ada

ada: main.o adaboost.o
	g++ main.o adaboost.o -o ada

main.o: main.cpp
	g++ -c main.cpp

adaboost.o: $(adalib_path)/adaboost.cpp
	g++ -c $(adalib_path)/adaboost.cpp

clean:
	rm -rf *o ada
