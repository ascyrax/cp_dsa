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
        freopen("time.in", "r", stdin);
        freopen("time.out", "w", stdout);
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
int n, m, c;
vector<int> moonies;
vector<vector<int>> dg;
vector<vector<int>> dp;
//...............................

//...............................

void suraj()
{
        cin >> n >> m >> c;
        dg = vector<vector<int>>(n + 1, vector<int>());
        dp = vector<vector<int>>(1005, vector<int>(1005, -1)); // t can be 1000 max for a positive no of moonies as uppper  bound is 1000t-ct2
        moonies.pb(0);
        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                moonies.pb(x);
        }
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                dg[a].pb(b);
        }
        dp[0][1] = 0;
        // for (auto neigh : dg[1])
        // {
        //         dp[neigh][1] = 0 + moonies[neigh];
        // }
        for (int t = 0; t <= 1002; t++)
        {
                for (int city = 1; city <= n; city++)
                {
                        if (dp[t][city] == -1)
                                continue;
                        else
                        {
                                // cout << " t = " << t << "city = " << city << endl;
                                for (auto neigh : dg[city])
                                {
                                        // cout << "neigh = " << neigh << endl;
                                        if (dp[t + 1][neigh] == -1)
                                                dp[t + 1][neigh] = 0;
                                        dp[t + 1][neigh] += (dp[t][city] + moonies[neigh]);
                                }
                        }
                }
        }
        // for (int i = 0; i <= 10; i++)
        // {
        //         for (int j = 0; j <= 10; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        int ans = 0;
        for (int t = 1; t <= 1000; t++)
        {
                ans = max(ans, dp[t][1] - c * t * t);
        }
        cout << ans << endl;
}

//................................
