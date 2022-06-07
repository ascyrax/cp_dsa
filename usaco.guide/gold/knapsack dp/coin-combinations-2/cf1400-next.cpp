#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;
int n, x;
int dp[int(1e6) + 1][100];

//...............................

void suraj()
{
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
        }
        // dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
                dp[v[i]][i] = 1;
        }
        for (int i = 0; i <= x; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        int coin = v[j];
                        if (i - coin >= 0)
                        {
                                for (int k = j; k < n; k++)
                                {
                                        dp[i][j] += dp[i - coin][k];
                                        dp[i][j] %= mod;
                                }
                        }
                }
                // for (int j = 0; j < n; j++)
                //         cout << dp[i][j] << " ";
                // cout << endl;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
                ans += dp[x][i];
                ans %= mod;
        }
        cout << ans << endl;
}

//................................
