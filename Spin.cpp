#include "head.h"
#include <iostream>

Spin::Spin(){
	int i,j;
	for(i=0;i<Sub;i++){
		this->cor[i]=0;
		this->ZC[i]=0;
		this->IP[i]=0;
		this->vector[i][0]=0;
		this->vector[i][1]=0;
		this->vector[i][2]=1;
	}
	for(i=0;i<20;i++){
		for(j=0;j<Sub;j++){
			this->block[i][j]=0;
		}
	}
}


