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
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        vector<vector<int>> dp(n, vector<int>(2, INF));
        // dp[i][j] = no of skip points used by my friend if
        // i monsters have been  killed and j is the last
        // dp[i][j] = min(dp[i][j],dp[i-1][j]+a[j],dp[i-2][!j]+a[j-1]+a[j],dp[i-1][!j]+a[j]);
        dp[0][0] = v[0];
        dp[1][0] = dp[0][0] + v[1];
        dp[0][1] = INF;
        dp[1][1] = dp[0][0];
        cout << "dp" << endl;
        for (int i = 0; i < n; i++)
        {
                cout << dp[i][0] << " " << dp[i][1] << "    ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < 2; j++)
                {
                        if (i - 1 >= 0)
                                dp[i][j] = min(dp[i][j], dp[i - 1][j] + v[j]);
                        if (i - 2 >= 0)
                                dp[i][j] = min(dp[i][j], dp[i - 2][!j] + v[j - 1] + v[j]);
                        if (i - 1 >= 0)
                                dp[i][j] = min(dp[i][j], dp[i - 1][!j] + v[j]);
                }
        }
        cout << "dp" << endl;
        for (int i = 0; i < n; i++)
        {
                cout << dp[i][0] << " " << dp[i][1] << "    ";
        }
        cout << endl;
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}
//................................
