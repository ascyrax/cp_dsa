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

const ll MOD = 998244353;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
ll pow(ll a, ll b, ll M)
{
        ll x = 1, y = a;
        while (b > 0)
        {
                if (b % 2 == 1)
                {
                        x = (x * y);
                        if (x > M)
                                x %= M;
                }
                y = (y * y);
                if (y > M)
                        y %= M;
                b /= 2;
        }
        return x;
}
ll modInverse(ll a, ll m)
{
        return pow(a, m - 2, m);
}
//...............................

void suraj()
{
        ll n;
        cin >> n;
        // 1 to n should have signal but 0 and n+1 should not
        vector<ll> vOdd;
        for (ll i = 1; i <= n; i += 2)
                vOdd.pb(i);
        ll len = vOdd.size();
        // ll dp[n][len]; // dp[i][j] is the no of ways to form sum i using the first j elements of vOdd
        // dp[0][0] = 1;
        // for (ll i = 1; i <= n; i++)
        // {
        //         for (ll j = 0; j <= min(len, i); j++)
        //         {
        //                 // if jth element is taken
        //                 if (j - 1 >= 0 && i - vOdd[j - 1] >= 1)
        //                         dp[i][j] += dp[i - vOdd[j - 1]][j - 1];
        //                 dp[i][j] %= MOD;
        //                 // if jth element is not taken
        //                 if (j - 1 >= 0)
        //                         dp[i][j] += dp[i][j - 1];
        //                 dp[i][j] %= MOD;
        //         }
        // }
        // cout << dp[n][len] << endl;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
                for (ll coin : vOdd)
                {
                        if (i - coin >= 0)
                        {
                                dp[i] += dp[i - coin];
                        }
                        dp[i] %= MOD;
                }
        }
        // cout << dp[n] << endl;
        ll x = dp[n];
        ll y = pow(2, n);
        ll yinv = modInverse(y, MOD);
        cout << (x * yinv) % MOD << endl;
}

//................................
