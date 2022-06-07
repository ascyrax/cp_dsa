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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll &i : a)
                cin >> i;
        for (ll &i : b)
                cin >> i;
        // dp[i][j] = tot no of sequences of the first i elements, ending with j as the last element.
        vector<vector<ll>> dp(3005, vector<ll>(3005, 0));
        ll lPrev = 0, rPrev = 3005;
        for (ll i = 0; i < n; i++)
        {
                ll l = min(a[i], b[i]);
                ll r = max(a[i], b[i]);
                if (i == 0)
                {
                        for (ll j = l; j <= r; j++)
                        {
                                dp[0][j] = 1;
                        }
                }
                else
                {
                        for (ll j = l; j <= r; j++)
                        {
                                dp[i][j] += dp[i - 1][j];
                                dp[i][j] %= mod;
                                // for (ll k = lPrev; k <= min(rPrev, j); k++)
                                // {
                                //         dp[i][j] += dp[i - 1][k];
                                //         dp[i][j] %= mod;
                                // }
                        }
                }
                lPrev = l;
                rPrev = r;

                // cout << "i= " << i << endl;
                // cout << "dp[i][l<->r]" << endl;
                // for (int e = 0; e <= 3; e++)
                //         cout << dp[i][e] << " ";
                // cout << endl;

                if (i != n - 1)
                        // for (ll j = l + 1; j <= r; j++)
                        for (ll j = 1; j <= 3000; j++)
                        {
                                dp[i][j] += dp[i][j - 1];
                                dp[i][j] %= mod;
                        }

                // cout << "i= " << i << endl;
                // cout << "dp[i][l<->r]" << endl;
                // for (int e = 0; e <= 3; e++)
                //         cout << dp[i][e] << " ";
                // cout << endl;
        }

        ll ans = 0;
        for (ll i = 0; i <= 3000; i++)
        {
                ans += dp[n - 1][i];
                ans %= mod;
        }
        cout << ans << endl;
}

//................................
// int
// int
// int
// int
