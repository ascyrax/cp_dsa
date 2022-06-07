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
        v.pb(0);
        for (int i = 0; i < n; i++)
        {
                int a;
                cin >> a;
                v.pb(a);
        }
        vector<int> dp(n + 1, INF);
        dp[1] = 0;
        dp[0] = 0;
        for (int i = 2; i <= n; i++)
        {
                dp[i] = min(dp[i], dp[i - 1] + abs(v[i] - v[i - 1]));
                if (i - 2 >= 1)
                        dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 2]));
                // cout << dp[i] << endl;
        }
        // for (int i : dp)
        //         cout << i << " ";
        // cout << endl;
        cout << dp[n] << endl;
}

//................................
