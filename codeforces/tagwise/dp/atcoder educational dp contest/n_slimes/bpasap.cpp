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
        // ioss
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
int n;
vector<ll> vInitial;
//...............................

//...............................

void suraj()
{
        cin >> n;
        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                vInitial.push_back(x);
        }
        vector<ll> psSum = {0ll};
        for (int i = 0; i < n; i++)
        {
                psSum.pb(vInitial[i] + psSum.back());
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

        for (int i = 1; i <= n; i++)
                dp[i][i] = vInitial[i - 1];
        //dp[i][j]= min cost to merge slimes i....j into a slime
        for (int i = 1; i <= n; i++)
        {
                // cout << "i = 1" << endl;
                for (int j = i + 1; j <= n; j++)
                {
                        dp[i][j] = 1e18;
                        // cout << "j = 1" << endl;
                        for (int k = i; k < j; k++)
                        {
                                // cout << i << " " << j << " " << k << endl;
                                if (abs(j - 1) == 1)
                                {
                                        dp[i][j] = psSum[j] - psSum[i - 1];
                                }
                                else
                                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + psSum[j] - psSum[i - 1]);
                        }
                }
        }
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        cout << dp[i][j] << " ";
                }
                cout << endl;
        }
        // ll ans = 0;
        // for (int j = 1; j <= n; j++)
        //         ans += dp[1][j];
        // cout << ans << endl;
        cout << dp[1][n] << endl;
}

//................................
