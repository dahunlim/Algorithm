#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    string a, temp1, temp2, temp3;
    string result;

    vector<string> v;

    cin >> a;

    for(int i=0; i < a.length()-2; i++){
        temp1 += a[i];
        for(int j=i+1; j < a.length()-1; j++){
            temp2 += a[j];
            for(int k= j+1; k < a.length(); k++){
                temp3 += a[k];
            }

            string change1, change2, change3;
    
            for(int q = temp1.length()-1; q >= 0 ; q--){
                    change1 += temp1[q];
                }
            for(int w = temp2.length()-1; w >= 0 ; w--){
                    change2 += temp2[w];
                }
            for(int e = temp3.length()-1; e >= 0 ; e--){
                    change3 += temp3[e];
                }
            result = change1 + change2 + change3;
            v.push_back(result);
            temp3 = "";
        }
        temp2 = "";
    }
    temp1 = "";

    sort(v.begin(), v.end());
    cout << v.at(0);
    
    return 0;
}