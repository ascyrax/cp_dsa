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
        ll n, wmax;
        cin >> n >> wmax;

        vector<ll> w(n + 1), v(n + 1);

        for (ll i = 1; i <= n; i++)
        {
                cin >> w[i] >> v[i];
        }

        ll dp[n + 1][n + 1];
        // initializa all value to 0.
        for (ll i = 0; i <= n; i++)
                for (ll j = 0; j <= n; j++)
                        dp[i][j] = 0;
        // dp[i][j] is the max value if from the first i items j are chosen.
        // base case
        for (ll i = 1; i <= n; i++)
                dp[i][0] = 0;
        for (ll i = 1; i <= n; i++)
                dp[0][i] = 0;

        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= n; j++)
                {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + v[j]);
                }
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
                ans = max(ans, dp[n][i]);
        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
