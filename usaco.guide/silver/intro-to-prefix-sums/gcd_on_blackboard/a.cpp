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

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        vector<ll> gcdLeft(n), gcdRight(n);
        gcdLeft[0] = v[0];
        gcdRight[n - 1] = v[n - 1];
        for (int i = 1; i < n; i++)
        {
                gcdLeft[i] = __gcd(gcdLeft[i - 1], v[i]);
                gcdRight[n - i - 1] = __gcd(gcdRight[n - i], v[n - i - 1]);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
                if (i == 0)
                        ans = max(ans, gcdRight[1]);
                else if (i == n - 1)
                        ans = max(ans, gcdLeft[n - 2]);
                else
                        ans = max(ans, __gcd(gcdLeft[i - 1], gcdRight[i + 1]));
        }
        cout << ans << endl;
}

//................................
