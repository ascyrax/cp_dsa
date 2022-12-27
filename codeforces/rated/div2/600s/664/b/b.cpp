// @author: ascyrax

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define pb push_back

double startTime;
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n, m, sx, sy;
        cin >> n >> m >> sx >> sy;
        cout << sx << " " << sy << endl;
        int flag = -1;
        if (sy % 2 == 0)
                flag = 0;
        else
                flag = 1;
        for (int row = 1; row <= n; row++)
        {
                if (row == sx)
                        continue;
                cout << row << " " << sy << endl;
        }
        for (int col = sy + 1; col <= m; col++)
        {
                if (col % 2 != sy % 2)
                        for (int row = n; row >= 1; row--)
                        {
                                cout << row << " " << col << endl;
                        }
                else if (col % 2 == sy % 2)
                        for (int row = 1; row <= n; row++)
                        {
                                cout << row << " " << col << endl;
                        }
        }
        if (m % 2 == sy % 2)
        {
                // one se start
                for (int col = 1; col < sy; col++)
                {
                        if (col % 2 == 1) // 1 3 5
                                for (int row = n; row >= 1; row--)
                                {
                                        cout << row << " " << col << endl;
                                }
                        else if (col % 2 == 0) // 2 4 6
                                for (int row = 1; row <= n; row++)
                                {
                                        cout << row << " " << col << endl;
                                }
                }
        }
        else if (m % 2 != sy % 2)
        {
                // n se start in the last col
                // => 1 se start in the 1st col
                for (int col = 1; col < sy; col++)
                {
                        if (col % 2 == 0) // 2 4 6
                                for (int row = n; row >= 1; row--)
                                {
                                        cout << row << " " << col << endl;
                                }
                        else if (col % 2 == 1) // 1 3 5
                                for (int row = 1; row <= n; row++)
                                {
                                        cout << row << " " << col << endl;
                                }
                }
        }
}

//................................
