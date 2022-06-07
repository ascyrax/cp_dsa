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
ll n, w;
ll dp[101][100001];
// dp[i][j] = min sum of weights for which from the first i items a total value of j is chosen.
ll infinity = 1e15;
//...............................

void suraj()
{
        cin >> n >> w;
        for (ll i = 0; i <= n; i++)
                for (ll j = 0; j <= 1e5; j++)
                        dp[i][j] = infinity;
        dp[0][0] = 0;
        for (ll i = 1; i <= n; i++)
        {
                ll wi, vi;
                cin >> wi >> vi;

                for (ll j = 0; j <= 1e5; j++)
                {
                        if (j - vi >= 0)
                                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - vi] + wi);
                        else
                                dp[i][j] = dp[i - 1][j];
                }
        }

        // for (ll i = 0; i <= n; i++)
        // {
        //         for (ll j = 0; j <= 150; j++)
        //                 cout << dp[i][j] << " ";
        //         cout << endl;
        // }

        for (ll j = 1e5; j >= 0; j--)
                if (dp[n][j] <= w)
                {
                        cout << j << endl;
                        return;
                }
}

//................................

// ll

// int

// int

// int
