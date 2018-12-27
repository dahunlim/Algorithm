#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int T, N, M, P;
int main(){
    cin >> T;
    while(T--){
        vector<pair<int, int>> v1;
        int a, b;
        int count = 0;
        cin >> N >> M;
        for(int i=0; i<N; i++){
            cin >> P;
            v1.push_back(make_pair(i, P));
        }
        while(1){
            int error = 0;
            a = v1.front().first;
            b = v1.front().second;
            for(int j=1; j<v1.size(); j++){
                if(v1[j].second > b){
                    error = 1;
                    break;
                }
            }
            if(error) v1.erase(v1.begin()), v1.push_back(make_pair(a, b)); 
            else{
                count++;
                if(a == M){
                    cout << count << "\n";
                    break;
                }
                else{
                    v1.erase(v1.begin());
                }
            }
        }   
    }
    return 0;
}