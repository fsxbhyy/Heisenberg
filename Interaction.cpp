#include "head.h"
#include <iostream>

void Spin::Interaction(int x, int y, int s, Spin object[][NN],double v[]){
	int i,j,k;
	int qx,qy,qs;
	double qr;
	for(i=0;i<3;i++){
		v[i]=0;
	}
	
	for(j=0;j<TotalNeighbor;j++){
		qx=LA[s][j][0];
	 	qy=LA[s][j][1];
		qs=LA[s][j][2];
		qr=LA[s][j][3];
		for(k=0;k<3;k++){
			v[k]+=qr*object[(x+qx+NN)%NN][(y+qy+NN)%NN].vector[qs][k];
		}
	}
}
