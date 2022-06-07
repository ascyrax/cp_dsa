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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //ioss
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................
int n, x;
vector<int> vCoins;
int dp[(int)1e6 + 1][101];
int ans = 0;
//...............................

//...............................

void suraj()
{
        cin >> n >> x;
        vCoins = vector<int>(n, x);
        for (int &i : vCoins)
                cin >> i;
        sort(vCoins.begin(), vCoins.end());
        int minCoin = vCoins[0];
        int maxCoin = vCoins[n - 1];
        // dp[0] = 1; // inorder to make dp[coin]=1 where coin belongs to vCoins
        // for (int coin : vCoins)
        //         dp[coin]++;
        // for (int i = 0; i <= x; i++)
        // {
        //         for (int coin : vCoins)
        //         {
        //                 // if (i == 0)
        //                 // {
        //                 //         dp[i + coin] += dp[i] + 1;
        //                 // }
        //                 // else
        //                 if (dp[i] > 0)
        //                 {
        //                         dp[i + coin]++;
        //                 }
        //                 // cout << "i = " << i << "   "
        //                 //      << " coin = " << coin << endl;
        //                 // for (int i : dp)
        //                 //         cout << i << " ";
        //                 // cout << endl;
        //                 dp[i + coin] %= mod;
        //         }
        // }
        // cout << dp[x] % mod << endl;
        //dp[i][j] = no of ways of getting the sum i with ordered denominations ending in j
        for (int i = 1; i <= x; i++)
        {
                for (int j = minCoin; j <= maxCoin; j++)
                {
                        for (int coin : vCoins)
                        {
                                if (i - coin >= 0)
                                        dp[i][j] = dp[i][j] + dp[i - coin][j];
                        }
                }
        }
        for (int j = minCoin; j <= maxCoin; j++)
        {
                ans += dp[x][j];
                ans %= mod;
        }
        cout << ans << endl;
}

//................................
