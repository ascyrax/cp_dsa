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
        // ioss
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
        moonies = vector<int>(n, 0);
        dg = vector<vector<int>>(n, vector<int>());
        dp = vector<vector<int>>(1002, vector<int>(n, -1));
        for (int &i : moonies)
                cin >> i;
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                dg[a].pb(b);
        }
        dp[0][0] = 0;
        // cout << "a" << endl;
        for (int time = 0; time < 1000; time++)
        {
                for (int city = 0; city < n; city++)
                {
                        if (dp[time][city] != -1)
                                for (int neigh : dg[city])
                                {
                                        dp[time + 1][neigh] = max(dp[time + 1][neigh], dp[time][city] + moonies[neigh]);
                                }
                }
        }
        // cout << "b" << endl;
        // for (int time = 0; time < 5; time++)
        // {
        //         for (int city = 0; city < n; city++)
        //         {
        //                 cout << dp[time][city] << " ";
        //         }
        //         cout << endl;
        // }
        int ans = 0;
        for (int time = 0; time <= 1000; time++)
        {
                ans = max(ans, dp[time][0] - c * time * time);
        }
        cout << ans << endl;
}

//................................
