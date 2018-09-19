#include <iostream>
#include "head.h"
#include <functional>
#include <stdlib.h>
#include <string> 
#include <fstream>
#include <math.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
	
	std::ofstream file;
	std::string slabel;
	std::string name1="All_";
	double JT;
	int name_q;
	if(argc==3){
		slabel=argv[1];
		name1=name1+slabel+".txt";
		file.open(name1.c_str());
	        JT=atof(argv[2]);
	}
	else{
		std::cin>>JT>>slabel;
		name1=name1+slabel+".txt";
		file.open(name1.c_str());
	}
	long long int N=1e9;
	long int block_N=0;
	long int block_L=N/20;
	long int block_n=0;
	long long int i; 
        long long int l;
	long long int j,k,i1;
	int k1=0,k2=0,k3=0;
//	long long int Out_P=1000000000;
	int label;
	double Z0=0;
	double total[3];
	double sum=0;
	Spin spgp[NN][NN];


		for(i=0;i<100000000;i++){       //Thermalization
			k1=int(RNG()*NN);
			k2=int(RNG()*NN);
			k3=int(RNG()*Sub);
			Spin::Interaction(k1,k2,k3,spgp,total);
		//	printf("%f %f %f \n",total[0],total[1],total[2]);
			Update(total,spgp[k1][k2].vector[k3],JT);
		//	printf("%f %f %f\n",spgp[k1][k2].vector[k3][0],spgp[k1][k2].vector[k3][1],spgp[k1][k2].vector[k3][2]);
		}
		
	
	
	

		for(i=0;i<NN;i++){
			for(j=0;j<NN;j++){
				for(k=0;k<Sub;k++){
					spgp[i][j].cor[k]=0;
					spgp[i][j].ZC[k]=0;
					spgp[i][j].IP[k]=Inner(spgp[0][0].vector[0], spgp[i][j].vector[k]);
				}			
			}
		}
		
  		
		for(l=0;l<N;l++){     
			k1=int(RNG()*NN);
			k2=int(RNG()*NN);
			k3=int(RNG()*Sub);
			Spin::Interaction(k1,k2,k3,spgp,total);
		//	printf("%f %f %f \n",total[0],total[1],total[2]);
			Update(total,spgp[k1][k2].vector[k3],JT);
			Z0++;
			
			if(k1==0&&k2==0&&k3==0){
				for(i=0;i<NN;i++){
					for(j=0;j<NN;j++){
						for(k=0;k<Sub;k++){
							spgp[i][j].cor[k]=spgp[i][j].cor[k]+spgp[i][j].IP[k]*(Z0-spgp[i][j].ZC[k]);
							spgp[i][j].ZC[k]=Z0;
							spgp[i][j].IP[k]=Inner(spgp[0][0].vector[0], spgp[i][j].vector[k]);
						}			
					}
				}
			}
			else {
				spgp[k1][k2].cor[k3]=spgp[k1][k2].cor[k3]+spgp[k1][k2].IP[k3]*(Z0-spgp[k1][k2].ZC[k3]);
				spgp[k1][k2].ZC[k3]=Z0;
				spgp[k1][k2].IP[k3]=Inner(spgp[0][0].vector[0], spgp[k1][k2].vector[k3]);
			//	printf("%f\n",spgp[k1][k2].IP[k3]);
			}

			if((l+1)%block_L==0){
				block_n=(l+1)/block_L-1;
				for(i=0;i<NN;i++){
                		        for(j=0;j<NN;j++){
                               			 for(k=0;k<Sub;k++){
                                		        spgp[i][j].block[block_n][k]=spgp[i][j].cor[k]+spgp[i][j].IP[k]*(Z0-spgp[i][j].ZC[k]);	
						 }
					}
	
        		        }
			} 
		}
		
			
		for(i=0;i<NN;i++){
			for(j=0;j<NN;j++){
				file<<i<<"\t"<<j<<"\t";
				for(k=0;k<Sub;k++){
					spgp[i][j].cor[k]=spgp[i][j].cor[k]+spgp[i][j].IP[k]*(Z0-spgp[i][j].ZC[k]);			                                      for(l=19;l>0;l--){
						spgp[i][j].block[l][k]=(spgp[i][j].block[l][k]-spgp[i][j].block[l-1][k])/block_L;
						sum=sum+(spgp[i][j].block[l][k]-spgp[i][j].cor[k]/Z0)*(spgp[i][j].block[l][k]-spgp[i][j].cor[k]/Z0);
					}	
					spgp[i][j].block[0][k]/=block_L;
					sum=sum+(spgp[i][j].block[0][k]-spgp[i][j].cor[k]/Z0)*(spgp[i][j].block[0][k]-spgp[i][j].cor[k]/Z0);
					sum=sqrt(sum/20);
					file<<spgp[i][j].cor[k]/Z0<<"\t"<<sum<<((k==Sub-1)?"\n":"\t");
					sum=0;		
				}
			}			

		}
		
	/*	fprintf(fp2,"%lf\n",spgp[0][0].cor[2]/Z0);
		fprintf(fp2,"%lf\n",spgp[0][1].cor[0]/Z0);
		fprintf(fp2,"%lf\n",spgp[0][1].cor[1]/Z0);
		fprintf(fp2,"%lf\n",spgp[1][1].cor[1]/Z0);
		fprintf(fp2,"%lf\n",spgp[1][1].cor[2]/Z0);
		fprintf(fp2,"%lf\n",spgp[0][1].cor[2]/Z0);
		fprintf(fp2,"%lf\n",spgp[NN-1][1].cor[1]/Z0);
		fprintf(fp2,"%lf\n",spgp[0][2].cor[0]/Z0);
		fprintf(fp2,"%lf\n",spgp[1][2].cor[1]/Z0);
		fprintf(fp2,"%lf\n",spgp[2][2].cor[1]/Z0);
		fprintf(fp2,"%lf\n",spgp[0][2].cor[1]/Z0);
		fprintf(fp2,"%lf\n",spgp[1][2].cor[2]/Z0);
		fprintf(fp2,"%lf\n",spgp[2][2].cor[2]/Z0); */
		

	
/*	for(i=0;i<NN;i++){ 
		for(j=0;j<NN;j++){
			printf("%f ",spgp[i][j].vector[0]);	
		}
		printf("\n");
	} */
file.close();
return 0;
}
