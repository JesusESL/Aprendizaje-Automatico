#ifndef POINT_H
#define POINT_H

#include "datos.h"

class point{
private:
	int id;
	double valores[numeroDatos];
	int pointNumeroCluster;
public:
	point();
	point(int id, double valores[]);
	point(double valores[], int pointNumeroCluster);
	void setValores(double valor, int i);
	double getValores(int i);
	void setPointNumeroCluster(int pointNumeroCluster);
	int getPointNumeroCluster();
	int getId();
};

#endif
