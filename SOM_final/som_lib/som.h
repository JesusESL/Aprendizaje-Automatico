/// Autor: Víctor Uc Cetina (uccetina@uady.mx)
#ifndef SOM_H_
#define SOM_H_

#include <vector>
using namespace std;

class SOM
{
	private:
		const float alfa;
		const unsigned int numEpocas;
		double radii;
		double time0;
		double neighbourhoodRadius;
		double learningRate;
		vector< vector<float> > pesos;
		vector< vector<float> > ejemplos;
		vector<int> bmu;
		unsigned int numNeuronas;
		unsigned int numNeuronasM;
		unsigned int numNeuronasN;
		unsigned int numRenglones;
		unsigned int numColumnas;
		unsigned int numEntradas;
		short dimensionSOM;
		unsigned int numEjemplos;

	public:
		SOM(const float _alfa, const unsigned int numEpocas, unsigned int _numNeuronas, double _radii);
		SOM(const float _alfa, const unsigned int numEpocas, unsigned int _numNeuronasM, unsigned int _numNeuronasN, double _radii, double _time0);
		void leeEjemplos(string directorioDatos, string archDatos);
		void printEjemplos();
		void generaPesos();
		void entrena();
		void epoca(double m_neighbourhoodRadius, double m_learningRate, unsigned int epocas);
		float distancia(const vector<float> & vec1, const vector<float> & vec2);
		void actualizaPesos(int idxNeurona, int idxEjemplo, double m_learningRate, double m_influence);

};

#endif
