/// Autor: Víctor Uc Cetina (uccetina@uady.mx)
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "../som_lib/som.h"
using namespace std;
/// SOM bidimensional
const float _alfa = 0.1;
const unsigned int _numEpocas = 2;
unsigned int _numNeuronasM = 10;
unsigned int _numNeuronasN = 10;
double _radii;
double _time0;

int main()
{
	_radii = max(_numNeuronasM, _numNeuronasN)/2;
	_time0 = _numEpocas/log(_radii);
	//_time0 = _numEpocas;
	SOM algo(_alfa, _numEpocas, _numNeuronasM, _numNeuronasN, _radii, _time0);
	algo.leeEjemplos("../datos/","f2.txt");
	//algo.printEjemplos();
	algo.entrena();

	return 0;
}
