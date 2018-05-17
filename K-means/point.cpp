#include "point.h"

point::point(){
	
}

point::point(int id, double valores[]){
	this->id = id;
	for(int i = 0; i < numeroDatos; i++){
		this->valores[i] = valores[i];
	}
}

point::point(double valores[], int pointNumeroCluster){
	this->pointNumeroCluster = pointNumeroCluster;
	for(int i = 0; i < numeroDatos; i++){
		this->valores[i] = valores[i];
	}
}

void point::setValores(double valor, int i){
	this->valores[i] = valor;
}

double point::getValores(int i){
	return valores[i];
}

void point::setPointNumeroCluster(int pointNumeroCluster){
	this->pointNumeroCluster = pointNumeroCluster;
}

int point::getPointNumeroCluster(){
	return pointNumeroCluster;
}

int point::getId(){
	return id;
}
