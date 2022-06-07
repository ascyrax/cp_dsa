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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
                cin >> i;
        for (int &i : b)
                cin >> i;

        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++)
                pos[a[i]] = i;

        vector<int> c(n);
        for (int i = 0; i < n; i++)
                c[i] = pos[b[i]];

        int inf = 1e9;
        vector<int> dp(n + 1, inf);
        dp[0] = -inf;

        // dp[i] = value which comes at the lis of length i.

        // find length of lis in c;
        for (int i = 0; i < n; i++)
        {
                int j = upper_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
                // if (dp[j - 1] < c[i] && c[i] < dp[j]) // maybe this is optional always.
                dp[j] = c[i];
        }

        // for (int i = 0; i <= n; i++)
        //         cout << dp[i] << " ";
        // cout << endl;
        int ans = 0;
        for (int i = 0; i <= n; i++)
                if (dp[i] < inf)
                        ans = max(ans, i);
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
