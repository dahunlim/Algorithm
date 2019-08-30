// 1245. [S/W 문제해결 응용] 2일차 - 균형점
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int T, N;
double dist[11];
double weight[11];
double answer;

// void search(double idx, double start, double end, int cnt) {
//     cout << fixed;
//     cout.precision(10);
//     double left, right;
//     left = 0;
//     right = 0;
//     for(int i=0; i<N; i++) {
//         if(dist[i] < idx) {
//             left += weight[i] / ((idx - dist[i])*(idx - dist[i]));
//         } else {
//             right += weight[i] / ((dist[i] - idx)*(dist[i] - idx));
//         }
//     }
//     // cout << idx << " " << start << " " << end << " " << left << " " << right << endl; 
//     if((left == right) || cnt >= 100) {
//         cout << " " << idx;
//         return;
//     } else if(left < right) {
//         double newIdx = (idx + start) / 2;
//         search(newIdx, start, idx, cnt+1);
//     } else if(left > right) {
//         double newIdx = (end + idx) / 2;
//         search(newIdx, idx, end, cnt+1);
//     }
//     return ;
// }
int main () {
    cout << fixed;
    cout.precision(10);

    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        answer = 0;
        memset(dist, 0, sizeof(dist));
        memset(weight, 0, sizeof(weight));
        cin >> N;
        for(int i=0; i<N; i++) cin >> dist[i];
        for(int i=0; i<N; i++) cin >> weight[i];
        cout << "#" << tc;
        for(int i=0; i<N; i++) {
            double left = dist[i];
            double right = dist[i+1];
            // double idx = (left + right) / 2;
            // search(idx, left, right, 0);
            int cnt = 0;
            while (true) {
                double leftsum = 0;
                double rightsum = 0;
                double idx = (left + right) / 2.0;
                for(int j=0; j<=i; j++) {
                    leftsum += weight[j] / ((idx - dist[j])*(idx - dist[j]));
                }
                for(int j=i+1; j<N; j++) {
                    rightsum += weight[j] / ((dist[j] - idx)*(dist[j] - idx));
                }

                if(cnt++ == 100) {
                    if(idx > 0.0000000001){
                        cout << " " << idx;
                    }
                    break;
                }

                if(leftsum > rightsum) left = idx;
                else right = idx;
            }
        }
        cout << endl;
    }
    return 0;
}