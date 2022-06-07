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
ll n, k;
vector<ll> v;
ll dp[201][201][31];

//...............................
ll find2(ll a)
{
        ll cnt = 0;
        while (a > 1)
        {
                if (a % 2 == 0)
                {
                        cnt++;
                        a /= 2ll;
                }
                else
                        break;
        }
        return cnt;
}
ll find5(ll a)
{
        ll cnt = 0;
        while (a > 1)
        {
                if (a % 5 == 0)
                {
                        cnt++;
                        a /= 5ll;
                }
                else
                        break;
        }
        return cnt;
}
//...............................

void suraj()
{
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
                ll a;
                cin >> a;
                v.pb(a);
        }

        // 0-1 knapsack
        // mine
        // dp[i][j]=max roundness of the product if j elements are chosen
        // only from the first i elements of the array is chosen

        //editorial's
        //dp[i][j][l]=max power of 2 among the first i elements having taken j
        //of them with power of 5 equal to l;

        //if the ith element is not taken
        //dp[i][j][l] = dp[i-1][j][l]

        //if the ith element is taken then
        //dp[i][j][l]=dp[i-1][j-1][l- no of 5s in ith element]+no of 2s in ith element

        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= k; j++)
                {
                        for (int l = 1; l <= 35; l++)
                        {
                                //if ith book was taken
                                if (l - find5(v[i - 1]) >= 0)
                                        dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - find5(v[i - 1])] + find2(v[i - 1]));
                                //if ith book was not taken
                                dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);
                        }
                }
        }
        ll ans = 0;

        for (ll l = 0; l <= 35; l++)
        {
                ans = max(ans, min(l, dp[n][k][l]));
        }
        cout << ans << endl;
}

//................................
