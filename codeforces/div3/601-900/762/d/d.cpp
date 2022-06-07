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
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid;
        grid.pb(vector<int>(n, 0));
        for (int i = 1; i <= m; i++)
        {
                vector<int> shop(n);
                for (int &i : shop)
                        cin >> i;
                grid.pb(shop);
        }

        vector<int> dp[m + 1][n - 1 + 1];
        // dp[i][j] => best gift vector if from the first i shops j shops are chosen

        for (int i = 0; i <= m; i++)
        {
                for (int j = 0; j <= n - 1; j++)
                {
                        vector<int> temp = vector<int>(n, 0);
                        dp[i][j] = temp;
                }
        }

        dp[1][1] = grid[1];

        for (int i = 1; i <= m; i++)
        {
                for (int j = 1; j <= n - 1 && j <= i; j++)
                {
                        cout << "first k loop" << endl;
                        // if this shop is chosen
                        for (int k = 0; k < n; k++)
                        {

                                dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j - 1][k], grid[i][k]));
                        }
                        cout << "i = " << i << " j = " << j << endl;
                        cout << "dp[" << i << "][" << j << "] : " << endl;
                        for (auto el : dp[i][j])
                                cout << el << " ";
                        cout << endl;
                        // if this shop is not chosen
                        cout << "second k loop" << endl;
                        for (int k = 0; k < n; k++)
                        {
                                if (i - 1 >= 0 && j - 1 >= 0)
                                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                        }
                        cout << "i = " << i << " j = " << j << endl;
                        cout << "dp[" << i << "][" << j << "] : " << endl;
                        for (auto el : dp[i][j])
                                cout << el << " ";
                        cout << endl;
                }
        }

        int ans = 1e9 + 9;
        for (auto el : dp[m][min(m, n - 1)])
                ans = min(ans, el);
        cout << ans << endl;

        for (auto el : dp[1][1])
                cout << el << " ";
        cout << endl;
        for (auto el : dp[2][1])
                cout << el << " ";
        cout << endl;
        for (auto el : dp[2][2])
                cout << el << " ";
        cout << endl;
        for (auto el : dp[4][2])
                cout << el << " ";
        cout << endl;
}

//................................
// 3 2 4 8 2