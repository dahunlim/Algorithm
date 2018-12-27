#include <iostream>
#include <cstring>

using namespace std;

int dp[3003][1 << 3][1001];
int map[1001][3];
int n, k;
int val = -999999999;   

int solve(int num, int state, int domino){
    if(domino == 0) return 0;
    if(num >= n*3) return val;
    if(dp[num][state][domino] != val) return dp[num][state][domino];

    int &ans = dp[num][state][domino];
    int a; 
    
    if(state & 1){ 
        ans = solve(num+1, state >> 1, domino); //자리가 차있어서 PASS
    }
    else{
        ans = solve(num+1, state >> 1, domino);       // 1. 안놓고 PASS
        
        if(((num%3) != 2) && ((state & 2) == 0)){     // 2. 가로
            a = map[num/3][num%3] + map[num/3][num%3 + 1]; // 가로합
            ans = max(ans, solve(num + 2, (state >> 2), domino-1) + a);
        }
        
        if(num < (n-1)*3){                            // 3. 세로
            a = map[num/3][num%3] + map[num/3 + 1][num%3]; // 세로합
            ans = max(ans, solve(num + 1, (state >> 1) | (1 << 2), domino-1)+ a);
        }
    
    }
    
    return ans;
}

int main(){

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }
    for(int i=0; i<3003; i++){
        for(int j=0; j<(1<<3); j++){
            for(int l=0; l<1001; l++){
                dp[i][j][l] = val;
            }
        }
    }
    cout << solve(0, 0, k);
    return 0;
}