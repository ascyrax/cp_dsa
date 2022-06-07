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
        freopen("feast.in", "r", stdin);
        freopen("feast.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;
int dp[int(5e6) + 1];
//...............................

void suraj()
{
        int t, a, b;
        cin >> t >> a >> b;
        dp[0] = 1;
        // dp[a] = 1;
        // dp[b] = 1;
        for (int i = 0; i <= t; i++)
        {
                if ((i - a >= 0 && dp[i - a] == 1) || (i - b >= 0 && dp[i - b] == 1))
                {
                        dp[i] = 1;
                }
        }
        for (int i = 0; i <= t; i++)
        {
                if (dp[i] == 1)
                        dp[i / 2] = 1;
        }
        int ans = 0;
        for (int i = 0; i <= t; i++)
        {
                if (dp[i] == 1)
                        ans = max(ans, i);
                if ((i - a >= 0 && dp[i - a] == 1) || (i - b >= 0 && dp[i - b] == 1))
                {
                        dp[i] = 1;
                        ans = max(ans, i);
                }
        }
        // for (int i = t; i >= 0; i--)
        // {
        //         if (dp[i] == 1)
        //         {
        //                 cout << i << endl;
        //                 return;
        //         }
        // }
        cout << ans << endl;
}

//................................
