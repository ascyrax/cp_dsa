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
        ll n, x;
        cin >> n >> x;
        vector<ll> vCoins(n);
        for (ll &i : vCoins)
                cin >> i;
        ll dp[x + 1][n + 1];
        for (int i = 0; i <= x; i++)
                for (int j = 0; j <= n; j++)
                        dp[i][j] = 0;
        for (int i = 0; i <= n; i++)
                dp[0][i] = 1;
        // dp[i][j] = total ways of forming the sum i using the first j coins
        // ans= dp[x][n];
        for (int i = 0; i <= x; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        // if we didnt pick the jth coin
                        // if (j - 1 >= 0)
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                        // if we picked the jth coin
                        if (i - vCoins[j - 1] >= 0)
                                dp[i][j] += dp[i - vCoins[j - 1]][j];
                        dp[i][j] %= MOD;
                }
        }
        cout << dp[x][n] << endl;
}

//................................
