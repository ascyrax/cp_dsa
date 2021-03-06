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
        int n;
        cin >> n;
        map<pair<int, int>, int> m;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
                int l, r;
                cin >> l >> r;
                m[make_pair(l, r)]++;
                vp.pb(make_pair(l, r));
        }

        for (auto p : vp)
        {
                int l = p.first;
                int r = p.second;
                if (l == r)
                {
                        cout << l << " " << r << " " << l << endl;
                        continue;
                }
                // cout << "p = " << p.first << " " << p.second << endl;
                for (int i = l; i <= r; i++)
                {
                        if (i == l)
                        {
                                if (m[make_pair(l + 1, r)] > 0)
                                {
                                        cout << l << " " << r << " " << i << endl;
                                        break;
                                }
                        }
                        else if (i == r)
                        {
                                if (m[make_pair(l, r - 1)] > 0)
                                {
                                        cout << l << " " << r << " " << i << endl;
                                        break;
                                }
                        }
                        else
                        {
                                if (m[make_pair(l, i - 1)] * m[make_pair(i + 1, r)] > 0)
                                {
                                        cout << l << " " << r << " " << i << endl;
                                        break;
                                }
                        }
                }
        }
}

//................................
// int
// int
// int
// int
