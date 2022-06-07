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
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        // for (int i = 1; i <= n; i++)
        //         cin >> v[i];
        for (int &i : v)
                cin >> i;

        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

        // dp[i][j] = sum i using the first (j+1) coins.
        // dp[v[1]][1]=1;
        // or
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= x; j++)
                {
                        dp[i][j] = dp[i - 1][j]; // when the ith coin was not used
                        int left = j - v[i - 1];
                        if (left >= 0)
                        {
                                dp[i][j] += dp[i][left];
                                dp[i][j] %= mod;
                        } // when jth coin was used in the last
                }
        }
        // int ans = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //         ans += dp[x][i];
        //         ans %= mod;
        // }
        // cout << ans << endl;
        cout << dp[n][x] << endl;
}

//................................

// int

// int

// int

// int
