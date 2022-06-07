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
        // ioss
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

vector<ll> parent, cnt;
//...............................
ll findParent(ll a)
{
        if (parent[a] == a)
                return a;
        else
        {
                return findParent(parent[a]);
        }
}
//...............................

void suraj()
{
        ll n;
        cin >> n;
        parent = vector<ll>(n);
        cnt = vector<ll>(n, 1);

        for (int i = 0; i < n; i++)
        {
                parent[i] = i;
        }
        vector<pair<ll, pair<ll, ll>>> inp;
        for (ll i = 1; i <= n - 1; i++)
        {
                ll u, v, w;
                cin >> u >> v >> w;
                u--;
                v--;
                inp.pb(make_pair(w, make_pair(u, v)));
        }
        sort(inp.begin(), inp.end());
        ll ans = 0;
        for (ll i = 0; i <= n - 2; i++)
        {
                ll w = inp[i].first;
                ll u = inp[i].second.first;
                ll v = inp[i].second.second;
                ll pu = findParent(u);
                ll pv = findParent(v);
                ll cntpu = cnt[pu];
                ll cntpv = cnt[pv];
                ans += (cntpu * cntpv) * w;
                if (cntpu > cntpv)
                {
                        parent[pv] = pu;
                        cnt[pu] += cnt[pv];
                }
                else
                {
                        parent[pu] = pv;
                        cnt[pv] += cntpu;
                }
        }
        cout << ans << endl;
}

//................................
// ll
// int
// int
// int
