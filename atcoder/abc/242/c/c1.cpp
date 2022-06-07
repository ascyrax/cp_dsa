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

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        // cin>>t;

        for (int i = 1; i <= t; i++)
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
        ll mod = 998244353;
        ll n;
        cin >> n;

        vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));

        for (int i = 1; i <= 9; i++)
                dp[1][i] = 1;

        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= 9; j++)
                {
                        if (j == 1)
                        {
                                dp[i][j] += dp[i - 1][j];
                                dp[i][j] += dp[i - 1][j + 1];
                        }
                        else if (j == 9)
                        {
                                dp[i][j] += dp[i - 1][j];
                                dp[i][j] += dp[i - 1][j - 1];
                        }
                        else
                        {
                                dp[i][j] += dp[i - 1][j];
                                dp[i][j] += dp[i - 1][j - 1];
                                dp[i][j] += dp[i - 1][j + 1];
                        }
                        dp[i][j] %= mod;
                }
        }
        ll ans = 0;
        for (int i = 1; i <= 9; i++)
        {
                ans += dp[n][i];
                ans %= mod;
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// ll

// ll
