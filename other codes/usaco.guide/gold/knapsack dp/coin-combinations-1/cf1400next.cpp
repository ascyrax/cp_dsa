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

//...............................

void suraj()
{
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        vector<ll> dp(x + 1);
        dp[0] = 1;

        for (int i = 1; i <= x; i++)
        {
                for (int coin : v)
                {
                        if (i - coin >= 0)
                                dp[i] += dp[i - coin];

                        dp[i] %= mod;
                }
                // cout << "x = " << i << endl;
                // cout << dp[i] << endl;
        }
        cout << dp[x] % mod << endl;
}

//................................
