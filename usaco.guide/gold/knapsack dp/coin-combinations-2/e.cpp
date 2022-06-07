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
int mod = 1e9 + 7;
//...............................

void suraj()
{
        int n, x;
        cin >> n >> x;

        vector<int> coins(n + 1);
        for (int i = 1; i <= n; i++)
                cin >> coins[i];

        sort(coins.begin(), coins.end());

        // total sum and also the last coin used is important
        // so we will deal with all the possible cases of coins as the last coin
        vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));

        // dp[i][j] = no of ordered ways to form sum i if coins[j] is the last coin used
        // dp[i][j] = dp[i-coin][k] where coin>=k
        for (int i = 1; i < n; i++)
                dp[0][i] = 0; // i.e. ordered ways to form sum 0 using the coins[j] as the last coin = 0.

        dp[0][0] = 1; // :)

        for (int i = 0; i <= x; i++)
        {
                for (int j = 0; j <= n; j++)
                {
                        for (int k = j; k <= n; k++)
                        {
                                if (k == 0)
                                        continue;
                                // if the last coin chosen to form the sum i was coins[k]
                                if (i + coins[k] <= x)
                                {
                                        // cout << "i = " << i << ", j = " << j << " , k = " << k << endl;
                                        dp[i + coins[k]][k] += dp[i][j];
                                        dp[i + coins[k]][k] %= mod;
                                }
                        }
                }
        }
        // for (int i = 0; i <= 9; i++)
        // {
        //         for (int j = 0; j <= 3; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        ll ans = 0;
        for (int i = 0; i <= n; i++)
        {
                ans += dp[x][i];
                ans %= mod;
        }

        cout << ans << endl;
}

//................................

// int

// int

// int

// int
