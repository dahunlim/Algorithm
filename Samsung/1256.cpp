// 1256. [S/W 문제해결 응용] 6일차 - K번째 접미어
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T, K;
string S;
int main() {
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        vector<string> v1;
        cin >> K;
        cin >> S;
        v1.resize(S.length() + 1);
        for(int i=0; i<S.length(); i++) {
            string tmp = "";
            for(int j=i; j<S.length(); j++) {
                tmp += S[j];
            }
            v1[i] = tmp;
        }
        sort(v1.begin(), v1.end());
        cout << "#" << tc << " " << v1[K] << endl;
    }  
    return 0;
}