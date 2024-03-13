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

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                cout << "Case #" << i << ": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................

void suraj()
{
        int inf = 1e9;

        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<vector<int>> dp(n, vector<int>(2, inf));

        // dp[i][j] = min palindrome substring ending at index i, if j is the character at the ith index in string s.
        // j can be either 0 or 1.

        // base case
        if (s[0] == '0')
        {
                dp[0][0] = 1;
                dp[0][1] = -1; // becz the first character cannot be 0.
        }
        else if (s[0] == '1')
        {
                dp[0][1] = 1;
                dp[0][0] = -1;
        }
        else if (s[0] == '?')
        {
                dp[0][0] = 1;
                dp[0][1] = 1;
        }

        for (int i = 1; i < n; i++)
        {
                if (s[i] == '?')
                {
                        // dp[i][1]
                        int leftIndex;
                        if (dp[i - 1][0] != -1)
                        {
                                leftIndex = i - dp[i - 1][0] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '1')
                                {

                                        dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2);
                                }
                                else
                                {
                                        dp[i][1] = min(dp[i][1], ((s[i - 1] == '1') ? 2 : 1));
                                }
                        }
                        if (dp[i - 1][1] != -1)
                        {
                                leftIndex = i - dp[i - 1][1] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '1')
                                {
                                        if (dp[i - 1][1] != -1)
                                                dp[i][1] = min(dp[i][1], dp[i - 1][1] + 2);
                                }
                                else
                                {
                                        dp[i][1] = min(dp[i][1], ((s[i - 1] == '1') ? 2 : 1));
                                }
                        }

                        // dp[i][0]
                        if (dp[i - 1][0] != -1)
                        {
                                leftIndex = i - dp[i - 1][0] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '0')
                                {
                                        if (dp[i - 1][0] != -1)
                                                dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2);
                                }
                                else
                                {
                                        dp[i][0] = min(dp[i][0], ((s[i - 1] == '0') ? 2 : 1));
                                }
                        }
                        if (dp[i - 1][1] != -1)
                        {
                                leftIndex = i - dp[i - 1][1] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '1')
                                {
                                        if (dp[i - 1][1] != -1)
                                                dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2);
                                }
                                else
                                {
                                        dp[i][0] = min(dp[i][0], ((s[i - 1] == '0') ? 2 : 1));
                                }
                        }
                }
                else if (s[i] == '1')
                {
                        dp[i][0] = -1;
                        int leftIndex;
                        if (dp[i - 1][0] != -1)
                        {
                                leftIndex = i - dp[i - 1][0] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '1')
                                {
                                        if (dp[i - 1][0] != -1)
                                                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2);
                                }
                                else
                                {
                                        dp[i][1] = min(dp[i][1], ((s[i - 1] == s[i]) ? 2 : 1));
                                }
                        }
                        if (dp[i - 1][1] != -1)
                        {
                                leftIndex = i - dp[i - 1][1] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '1')
                                {
                                        if (dp[i - 1][1] != -1)
                                                dp[i][1] = min(dp[i][1], dp[i - 1][1] + 2);
                                }
                                else
                                {
                                        dp[i][1] = min(dp[i][1], ((s[i - 1] == s[i]) ? 2 : 1));
                                }
                        }
                }
                else if (s[i] == '0')
                {
                        dp[i][1] = -1;
                        int leftIndex;
                        if (dp[i - 1][0] != -1)
                        {
                                leftIndex = i - dp[i - 1][0] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '0')
                                {
                                        if (dp[i - 1][0] != -1)
                                                dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2);
                                }
                                else
                                {
                                        dp[i][0] = min(dp[i][0], ((s[i - 1] == s[i]) ? 2 : 1));
                                }
                        }
                        if (dp[i - 1][1] != -1)
                        {
                                leftIndex = i - dp[i - 1][1] - 1;
                                if (leftIndex >= 0 && s[leftIndex] == '1')
                                {
                                        if (dp[i - 1][1] != -1)
                                                dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2);
                                }
                                else
                                {
                                        dp[i][0] = min(dp[i][0], ((s[i - 1] == s[i]) ? 2 : 1));
                                }
                        }
                }
                if (dp[i][0] >= 5 && dp[i][1] >= 5)
                {
                        cout << "IMPOSSIBLE" << endl;
                        return;
                }
        }

        cout << "dp" << endl;
        for (int i = 0; i < n; i++)
                cout << dp[i][0] << " " << dp[i][1] << "      ";
        cout << endl;

        if (dp[n - 1][0] < 5 || dp[n - 1][1] < 5)
                cout << "POSSIBLE" << endl;
        else
                cout << "IMPOSSIBLE" << endl;
}

//................................

// int

// int

// int

// int
