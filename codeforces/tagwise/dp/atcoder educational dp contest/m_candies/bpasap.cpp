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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, k;
vector<int> v;
//...............................

//...............................

void suraj()
{
        cin >> n >> k;
        v = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
                cin >> v[i];
        //let dp[i][j]= no of ways to distribute j candies among first i children
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= v[i]; j++)
                {
                        cout << i << " " << j << endl;
                        if (i == 1)
                                dp[1][j] = 1;
                        // dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                        int sum = 0;
                        for (int k = 0; k <= min(j, min(v[i], v[i - 1])); k++)
                        {
                                sum += dp[i - 1][k];
                        }
                        dp[i][j] = max(dp[i][j], sum);
                }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j <= v[i]; j++)
                {
                        ans = max(dp[i][j], ans);
                        ans %= MOD;
                        // cout << dp[i][j] << " ";
                }
                // cout << endl;
        }

        // cout << dp[n][k] << endl;
        cout << ans % MOD << endl;
}

//................................
