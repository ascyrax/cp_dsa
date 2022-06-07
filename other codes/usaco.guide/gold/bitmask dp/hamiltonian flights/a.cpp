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

        vector<vector<int>> idg(n + 1, vector<int>());

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                idg[b].pb(a); // inverse directed graph
        }

        vector<vector<int>> dp(pow(2, n), vector<int>(n + 1, 0));
        // dp[s][j] = total no of flights to reach j from 1, if the subset s is chosen as the list of all the visited cities.....

        dp[1][1] = 1;

        for (int i = 0; i < (1 << n); i++)
        {
                // 1st city i.e. syrjala must be in the subset.
                if (i & (1 << 0) == 0)
                        continue;
                if (i & (1 << (n - 1)) && i != ((1 << n) - 1))
                        continue;
                for (int j = 1; j <= n; j++)
                {
                        // dp[i][j] = ?

                        // cout << "i = " << i << " , j = " << j << endl;
                        if ((i & (1 << (j - 1))) == 0)
                                continue;
                        // cout << "neigh = " << endl;
                        for (auto neigh : idg[j])
                        {
                                // cout << neigh << endl;
                                if (i & (1 << (neigh - 1)))
                                {
                                        (dp[i][j] += dp[i ^ (1 << (j - 1))][neigh]) %= mod;
                                }
                        }
                }
        }

        cout << dp[(1 << n) - 1][n] << endl;
}

//................................

// int

// int

// int

// int
