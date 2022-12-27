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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n, m, k;
        cin >> n >> m >> k;

        // int dp[101][101];

        // dp[n][m] = k;

        // for (int i = n; i >= 1; i--) //cannot divide by zero
        // {
        //         for (int j = m; j >= 1; j--)
        //         {
        //                 if (i == n && j == m)
        //                         continue;
        //                 if (j + 1 <= m)
        //                         dp[i][j] = dp[i][j + 1] / i; //cannot divide by zero. therefore i>=1
        //                 if (i + 1 <= n)
        //                         dp[i][j] = dp[i + 1][j] / j; //cannot divide by zero. therefore j>=1
        //         }
        // }
        // if (dp[1][1] == 0)
        //         cout << "YES" << endl;
        // else
        //         cout << "NO" << endl;
        if (k == n * m - 1)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;
}

//................................
