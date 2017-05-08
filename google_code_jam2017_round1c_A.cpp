#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define PI 3.1415926535

using namespace std;

struct pancake{
    double h,r;
};

bool cmp(pancake a, pancake b){
    return a.r*a.h > b.r*b.h;
}

double getSurface(pancake p){
    return p.r*p.r*PI;
}

int main(){
        int T;
        int K,N;
        int i,j;
        pancake p[1000];
        cin >> T;
        for(int t=1;t<=T;t++){
            cout << "Case #" << t << ": ";
            cin >> N >> K;
            for(i=0;i<N;i++)
                cin >> p[i].r >> p[i].h;
            sort(p,p+N,cmp);
            double maxr=0;
            for(i=0;i<K;i++)
                maxr = max(maxr,p[i].r);

            for(;i<N;i++){
                if(2*p[i].r*PI*p[i].h + PI*p[i].r*p[i].r > PI*maxr*maxr+ 2*p[K-1].r*PI*p[K-1].h){
                    p[K-1] = p[i];
                    maxr = p[i].r;
                }
            }
            double tot = 0;
            for(i=0;i<K;i++)
                tot+=2*p[i].r*PI*p[i].h;
            tot+=maxr*maxr*PI;
            printf("%.6f\n",tot);
        }
        return 0;
}
