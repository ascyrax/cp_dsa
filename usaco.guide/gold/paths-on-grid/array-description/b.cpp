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
        int mod = 1e9 + 7;
        int n, m;
        cin >> n >> m;

        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
                cin >> v[i];

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // dp[0][0] = 1;

        if (v[1] != 0)
        {
                dp[1][v[1]] = 1;
        }
        else
        {
                for (int i = 1; i <= m; i++)
                        dp[1][i] = 1;
        }

        // dp[i][j] => no of ways to form the prefix of length i, if j is the ith element of the prefix.

        for (int i = 2; i <= n; i++)
        {
                if (v[i] != 0)
                {
                        // if (v[i - 1] != 0)
                        //         (dp[i][v[i]] += dp[i - 1][v[i - 1]]) %= mod;
                        // else
                        // {

                        if (v[i] - 1 >= 1)
                                (dp[i][v[i]] += dp[i - 1][v[i] - 1]) %= mod;
                        (dp[i][v[i]] += dp[i - 1][v[i]]) %= mod;
                        if (v[i] + 1 <= m)
                                (dp[i][v[i]] += dp[i - 1][v[i] + 1]) %= mod;
                        // }
                }
                else
                {
                        for (int j = 1; j <= m; j++)
                        {
                                // if (v[i - 1] != 0)
                                // {
                                //         (dp[i][j] += dp[i - 1][v[i - 1]]) %= mod;
                                // }
                                // else
                                // {
                                if (j - 1 >= 0)
                                        (dp[i][j] += dp[i - 1][j - 1]) %= mod;
                                (dp[i][j] += dp[i - 1][j]) %= mod;
                                if (j + 1 <= m)
                                        (dp[i][j] += dp[i - 1][j + 1]) %= mod;
                                // }
                        }
                }
        }
        int ans = 0;
        if (v[n] == 0)
        {
                for (int i = 1; i <= m; i++)
                {
                        (ans += dp[n][i]) %= mod;
                }
                cout << ans << endl;
        }
        else
                cout << dp[n][v[n]] << endl;
}

//................................

// int

// int

// int

// int
