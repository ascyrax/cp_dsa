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
        int k;
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
                cin >> v[i];
        }

        int dp[k][4];
        for (int i = 0; i < k; i++)
                for (int j = 0; j < 4; j++)
                        dp[i][j] = 1e9;

        // dp[i][j] = min no of rule breaks for index i=0 to i=i, if the last element is represented as j, where j will belong from 0 to 3.

        // trust the above rule.

        // green box.
        // dp[i][j] = dp[i-1][corresponding value wrt v[i] and v[i-1]].

        // base case.

        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0; // i.e. no rule breaks if the first element is represented as any of the four notes.

        for (int i = 1; i < k; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                        if (v[i] > v[i - 1])
                        {
                                // j should be > z if z is the note chosen by aliens for the i-1 th element.
                                for (int z = 0; z < 4; z++)
                                {
                                        if (j > z)
                                                dp[i][j] = min(dp[i][j], dp[i - 1][z]);
                                        else
                                                dp[i][j] = min(dp[i][j], dp[i - 1][z] + 1);
                                }
                        }
                        else if (v[i] < v[i - 1])
                        {
                                // j should be < z if z is the note chosen by aliens for the i-1 th element.
                                for (int z = 0; z < 4; z++)
                                {
                                        if (j < z)
                                                dp[i][j] = min(dp[i][j], dp[i - 1][z]);
                                        else
                                                dp[i][j] = min(dp[i][j], dp[i - 1][z] + 1);
                                }
                        }
                        else
                        {
                                // j should be = z if z is the note chosen by aliens for the i-1 th element.
                                for (int z = 0; z < 4; z++)
                                {
                                        if (j == z)
                                                dp[i][j] = min(dp[i][j], dp[i - 1][z]);
                                        else
                                                dp[i][j] = min(dp[i][j], dp[i - 1][z] + 1);
                                }
                        }
                }
        }

        int ans = 1e9;
        for (int i = 0; i < 4; i++)
                ans = min(ans, dp[k - 1][i]);
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
