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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> dp(n + 1);
        //dp[i]=no of good subarrays if ending at i

        // for (ll i = 1; i <= n; i++)
        // {
        //         ll current = s[i - 1] - '0';
        //         if (current == 1)
        //                 dp[i]++;
        //         dp[i] += dp[i - current];
        // }
        // ll ans = 0ll;
        // for (ll i : dp)
        // {
        //         cout << i << " ";
        //         ans += i;
        // }
        // cout << endl;
        // cout << ans << endl;
        vector<int> p(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
                p[i] = p[i - 1] + (s[i - 1] - '0');
        }
        //p[i]=sum of all the first i digits

        //subarray l to r is good if p[r] - p[l-1] = r-l+1;
        //viz p[r]-r=p[l-1]-(l-1)
        ll ans = 0;
        for (int i : p)
                cout << i << " ";
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
                // if (p[i] == 1)
                //         ans++;
                p[i] = p[i] - i;
        }
        for (int i : p)
                cout << i << " ";
        cout << endl;

        map<ll, ll> m;
        for (int i = 1; i <= n; i++)
        {
                m[p[i]]++;
        }
        m[p[0]]++;

        for (auto i : m)
        {
                // cout << i.first << " " << i.second << endl;
                ans += i.second * (i.second - 1) / 2;
        }
        cout << ans << endl;
}

//................................
