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
int n;
vector<int> v;
//...............................

//...............................

void suraj()
{
        cin >> n;
        v = vector<int>(n, 0);
        for (int &i : v)
                cin >> i;
        int lisLen = 0;
        vector<int> dp(n + 1, INF);
        dp[0] = NEG_INF;
        //dp[i]= a lis of length i will end at
        for (int i = 0; i < n; i++)
        {
                //we r talkin about v[i] now
                // for (int j = 1; j <= n; j++)
                int j = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
                {
                        if (dp[j] > v[i] && dp[j - 1] < v[i])
                                dp[j] = v[i];
                }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
                // cout << dp[i] << endl;
                if (dp[i] < INF)
                        ans = i;
        }
        cout << ans << endl;
}

//................................
