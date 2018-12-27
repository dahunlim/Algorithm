#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, L, n, loc, minresult, maxresult;
int main(){
    cin >> T;
    while(T--){
        vector<int> v1;
        v1.push_back(0);
        int middle = -1;
        cin >> L >> n;
        for(int i=0; i<n; i++) {
            cin >> loc;
            v1.push_back(loc);
        }
        sort(v1.begin(), v1.end());
        for(int i=1; i<=n; i++){
            if(v1[i] == (L/2)){
                middle = v1[i];
                minresult = middle;
                break;
            }
            if(v1[i] > (L/2)){
                if(v1[i] - (L/2) > (L/2) - v1[i-1]){
                    middle = v1[i-1];
                    minresult = middle;
                }
                else {
                    middle = v1[i];
                    minresult = L - middle;
                }
                break;
            }
        }
        if(middle == -1) minresult = v1[n];
        if(v1[1] > L - v1[n]) maxresult = v1[n];
        else maxresult = L - v1[1];

        cout << minresult << " " << maxresult << "\n";
    }
    return 0;
}