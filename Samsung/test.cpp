#include <iostream>
using namespace std;
int map[4][4];
bool visitednum[10000000];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

int cnt;

int dfs(int y, int x, int depth, int now)
{
     if(depth==7)
     {
          if(!visitednum[now]) {visitednum[now]=1; cnt++;}
          return 0;
     }
     now*=10;
     now+=map[y][x];


     for(int i=0; i<4; i++)
     {
          int ny = y + dy[i];
          int nx = x + dx[i];

          if(ny>=0 && ny<4 && nx>=0 && nx<4)
          { dfs( ny, nx, depth+1, now);}
     }
     now/=10;
     now-=map[y][x];

}
int main()
{
     int tc;
     cin >> tc;

     for(int t=1; t<=tc; t++)
     {
          cnt=0;
          for(int i=0; i<4; i++)
               for(int j=0; j<4; j++)
                    cin >> map[i][j];

          for(int i=0; i<=9999999; i++) visitednum[i]=0;
          for(int i=0; i<4; i++)
               for(int j=0; j<4; j++)
                    dfs(i,j,0,0);

          cout << "#" << t << " " << cnt <<endl;
     }
}