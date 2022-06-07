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
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................
bool distFirst(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
        if (a.first.second < b.first.second)
                return true;
        else
                return false;
}
//...............................

void suraj()
{
        ll n, l, k;
        cin >> n >> l >> k;

        vector<ll> dist(n), sl(n);
        for (ll &i : dist)
                cin >> i;
        for (ll &i : sl)
                cin >> i;
        if (n == 1)
        {
                cout << l * sl[0] << endl;
                return;
        }
        vector<pair<pair<ll, ll>, ll>> vp, vp2;
        // cout << "hi" << endl;
        for (ll i = 1; i < n; i++)
        {
                vp.pb(make_pair(make_pair(sl[i], dist[i]), i));
        }

        sort(vp.rbegin(), vp.rend());

        // pair<pair<ll, ll>, ll> slmin = {{1e9, 1e9}, -1};

        // for (auto el : vp)
        // {
        //         if (el.first.first < slmin.first.first)
        //                 slmin = el;
        // }

        if (k == n - 1)
        {
                // if smallest speedLimit<first
                // remove all but smallest
                if (vp[n - 1].first.first < sl[0])
                {
                        cout << vp[n - 1].first.second * sl[0] + (l - vp[n - 1].first.second) * vp[n - 1].first.first << endl;
                }
                else // else remove all
                {
                        cout << sl[0] * l << endl;
                }
        }
        else
        {
                // remove all k speedLimit beginning from the higher values first
                for (ll i = k; i < vp.size(); i++)
                {
                        vp2.pb(vp[i]);
                }
                // cout << "vp2.size() = " << vp2.size() << endl;
                sort(vp2.begin(), vp2.end(), distFirst);
                // cout << "vp2" << endl;
                // for (auto el : vp2)
                //         cout << el.first.first << " " << el.first.second << " " << el.second << endl;
                // cout << "---" << endl;
                ll lenv2 = vp2.size();
                ll ans = 0;
                ll prevsl = sl[0];
                ll prevd = 0;
                // cout << "lenv2 = " << lenv2 << endl;
                for (ll i = 0; i < lenv2; i++)
                {
                        // cout << "i = " << i << endl;
                        ans += prevsl * (vp2[i].first.second - prevd);
                        // cout << "ans = " << ans << endl;
                        prevsl = vp2[i].first.first;
                        prevd = vp2[i].first.second;
                }
                // cout << "prevd = " << prevd << " , prevsl = " << prevsl << endl;
                ans += (l - prevd) * prevsl;
                cout << ans << endl;
        }
}

//................................
// ll
// int
// int
// int
