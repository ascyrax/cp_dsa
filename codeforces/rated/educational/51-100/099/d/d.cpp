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
ll n, x;
vector<ll> v;
vector<vector<ll>> dp;
//...............................
bool check(ll i)
{
}
//...............................

void suraj()
{
        cin >> n >> x;
        v = vector<ll>(n, 0);
        dp = vector<vector<ll>>(501, vector<ll>(501, 0));
        for (ll &i : v)
                cin >> i;
        // x=j now swap =>
        // dp[i][j]=smallest no of swaps where last swap was between x and a[i]
        // and the current value of a[i] is j.
        // x=? maybe not needed
        ll ans = 0;
        for (ll i = 0; i <= 500; i++)
        {
                for (ll j = 0; j <= 500; j++)
                {
                        if (is_sorted(v.begin() + i, v.end()))
                        {
                                ans = min(ans, dp[i][j]);
                        }
                        for (ll k = 0; k <= 500; k++)
                        {
                                dp[k][v[i]] = min(dp[k][v[i]], dp[i][j] + 1);
                        }
                }
        }
}

// void suraj()
// {
//         cin >> n >> x;
//         for (int &i : v)
//                 cin >> i;
//         int swaps = 0;
//         for (int i = 0; i < n; i++)
//         {
//                 // check if i should be swapped or not
//                 auto chk = check(i);
//                 if (chk)
//                 {
//                         if (v[i] <= x)
//                         {
//                                 cout << -1 << endl;
//                                 return;
//                         }
//                         int temp = v[i];
//                         v[i] = x;
//                         x = temp;
//                         swaps++;
//                 }
//         }
//         cout << swaps << endl;
// }
//................................
