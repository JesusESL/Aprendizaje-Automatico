#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include "kMeans.h"
#include "datos.h"
using namespace std;


int main(int argc, char *argv[]){
	srand (time(NULL));
	kMeans kmeans(totalClusters, numeroDatos, totalDatos);
	kmeans.inicializar();
	kmeans.entrenar();
	return 0;
}

