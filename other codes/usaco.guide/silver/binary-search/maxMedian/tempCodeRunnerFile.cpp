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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        ll l = 1, r = 2e5;
        while (r - l > 1)
        {
                cnt++;
                ll m = l + (r - l) / 2;
                // check if m can be a median or not
                // cout << "m = " << m << endl;
                vector<ll> b = v;
                for (ll &i : b)
                {
                        if (i >= m)
                                i = 1;
                        else
                                i = -1;
                }
                vector<ll> ps;
                ps.pb(0);
                for (ll i : b)
                {
                        ps.pb(ps.back() + i);
                }
                ll flag = -1;
                // cout << "yo" << endl;
                // for (int i : b)
                // cout << i << " ";
                // cout << endl;
                // for (int i : ps)
                // cout << i << " ";
                // cout << endl;
                for (ll i = k; i <= n; i++)
                {
                        if (ps[i] - ps[i - k] > 0)
                        {
                                ans = max(ans, m);
                                flag = 1;
                                break;
                        }
                }
                if (flag == -1)
                {
                        r = m;
                }
                else
                        l = m;
                // cout << "l = " << l << " r = " << r << endl;
        }
        cout << l << endl;
}

//................................