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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        ioss
            // startTime=(double)clock();
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

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;

        vector<ll> v(n);

        for (ll &i : v)
                cin >> i;

        ll ans = 0;

        map<ll, vector<ll>> m;

        for (ll i = 0; i < n; i++)
        {
                m[v[i]].pb(i);
        }

        for (auto el : m)
        {
                // cout << "el.first = " << el.first << endl;
                // for (auto i : el.second)
                //         cout << i << " ";
                // cout << endl;
                vector<ll> two = el.second;
                int len = two.size();
                if (len >= 2)
                {
                        for (int i = 1; i < len; i++)
                        {
                                // 3 2 31 5 22 11 23 34 5 6 7
                                // first two right side
                                ans = max(ans, (two[i - 1]) + 1 + ((n - 1) - two[i]));
                                // // first two left side
                                // ans = max(ans, (two[1]));

                                // last two right side
                                ans = max(ans, (two[i - 1]) + 1 + ((n - 1) - two[i]));
                                // last two left side
                        }
                }
        }

        if (ans == 0)
                cout << -1 << endl;
        else
                cout << ans << endl;
}

//................................
// ll
// ll
// int
// int
