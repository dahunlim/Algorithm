#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, input;
int main(){
    vector<int> v1;
    cin >> N;
    while(N--){
        cin >> input;
        v1.push_back(input); 
    }
    sort(v1.begin(), v1.end());
    for(int i=0; i<v1.size(); i++) cout << v1[i] << endl;
    return 0;
}