#include <iostream>
#include <cstring>
using namespace std;
int n, a, sum;
int check[729];
int solve(int num){
    if(check[num] != -1){
        cout << "UNHAPPY";
        return 0;
    }
    int a = 0;
    while(1){
        a += (num % 10) * (num % 10);
        if(num < 10){
            break;
        }
        num = num / 10;
    }
    if(a == 1){
        cout << "HAPPY";
        return 0;
    }
    check[num] = 1;
    solve(a);    
}
int main(){
    cin >> n;
    memset(check, -1, sizeof(check));
    sum = 0;
    while(1){
        sum += (n % 10) * (n % 10);
        if(n < 10){
            break;
        }
        n = n / 10;
    }
    solve(sum);
    return 0;
}