#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
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
pair<ll, ll> dp[201][201];
pair<ll, ll> fact[201];

//...............................
pair<ll, ll> twofive(ll n)
{
    ll ntwo = 0, nfive = 0;
    while (true)
    {
        if (n % 2 == 0)
        {
            ntwo++;
            n /= 2;
        }
        else if (n % 5 == 0)
        {
            nfive++;
            n /= 5;
        }
        else
            break;
    }
    return make_pair(ntwo, nfive);
}
void suraj()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = twofive(v[i - 1]);
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k && j <= i; j++)
        {
            pair<ll, ll> temp = make_pair(dp[i - 1][j - 1].first + fact[i].first, dp[i - 1][j - 1].second + fact[i].second);
            if (min(dp[i - 1][j].first, dp[i - 1][j].second) > min(temp.first, temp.second))
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (min(dp[i - 1][j].first, dp[i - 1][j].second) == min(temp.first, temp.second))
            {
                dp[i][j] = temp; //or dp[i][j]=dp[i-1][j]
            }
            else if (min(dp[i - 1][j].first, dp[i - 1][j].second) < min(temp.first, temp.second))
            {
                dp[i][j] = temp;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         cout << dp[i][j].first << " " << dp[i][j].second << " ";
    //     }
    //     cout << endl;
    // }
    cout << min(dp[n][k].first, dp[n][k].second) << endl;
}

//................................
