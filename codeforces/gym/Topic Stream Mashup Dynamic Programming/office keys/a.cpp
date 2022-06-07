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
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e17);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
ll n, k, p;
vector<ll> vn, vk;
vector<vector<ll>> dp;
//...............................

//...............................

void suraj()
{
        cin >> n >> k >> p;
        vn = vector<ll>(n, 0);
        vk = vector<ll>(k, 0);
        dp = vector<vector<ll>>(k + 1, vector<ll>(n + 1, 0));
        for (ll &i : vn)
                cin >> i;
        for (ll &i : vk)
                cin >> i;
        // dp[i][j]= min cost if we are at the ith key position and we have used j pupil
        // dp[i][j+1]=min(dp[i][j+1],dp[i][j])
        for (ll i = 0; i <= k; i++)
                for (ll j = 0; j <= n; j++)
                        dp[i][j] = INF;
        dp[0][0] = 0;
        for (int i = 0; i <= k; i++)
        {
                for (int j = 0; j <= n; j++)
                {
                        // if the jth person went for the ith key
                        dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j]);
                        // if not
                        dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i - 1][j]);
                }
        }
}

//................................
