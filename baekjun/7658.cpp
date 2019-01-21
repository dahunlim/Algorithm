#include <iostream>
using namespace std;

int main(){
    int N;
    int a[50], b[50];
    int c[50] = {};
    int x, y;
   
    cin >> N;
    for(int i=0; i<N; i++){cin >> a[i] >> b[i];}
    for(int i=0; i<N; i++){
        x = a[i];
        y = b[i];
        for(int j=0; j<N; j++){
            if(j==i) continue;
            if(x < a[j] && y < b[j]){c[i]++;} 
        }
    }
    for(int i=0; i<N; i++){cout << (c[i]+1) << " ";}
}