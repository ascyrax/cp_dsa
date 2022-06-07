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
//...............................

void suraj()
{
        cin >> n >> w;
        for (ll i = 1; i <= n; i++)
        {
                ll wi, vi;
                cin >> wi >> vi;
                for (ll j = 0; j <= w; j++)
                {
                        if (j - wi >= 0)
                                dp[i][j] = max(dp[i - 1][j], vi + dp[i - 1][j - wi]);
                        else
                                dp[i][j] = dp[i - 1][j];
                }
        }
        ll ans = 0;
        for (ll j = 0; j <= w; j++)
        {
                ans = max(ans, dp[n][j]);
        }
        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
