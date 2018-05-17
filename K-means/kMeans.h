#ifndef KMEANS_H
#define KMEANS_H

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "cluster.h"
#include "point.h"
#include "datos.h"
using namespace std;

class kMeans{
private:
	int totalClusters;
	int numeroDatos;
	int totalDatos;
	vector<point> points;
	vector<cluster> clusters;
public:
	kMeans(int totalClusters, int numeroDatos, int totalDatos);
	void inicializar();
	double getDistancia(point p, cluster c);
	void entrenar();
};

#endif
