#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	double x1,y1,x2,y2;
	double x3,y3,x4,y4; //solution set
	double cx,cy;	//center of square
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF){
		if( fabs(x2-x1) < 1e-9 && fabs(y2-y1) < 1e-9 ){
			cout << "Impossible" <<endl;
			continue;
		}
		cx = (x1+x2) / 2, cy = (y1+y2) /2; 
		x3 = cx + cy - y2, y3 = cy + x2 - cx; //+- 1*orthognal vector 
		x4 = cx + y2 - cy, y4 = cy + cx - x2;
		printf("%.10lf %.10lf %.10lf %.10lf\n",x3,y3,x4,y4);

	}
	return 0;
}