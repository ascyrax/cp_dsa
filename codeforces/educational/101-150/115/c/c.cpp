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
        // ioss
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
        vector<ll> v(n);
        map<ll, ll> cnt;
        ll sum = 0;
        for (ll &i : v)
        {
                cin >> i;
                cnt[i]++;
                sum += i;
        }
        double k = (double(sum) / double(n));
        // cout << "k= " << k << endl;
        sort(v.begin(), v.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
                ll curr = v[i];
                auto it = lower_bound(v.begin(), v.end(), 2 * k - v[i]);
                if (*it != (2 * k - v[i]))
                        continue;
                ll cntIt = 0;
                if (it != v.end())
                        cntIt = cnt[*it];
                if (v[i] == (2 * k - v[i]))
                        ans += (cntIt - 1);
                else
                        ans += cntIt;
                // cout << "ans = " << ans << endl;
        }
        cout << ans / 2 << endl;
        // cout << "----------------------------------------------------------------" << endl;
}

//................................
