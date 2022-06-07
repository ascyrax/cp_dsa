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
        int n, k;
        cin >> n >> k;

        vector<int> h(n + 1);
        for (int i = 1; i <= n; i++)
                cin >> h[i];

        vector<int> dp(n + 1, 1e9);

        // dp[i] = min cost to reach stone i

        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
                for (int j = 1; j <= k; j++)
                {
                        if (i - j >= 1)
                                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
                }
        }

        cout << dp[n] << endl;
}

//................................

// int

// int

// int

// int
