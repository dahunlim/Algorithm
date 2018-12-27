#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int N, K, Pi;
double x, y;
vector<double> v;
int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        double temp1;
        double tempm = 0;
        scanf("%d", &Pi);
        for(int j=0; j<Pi; j++){
            scanf("%lf %lf", &x, &y);
            temp1 = x*x + y*y;
            if(tempm < temp1) tempm = temp1;
        }
        v.push_back(tempm);
    }
    sort(v.begin(), v.end());
    printf("%.2f", v[K-1]);
    return 0;
}