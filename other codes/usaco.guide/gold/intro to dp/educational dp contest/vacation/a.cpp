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

        int inputs[n + 1][3];
        for (int i = 1; i <= n; i++)
        {
                int a, b, c;
                cin >> inputs[i][0] >> inputs[i][1] >> inputs[i][2];
        }

        int dp[n + 1][3];

        for (int i = 0; i <= n; i++)
                for (int j = 0; j <= 2; j++)
                        dp[i][j] = 0;

        // dp[0][any] = 0.

        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= 2; j++)
                {
                        dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + inputs[i][j];
                }
        }
        cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}

//................................

// int

// int

// int

// int
