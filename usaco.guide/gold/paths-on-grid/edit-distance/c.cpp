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
        string a, b;
        cin >> a >> b;

        int lcs = 0;

        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

        for (int i = 0; i < a.size(); i++)
        {
                for (int j = 0; j < b.size(); j++)
                {
                        if (a[i] == b[j])
                        {
                                if (i - 1 >= 0 && j - 1 >= 0)
                                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]) + 1;
                                else
                                        dp[i][j] = 1;
                        }
                        else
                        {
                                if (i - 1 >= 0)
                                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                                if (j - 1 >= 0)
                                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                        }
                }
        }
        cout << dp[a.size() - 1][b.size() - 1] << endl;

        cout << max(a.size(), b.size()) - dp[a.size() - 1][b.size() - 1] << endl;
}

//................................

// int

// int

// int

// int
