somlib_path=../som_lib

all: som

som: som_main.o som.o
	g++ som_main.o som.o -o som

som_main.o: som_main.cpp
	g++ -c som_main.cpp

som.o: $(somlib_path)/som.cpp
	g++ -c $(somlib_path)/som.cpp

clean:
	rm -rf *o som
