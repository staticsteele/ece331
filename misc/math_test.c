#include <stdio.h>
#include <math.h>

double result(double x, double y);

int main(int argc, char * argv[]){

	// Variable declarations
	double x = -1.0;
	double y = -1.0;
	double z;

	for(x = -1.0; x<=1.0; x=x+0.1){
		//z = result(x,y);
		printf("For x = %.2lf and y = %.2lf, z = %.2lf\n", x, y, result(x,y));
		y = y+0.1;
	}

	return 0;

}

double result(double x, double y){
	return sqrt((x*x)+(y*y));
}
