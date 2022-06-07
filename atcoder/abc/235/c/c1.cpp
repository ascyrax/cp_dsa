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

//...............................

void suraj()
{
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
                m[v[i]].pb(i);
        }

        for (int i = 0; i < q; i++)
        {
                int x, k;
                cin >> x >> k;
                if (m.count(x) > 0 && m[x].size() >= k)
                {
                        cout << m[x][k - 1] + 1 << endl;
                }
                else
                        cout << -1 << endl;
        }
}

//................................
// int
// int
// int
// int
