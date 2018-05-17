/// Autor: Víctor Uc Cetina (uccetina@uady.mx)
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "som.h"
using namespace std;


SOM::SOM(const float _alfa, const unsigned int _numEpocas, unsigned int _numNeuronas, double _radii)
 : alfa(_alfa), numEpocas(_numEpocas), radii(_radii)
{
	numNeuronas = _numNeuronas;
	dimensionSOM = 1;
}

SOM::SOM(const float _alfa, const unsigned int _numEpocas, unsigned int _numNeuronasM, unsigned int _numNeuronasN, double _radii, double _time0)
 : alfa(_alfa), numEpocas(_numEpocas), radii(_radii), time0(_time0)
{
	numNeuronasM = _numNeuronasM;
	numNeuronasN = _numNeuronasN;
	numNeuronas = numNeuronasM * numNeuronasN;
	dimensionSOM = 2;
}

void SOM::leeEjemplos(string directorioDatos, string archDatos)
{
	string strArchivoDatos;
	strArchivoDatos = directorioDatos + archDatos;
	vector<float> tmpVecX;
	float floatVal;

	ifstream archivoDatos( strArchivoDatos.c_str() );
	archivoDatos >> SOM::numEjemplos;
	archivoDatos >> SOM::numEntradas;

	for(unsigned int i=0; i<SOM::numEjemplos; i++)
	{
		for(unsigned int j=0; j<SOM::numEntradas; j++)
		{
			archivoDatos >> floatVal;
			tmpVecX.push_back(floatVal);
		}
		ejemplos.push_back(tmpVecX);
		tmpVecX.clear();
	}

	generaPesos();
}

void SOM::printEjemplos()
{
	vector< vector<float> >::iterator renglon;
	vector<float>::iterator columna;

	cout << endl << "Ejemplos = " << endl << endl;
	for(renglon = ejemplos.begin(); renglon != ejemplos.end(); ++renglon)
	{
		for(columna = renglon->begin(); columna != renglon->end(); ++columna)
			cout << *columna << " ";
		cout << endl;
	}
	cout << endl;
}

void SOM::generaPesos()
{
	srand(time(0));
	vector<float> tmpVec;

	for(unsigned int i=0; i<SOM::numNeuronas; i++)
	{
		for(unsigned int j=0; j<SOM::numEntradas; j++)
			tmpVec.push_back( rand() % 2 ); // en el rango de 0 a 1
		pesos.push_back( tmpVec );
		//for(unsigned int j=0; j<SOM::numEntradas; j++)
		//	cout << endl << endl << "(" << i << ") " << "Peso = " << pesos[i][j];
		tmpVec.clear();
	}
}

void SOM::entrena()
{
	for(unsigned int epocas = 0; epocas < SOM::numEpocas; epocas++)
	{
		bmu.clear();
		SOM::neighbourhoodRadius = SOM::radii * exp(-(double)(epocas+1)/SOM::time0);
    	SOM::learningRate = SOM::alfa * exp(-(double)(epocas+1)/SOM::time0);
    	//cout << endl << endl << "(" << epocas << ") " << "neighbourhoodRadius = " << neighbourhoodRadius << " learningRate = " << learningRate;
		epoca(neighbourhoodRadius,learningRate,epocas);
		/*for(unsigned int i=0; i<SOM::numNeuronas; i++)
		{
			for(unsigned int j=0; j<SOM::numEntradas; j++)
				cout << endl << endl << "(" << i << ") " << "Peso = " << pesos[i][j];
		}*/
	}

	for(int idxEjemplo=0; idxEjemplo<SOM::numEjemplos; idxEjemplo++)
	{
		cout << endl << endl << "(" << idxEjemplo+1 << ") " << "idxNeuronaMenorDist = " << bmu[idxEjemplo];
	}
	cout << endl << endl;
}

void SOM::epoca(double m_neighbourhoodRadius, double m_learningRate, unsigned int epocas)
{
    double m_influence;
	float menorDistancia;
	float tmpDist;
	int idxNeuronaMenorDist;
	int inicio, inicioRenglon, inicioColumna;
	int fin, finRenglon, finColumna;
	int idx;
	int renNeuMenorDist=0;
	int colNeuMenorDist=0;
    int y=0,x=0;

	for(int idxEjemplo=0; idxEjemplo<SOM::numEjemplos; idxEjemplo++)
	{
		menorDistancia = 999999;
		idxNeuronaMenorDist = 0;
		y=0;
        x=0;

        //Calcula el best matching unit, BMU
		for(int idxNeurona=0; idxNeurona<SOM::numNeuronas; idxNeurona++)
		{
            if(x == SOM::numNeuronasN){
                y++;
                x=0;
            }
			tmpDist = distancia(ejemplos[idxEjemplo], pesos[idxNeurona]);
			if(  tmpDist  <  menorDistancia  )
			{
				menorDistancia = tmpDist;
				idxNeuronaMenorDist = idxNeurona;
                colNeuMenorDist=x;
                renNeuMenorDist=y;
                //cout << endl << endl << "(" << idxEjemplo << ") " << "idxNeuronaMenorDist = " << idxNeuronaMenorDist << " menorDistancia = " << menorDistancia;
                //cout << endl << endl << "x = " << colNeuMenorDist << " y = " << renNeuMenorDist;
			}
			//cout << endl << endl << "idxNeurona = " << idxNeurona << "x = " << x << " y = " << y;
            x++;
		}

        y=0;
        x=0;

        //Calcular la distancia de cada nodo con el BMU
        for(int idxNeurona=0; idxNeurona<SOM::numNeuronas; idxNeurona++)
		{
			if(x == SOM::numNeuronasN){
                y++;
                x=0;
            }

            double DistBMU = (x-colNeuMenorDist) * (x-colNeuMenorDist) + (y-renNeuMenorDist) * (y-renNeuMenorDist);
            double WidthSq = m_neighbourhoodRadius * m_neighbourhoodRadius;

            if (DistBMU < (m_neighbourhoodRadius * m_neighbourhoodRadius))
            {
				//Calcula la influencia que tienen los nodos con respecto al BMU
				m_influence = exp(-(DistBMU) / (2*WidthSq));

				actualizaPesos(idxNeurona, idxEjemplo, m_learningRate, m_influence);
            }
            x++;
		}
		bmu.push_back(idxNeuronaMenorDist);
	}
}

float SOM::distancia(const vector<float> & vec1, const vector<float> & vec2)
{
	float dist = 0.0;

	for(unsigned int i=0; i<SOM::numEntradas; i++)
		dist += ( (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]) );

	return dist;
}

void SOM::actualizaPesos(int idxNeurona, int idxEjemplo, double m_learningRate, double m_influence)
{
	for(int idxEntrada=0; idxEntrada<SOM::numEntradas; idxEntrada++){
		pesos[idxNeurona][idxEntrada] += (  m_influence * m_learningRate * (ejemplos[idxEjemplo][idxEntrada] - pesos[idxNeurona][idxEntrada])  );
		//cout << endl << endl << "(" << idxEjemplo << ") " << "idxNeuronaMenorDist = " << idxNeurona << " pesoNuevo = " << pesos[idxNeurona][idxEntrada]<< " influencia = " << m_influence;
	}
}
