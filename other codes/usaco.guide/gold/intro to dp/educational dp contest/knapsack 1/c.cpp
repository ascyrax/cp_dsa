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
ll dp[101][100001];
//...............................

void suraj()
{
        ll n, wmax;
        cin >> n >> wmax;

        vector<ll> w(n + 1), v(n + 1);

        for (ll i = 1; i <= n; i++)
        {
                cin >> w[i] >> v[i];
        }

        //  Let dp[i][j] represent the maximum value that can be attained by the first i weights with a weight of j.

        // base case
        for (ll i = 1; i <= n; i++)
                dp[i][0] = 0;
        for (ll i = 1; i <= wmax; i++)
                dp[0][i] = 0;

        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= wmax; j++)
                {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                        if (j - w[i] >= 0)
                                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i][j]);
                }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //         for (int j = 1; j <= wmax; j++)
        //                 cout << dp[i][j] << " ";
        //         cout << endl;
        // }
        // cout << endl;

        ll ans = 0;
        for (int i = 1; i <= wmax; i++)
                ans = max(ans, dp[n][i]);
        cout << ans << endl;
}
//................................

// ll

// ll

// int

// int
