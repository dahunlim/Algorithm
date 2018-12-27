#include <iostream>
#include <vector>
using namespace std;
int N, K, input, count, temp;
vector<int> v;
int main(){
    count = 0;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> input;
        v.push_back(input);
    }
    for(int i=N-1; i>=0; i--){
        if(v[i] > K) continue;
        temp = K;
        for(int j=i; j>=0; j--){
            count += temp / v[j];
            if(temp % v[j] == 0){
                cout << count;
                return 0;
            }
            temp %= v[j];
        }  
    }   
    return 0;
}