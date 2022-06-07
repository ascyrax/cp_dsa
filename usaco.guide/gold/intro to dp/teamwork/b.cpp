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
        vector<int> dp(n);
        // vector<int> sum(n);

        // dp[i] is the optimally max possible skill if only the first i cows are there
        for (int i = 0; i < n; i++)
        {
                // dp[i]=?
                int mx = v[i];

                for (int teamSize = 1; teamSize <= min(k, i + 1); teamSize++)
                {
                        // cout << "i = " << i << endl;
                        // cout << "teamSize = " << teamSize << endl;
                        // cout << "j  -> ";
                        for (int j = i; j >= max(0, i - teamSize + 1); j--)
                        {
                                // cout << j << " ";
                                mx = max(v[j], mx);

                                if (i - teamSize >= 0)
                                {
                                        // cout << "if" << endl;
                                        dp[i] = max(dp[i], dp[i - teamSize] + mx * teamSize);
                                }
                                else
                                {
                                        // cout << "else" << endl;
                                        dp[i] = max(dp[i], 0 + mx * teamSize);
                                }
                        }
                        // cout << endl;
                        // cout << "mx = " << mx << endl;
                        // cout << "dp[" << i << "] = " << dp[i] << endl;
                }
        }
        // for (int i : dp)
        // cout << i << " ";
        // cout << endl;
        cout << dp[n - 1] << endl;
}

//................................
