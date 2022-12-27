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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
        map<ll, ll> cntt, cntd;
        vector<pair<ll, ll>> vp;
        for (ll i = 0; i < n; i++)
        {
                ll t, d;
                cin >> t >> d;
                cntt[t]++;
                cntd[d]++;
                vp.pb(make_pair(t, d));
        }
        sort(vp.begin(), vp.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
                ll t = vp[i].first;
                ll d = vp[i].second;
                // cout << "cntt[t] = " << cntt[t] << " "
                //      << "cntd[d] = " << cntd[d] << endl;
                ans += ((cntt[t] - 1) * (cntd[d] - 1));
                // cout << "ans = " << ans << endl;
        }
        cout << n * (n - 1) * (n - 2) / 6 - ans << endl;
}

//................................
