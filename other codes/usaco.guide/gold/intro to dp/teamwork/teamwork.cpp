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
        freopen("teamwork.in", "r", stdin);
        freopen("teamwork.out", "w", stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        vector<int> dp(n, 0);
        vector<int> mx = v;
        // dp[i] = max optimal sum of skill levels till the ith cow
        for (int i = 0; i < n; i++)
        {
                for (int j = 1; j <= k; j++) // j is the size of the last team
                {
                        int sum = 0;
                        int valMax = 0;
                        for (int e = max(0, i - j + 1); e <= i; e++)
                        {
                                valMax = max(valMax, v[e]);
                                // sum += valMax;
                        }
                        for (int e = max(0, i - j + 1); e <= i; e++)
                        {
                                sum += valMax;
                        }
                        // dp[i] = max(dp[i], dp[i - j] + sum(i - j + 1 to i));
                        if (i - j >= 0)
                                dp[i] = max(dp[i], dp[i - j] + sum);
                        else if (i - j == -1)
                        {
                                dp[i] = max(dp[i], 0 + sum);
                        }
                        // cout << "sum = " << sum << endl;
                        // cout << "dp[" << i << "] = " << dp[i] << endl;
                }
        }
        cout << dp[n - 1] << endl;
}

//................................
