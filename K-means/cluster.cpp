#include "cluster.h"

cluster::cluster(){
	
}

cluster::cluster(int id, int centroideNumeroCluster, point centralPoint){
	this->centroideNumeroCluster = centroideNumeroCluster;
	this->id = id;
	for(int i = 0; i < numeroDatos; i++){
		this->centralPoint.setValores(centralPoint.getValores(i),i);
	}
}

void cluster::setCentroideNumeroCluster(int centroideNumeroCluster){
	this->centroideNumeroCluster = centroideNumeroCluster;
}

int cluster::getCentroideNumeroCluster(){
	return centroideNumeroCluster;
}

void cluster::setCentralPoint(point centralPoint){
	this->centralPoint = centralPoint;
}

point cluster::getCentralPoint(){
	return centralPoint;
}

void cluster::setCentralValores(double valor, int i){
	centralPoint.setValores(valor,i);
}

double cluster::getCentralValores(int i){
	return centralPoint.getValores(i);
}

void cluster::agregarPoint(point p){
	points.push_back(p);
}

void cluster::eliminarPoint(int i){
	totalPoints = getTotalPoints();
	for(int j = 0; j < totalPoints; j++){
		if(i == points[j].getId()){
			points.erase(points.begin() + i);
		}
	}
}

int cluster::getTotalPoints(){
	return points.size();
}

int cluster::getId(){
	return id;
}

point cluster::getPoint(int i){
	return points[i];
}
