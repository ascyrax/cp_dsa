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
        // ioss
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
        ll w, h;
        cin >> w >> h;

        ll nh1;
        cin >> nh1;
        vector<ll> vh1(nh1);
        for (ll &i : vh1)
                cin >> i;
        ll nh2;
        cin >> nh2;
        vector<ll> vh2(nh2);
        for (ll &i : vh2)
                cin >> i;
        ll nv1;
        cin >> nv1;
        vector<ll> vv1(nv1);
        for (ll &i : vv1)
                cin >> i;
        ll nv2;
        cin >> nv2;
        vector<ll> vv2(nv2);
        for (ll &i : vv2)
                cin >> i;

        ll a, b, c, d;
        sort(vh1.begin(), vh1.end());
        sort(vh2.begin(), vh2.end());
        sort(vv1.begin(), vv1.end());
        sort(vv2.begin(), vv2.end());
        // for (int i : vv1)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : vv2)
        //         cout << i << " ";
        // cout << endl;
        a = h * (vh1[vh1.size() - 1] - vh1[0]);
        b = h * (vh2[vh2.size() - 1] - vh2[0]);
        c = w * (vv1[vv1.size() - 1] - vv1[0]);
        d = w * (vv2[vv2.size() - 1] - vv2[0]);
        cout << max(max(a, b), max(c, d)) << endl;
}

//................................
