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
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, w;
vector<pair<int, int>> cows;
vector<int> weights, talents;
vector<vector<int>> dp;
//...............................
bool doable(int y)
{
        for (int j = 0; j < n; j++)
        {
                int value = 1000 * talents[j] - y * weights[j];
                for (int k = 0; k <= w; k++)
                {
                        dp[j][k] = max(dp[j - 1][k - weights[j]] + value, dp[j][k]);
                        dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                }
        }
        if (dp[n - 1][w] >= y)
        {
        }
}
//...............................

void suraj()
{
        cin >> n >> w;
        cows = vector<pair<int, int>>(n);
        weights = vector<int>(n);
        talents = vector<int>(n);
        dp = vector<vector<int>>(n, vector<int>(w));
        for (int i = 0; i < n; i++)
        {
                int a, b;
                cin >> a >> b;
                weights[i] = a;
                talents[i] = b;
                cows[i] = make_pair(a, b);
        }
        int lo = 0;
        int hi = 250 * 1000 * 1000;
        while (hi > lo + 1)
        {
                int mid = lo + (hi - lo) / 2;
                if (doable(mid))
                        lo = mid;
                else
                        hi = mid;
        }
        cout << lo << endl;
}

//................................
