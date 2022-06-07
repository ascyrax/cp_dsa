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

        ioss

            // startTime=(double)clock();

            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

            // cout << setprecision(15) << fixed;

            int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
pair<int, pair<int, int>> dp[41][41];
//...............................

void suraj()
{
        int n, k;
        cin >> n >> k;

        for (int i = 0; i <= 40; i++)
                for (int j = 0; j <= 40; j++)
                {
                        dp[i][j] = make_pair(0, make_pair(0, 0));
                }

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
                cin >> b[i];
        }

        // dp[i][j].first = max value for min(sum a, sum b) if from the first i indices j has been chosen.
        // dp[i][j].second = corresponding values of {suma,sumb}

        // base cases
        dp[0][1].first = min(a[0], b[0]);
        dp[0][1].second.first = a[0];
        dp[0][1].second.second = b[0];

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j <= min(k, i + 1); j++) // since in nCr r cannot be greater than n
                {
                        // if we take the ith indexed element.
                        if (i - 1 >= 0 && j - 1 >= 0)
                                if (min(dp[i - 1][j - 1].second.first + a[i], dp[i - 1][j - 1].second.second + b[i]) >= dp[i][j].first)
                                {
                                        dp[i][j].first = min(dp[i - 1][j - 1].second.first + a[i], dp[i - 1][j - 1].second.second + b[i]);
                                        dp[i][j].second.first = dp[i - 1][j - 1].second.first + a[i];
                                        dp[i][j].second.second = dp[i - 1][j - 1].second.second + b[i];
                                }
                        // if we dont take the ith indexed element
                        if (i - 1 >= 0)
                                if (dp[i - 1][j].first >= dp[i][j].first)
                                {
                                        dp[i][j].first = dp[i - 1][j].first;
                                        dp[i][j].second.first = dp[i - 1][j].second.first;
                                        dp[i][j].second.second = dp[i - 1][j].second.second;
                                }
                }
        }

        // for (int i = 0; i <= 6; i++)
        // {
        //         for (int j = 0; j <= 3; j++)
        //         {
        //                 cout << dp[i][j].first << "," << dp[i][j].second.first << "," << dp[i][j].second.second << " ";
        //         }
        //         cout << endl;
        // }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
                ans = max(ans, dp[i][k].first);
        }
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
