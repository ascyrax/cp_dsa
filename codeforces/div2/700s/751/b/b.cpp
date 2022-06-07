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
        vector<ll> a(n);
        map<ll, ll> cnt, cnt2;
        for (ll &i : a)
        {
                cin >> i;
                cnt[i]++;
        }
        map<ll, ll> final;
        for (auto el : cnt)
        {
                cnt2[el.second]++;
        }
        for (auto el : cnt)
        {
                final[el.first] = cnt2[el.second] * el.second;
        }
        map<ll, ll> steps;
        for (auto el : final)
        {
                steps[el.first] = (el.second / el.first) / 2;
        }
        cout << "cnt" << endl;
        for (auto el : cnt)
        {
                cout << el.first << " " << el.second << endl;
        }
        cout << "cnt2" << endl;
        for (auto el : cnt2)
                cout << el.first << " " << el.second << endl;
        cout << "final" << endl;
        for (auto el : final)
        {
                cout << el.first << " " << el.second << endl;
        }
        ll q;
        cin >> q;
        for (ll i = 0; i < q; i++)
        {
                ll x, k;
                cin >> x >> k;
                ll num = a[x - 1];
                cout << "num = " << a[x - 1] << endl;
                cout << "final = " << final[a[x - 1]] << endl;
                cout << min(ll(pow(a[x - 1], k)), final[a[x - 1]]) << endl;
        }
}

//................................
