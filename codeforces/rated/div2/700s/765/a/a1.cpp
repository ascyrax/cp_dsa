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
        ll n, l;
        cin >> n >> l;

        vector<ll> v(l);

        for (ll i = 0; i < n; i++)
        {
                ll x;
                cin >> x;
                ll index = 0;
                while (x)
                {
                        if (x % 2 == 1)
                                v[index]++;
                        index++;
                        x /= 2;
                }
        }
        ll index = 0;
        ll ans = 0;

        // for (ll i = l - 1; i >= 0; i--)
        // {
        //         cout << v[i] << " ";
        // }
        // cout << endl;

        for (ll i = 0; i < l; i++, index++)
        {
                // cout << "i = " << i << endl;
                // cout << "v[i] = " << v[i] << endl;
                if (v[i] >= (n + 1) / 2)
                {
                        // cout << "if" << endl;
                        // cout << "pow(2,index) = " << pow(2, index) << endl;
                        ans += pow(2, index);
                }
        }
        cout << ans << endl;
}

//................................
// ll
// int
// int
// int
