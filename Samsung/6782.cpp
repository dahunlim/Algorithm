// 6782. 현주가 좋아하는 제곱근 놀이
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
using namespace std;
int T;
long long N;
int main() {
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        long long result = 0;
        cin >> N;
        
        while(true) {
            if(N == 2) {
                break;
            } else if(N == 1) {
                result += 1;
                break;
            }
            
            double cal = sqrt(N);
            // cout << N << " " << cal << " " << long(cal) << " " << result << endl;
            if(long(cal) == cal) {
                N = cal;    
                result++;
            } else {
                long long next = (long(cal) + 1) * (long(cal) + 1);
                result += next - N;
                N = next;
            }

        }
        cout << "#" << tc << " " << result << endl;
    }
    return 0;
}