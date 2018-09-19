#ifndef CIRCLE_H
#define CIRCLE_H

#define NN 16 
#define Sub 1
#define TotalNeighbor 8
#define M_PI 3.1415926535897932384

class Spin{

	public:
	        static double LA[Sub][TotalNeighbor][4]; //x,y,s,r.
		double cor[Sub]; //Correlation function
		double ZC[Sub]; //counter
		double IP[Sub]; //Inner Product	
		double vector[Sub][3];
		double block[20][Sub];
		static void Interaction(int x,int y,int s,Spin object[][NN],double v[3]);
		Spin();
};




double Inner(double a[3],double b[3]);

void Update(double total[3], double a[3],double JT);

double RNG();




#endif
