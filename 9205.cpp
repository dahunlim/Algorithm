#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef struct
{
    int x;
    int y;
    bool check = false;
} coord;

int abs(int x)
{
    return ((x < 0) ? -x : x);
}

int main()
{

    int casenum;
    cin >> casenum;

    while (casenum--)
    {
        int n;
        cin >> n;

        coord temp[n + 2];

        for (int i = 0; i < n + 2; i++)
        {
            cin >> temp[i].x >> temp[i].y;
        }

        int nx, ny;

        nx = temp[0].x;
        ny = temp[0].y;
        temp[0].check = true;

        queue<pair<int, int>> q;
        q.push(make_pair(nx, ny));

        while (!q.empty())
        {
            int x, y;
            x = q.front().first;
            y = q.front().second;

            if (x == temp[n + 1].x && y == temp[n + 1].y)
            {
                cout << "happy\n";
                break;
            }
            q.pop();
            for (int i = 0; i < n + 2; i++)
            {
                if (abs(temp[i].x - x) + abs(temp[i].y - y) <= 1000)
                {

                    if (temp[i].check == false)
                    {
                        q.push(make_pair(temp[i].x, temp[i].y));
                        temp[i].check = true;
                    }
                }
            }
        }
        if (!temp[n + 1].check)
        {
            cout << "sad\n";
        }
    }

    return 0;
}