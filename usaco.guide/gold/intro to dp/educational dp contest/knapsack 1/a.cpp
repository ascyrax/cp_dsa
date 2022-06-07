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

        vector<ll> v(n + 1), w(n + 1);

        for (ll i = 1; i <= n; i++)
        {
                cin >> w[i] >> v[i];
        }

        ll dp[wmax + 1];
        // initializa all value to 0.
        for (int i = 0; i <= wmax; i++)
                dp[i] = 0;
        // dp[i] is the max value of items which total to a weight of i.
        // base case
        dp[0] = 0;

        for (ll i = 1; i <= wmax; i++)
        {
                // vector<bool> flag(n + 1, false);
                // int curr = -1, prev = -1;
                for (ll j = 1; j <= n; j++)
                {
                        // if (flag[j] == true)
                        // {
                        //         continue;
                        // }
                        if (i - w[j] >= 0)
                        {
                                if (dp[i - w[j]] + v[j] >= dp[i])
                                {
                                        // curr = j;
                                        dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
                                        // flag[j]
                                }
                                else
                                {
                                        dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
                                }
                        }
                }
                // if (curr != -1)
                //         flag[curr] = true;
        }
        ll ans = 0;
        for (ll i = 1; i <= wmax; i++)
        {
                cout << "dp[" << i << "] = " << dp[i] << endl;
                ans = max(ans, dp[i]);
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// ll

// int
