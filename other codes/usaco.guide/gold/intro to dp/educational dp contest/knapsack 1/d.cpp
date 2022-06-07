// @author: ascyrax

// solution using 1-D dp.

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

        vector<ll> dp(wmax + 1);
        // dp[0]=0;

        for (ll i = 1; i <= n; i++)
        {
                ll w, v;
                cin >> w >> v;

                // right to left becz we cant count same item twice.
                for (int j = wmax; j >= w; j--)
                {
                        dp[j] = max(dp[j], dp[j - w] + v);
                }
        }

        ll ans = 0;
        for (ll i : dp)
                ans = max(ans, i);

        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
