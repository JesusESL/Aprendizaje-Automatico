#include "kMeans.h"

kMeans::kMeans(int totalClusters, int numeroDatos, int totalDatos){
	this->totalClusters = totalClusters;
	this->numeroDatos = numeroDatos;
	this->totalDatos = totalDatos;
}

double kMeans::getDistancia(point p, cluster c){
	double distancia = 0;
	for(int i = 0; i < numeroDatos-1; i++){
		distancia += pow(c.getCentralValores(i) - p.getValores(i), 2);
	}
	return sqrt(distancia);
}

void kMeans::inicializar(){
	ifstream archivo;
	archivo.open("data.txt", ifstream::in);
	double d;
	double valores[8];
	
	for(int i = 0; i < totalDatos; i++){
		for(int j = 0; j < numeroDatos; j++){
			archivo >> d;
			valores[j] = d;
		}
		point p(i,valores);
		points.push_back(p);
	}
	
	archivo.close();
}

void kMeans::entrenar(){
	bool kMeansFlag = true;
	int numeroCluster = -1;
	int viejoCluster = 0;
	int viejoCluster1 = 0;
	int viejoCluster2 = 0;
	int viejoCluster3 = 0;
	int nuevoCluster;
	int totalPoints = 0;
	double centroide = 0;
	double min = 100000;
	bool mismoVector = false;
	
	for(int i = 0; i < totalClusters; i++){
		int randomPoint = rand() % totalDatos;
		cluster _cluster(points[randomPoint].getId(), i, points[randomPoint]);
		clusters.push_back(_cluster);
	}
	
	for(int i = 0; i < totalDatos; i++){
		for(int j = 0; j < totalClusters; j++){
			for(int x = 0; x < numeroDatos; x++){
				if(points[i].getValores(x) == clusters[j].getCentralValores(x)){
					mismoVector = true;
				}else{
					mismoVector = false;
					break;
				}
			}
			if(mismoVector == false){
				double distanciaMinima = getDistancia(points[i], clusters[j]);
				if(distanciaMinima < min){
					min = distanciaMinima;
					numeroCluster = j;
				}
			}
		}
		points[i].setPointNumeroCluster(numeroCluster);
		clusters[numeroCluster].agregarPoint(points[i]);
		min = 100000;
	}

	for(int epoca = 0; epoca < 1000; epoca++){
		kMeansFlag = false;
		for(int i = 0; i < totalDatos; i++){
			viejoCluster = points[i].getPointNumeroCluster();
			for(int j = 0; j < totalClusters; j++){
				for(int x = 0; x < numeroDatos; x++){
					if(points[i].getValores(x) == clusters[j].getCentralValores(x)){
						mismoVector = true;
					}else{
						mismoVector = false;
						break;
					}
				}
				if(mismoVector == false){
					double distanciaMinima = getDistancia(points[i], clusters[j]);
					if(distanciaMinima < min){
						min = distanciaMinima;
						numeroCluster = j;
					}
				}
			}
			if(viejoCluster != numeroCluster && mismoVector == false){
				clusters[viejoCluster].eliminarPoint(points[i].getId());
				points[i].setPointNumeroCluster(numeroCluster);
				clusters[numeroCluster].agregarPoint(points[i]);
				kMeansFlag = false;
			}
			min = 100000;
		}
		
		for(int i = 0; i < totalClusters; i++){
			for(int j = 0; j < numeroDatos-1; j++){
				int totalPointsCluster = clusters[i].getTotalPoints();
				double sum = 0.0;
				if(totalPointsCluster > 0){
					for(int k = 0; k < totalPointsCluster; k++){
						sum += clusters[i].getPoint(k).getValores(j);
					}
					clusters[i].setCentralValores(sum / totalPointsCluster,j);
				}
			}
		}
		
		if( (viejoCluster1==clusters[0].getTotalPoints()) && (viejoCluster2==clusters[1].getTotalPoints()) && (viejoCluster3==clusters[2].getTotalPoints())){
			break;
		}
		
		viejoCluster1 = clusters[0].getTotalPoints();
		viejoCluster2 = clusters[1].getTotalPoints();
		viejoCluster3 = clusters[2].getTotalPoints();
		
		cout << "Epoca: " << epoca+1 << endl;
		cout << "Total de puntos en el cluster 1: " << clusters[0].getTotalPoints() << endl;
		cout << "Total de puntos en el cluster 2: " << clusters[1].getTotalPoints() << endl;
		cout << "Total de puntos en el cluster 3: " << clusters[2].getTotalPoints() << endl << endl;
		for(int i = 0; i < totalClusters; i++){
			cout << "Cluster" << i+1 << ": " << endl;
			int totalPointsCluster = clusters[i].getTotalPoints();
			for(int j = 0; j < totalPointsCluster; j++){
				int totalPointsCluster = clusters[i].getTotalPoints();
				if(totalPointsCluster > 0){
					cout << clusters[i].getPoint(j).getValores(7) << " ";
				}
			}
			cout << endl << endl;
		}
		cout << endl;
		
	}
}
