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

        // freopen("1_04.in", "r", stdin);
        // freopen("shell.out", "w", stdout);

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
        ll n;
        cin >> n;
        vector<ll> h(n + 1);
        for (ll i = 1; i <= n; i++)
                cin >> h[i];

        vector<ll> dp(n + 1);
        // dp[i] is the minimum cost to reach the ith stone;
        dp[1] = 0;
        dp[2] = abs(h[2] - h[1]);
        for (ll i = 3; i <= n; i++)
        {
                dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
        }

        cout << dp[n] << endl;
}

//................................

// ll

// int

// int

// int
