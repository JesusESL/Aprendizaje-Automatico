/// Autor: Víctor Uc Cetina (uccetina@uady.mx)

///===
///=== Usar el makefile para compilar. Nombre del ejecutable: ada
///===

#include <iostream>
#include <string>
#include <vector>
#include "../adalib/adaboost.h"
using namespace std;


/// Parámetros que deben especificarse antes de compilar
const unsigned short NUM_CLASIFICADORES_DEBILES = 10;
const unsigned short MIN_TAMANO_PLANTILLA = 3;
const unsigned short MAX_TAMANO_PLANTILLA = 3;


int main()
{
	Datos datosEntrenamiento;
	Datos datosPrueba;
	
	datosEntrenamiento.leeArchivoDatos("../datos/", "datosX.txt", "datosY.txt");
	
	datosPrueba = datosEntrenamiento;
	
	ClasificadorFuerte H(datosEntrenamiento.X(), datosEntrenamiento.Y(), NUM_CLASIFICADORES_DEBILES, MIN_TAMANO_PLANTILLA, MAX_TAMANO_PLANTILLA);
	H.generaDebiles();
	H.printDebiles();
	H.pruebaDebiles(datosPrueba.X(), datosPrueba.Y());
	
	
	return 0;
}
