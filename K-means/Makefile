all: kmeans

kmeans: main.o cluster.o kMeans.o point.o
	g++ main.o cluster.o kMeans.o point.o -o kmeans

main.o: main.cpp
	g++ -c main.cpp

cluster.o: cluster.cpp
	g++ -c cluster.cpp

kMeans.o: kMeans.cpp
	g++ -c kMeans.cpp
	
point.o: point.cpp
	g++ -c point.cpp

clean:
	rm -rf *o kmeans
