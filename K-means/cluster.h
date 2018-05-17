#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include <vector>
#include "point.h"
using namespace std;

#include "datos.h"

class cluster{
private:
	int id;
	int centroideNumeroCluster;
	point centralPoint;
	int totalPoints;
	vector<point> points;
public:
	cluster();
	cluster(int id, int centroideNumeroCluster, point centralPoint);
	void setCentroideNumeroCluster(int centroideNumeroCluster);
	int getCentroideNumeroCluster();
	void setCentralPoint(point centralPoint);
	point getCentralPoint();
	void setCentralValores(double valor, int i);
	double getCentralValores(int i);
	void agregarPoint(point p);
	void eliminarPoint(int i);
	int getTotalPoints();
	int getId();
	point getPoint(int i);
};

#endif
