// 1265. [S/W 문제해결 응용] 9일차 - 달란트2
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int T, N, P;
int val[100];

int main() {
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        memset(val, 0, sizeof(val));
        cin >> N >> P;
        
        int mod = N % P;
        int div = N / P;
        // cout << "@" << mod << " " << div << endl;
        for(int i=0; i<P; i++) {
            val[i] = div;
        }
        // for(int i=0; i<div; i++) cout << val[i];
        // cout << endl;

        if(mod) {
            int plus = mod / P;
            int rest = mod % P;
            for(int i=0; i<plus; i++) {
                val[i] += 1;
            }

            for(int i=0; i<rest; i++) {
                val[i] += 1;
            }
        }

        long long result = 1;
        for(int i=0; i<P; i++) {
            result *= val[i];
        }

        cout << "#" << tc << " " << result << endl;
    }
    return 0;
}