#ifndef CIRCLE_H
#define CIRCLE_H

#define NN 16 
#define M_PI 3.1415926535897932384

class Spin{
	public:
	    double cor[3]; //Correlation function
		double ZC[3]; //counter
		double IP[3]; //Inner Product
			
		double vector[3][3];
		double block[20][3];
		Spin();
};

double Inner(double a[3],double b[3]);

void Update(double total[3], double a[3],double JT);

double RNG();




#endif
