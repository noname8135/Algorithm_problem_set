#include <iostream> 
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	int a,b,s,m,n;
	long int h,w;
	double angle, v, travel_dis;
	while(scanf("%d%d%d%d%d",&a,&b,&s,&m,&n)){
		if(a==0 && b==0 && s==0 && m==0 && n==0)
			break;
		w = a * m, h = b * n;
		travel_dis = sqrt(w*w + h*h);
		v = travel_dis / (double) s; 
		angle = asin(h/travel_dis) * 180 / 3.1415926;
		printf("%.2lf %.2lf\n",angle,v);
	}
	return 0;
}
