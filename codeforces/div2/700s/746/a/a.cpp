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
        ioss
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
        ll n, h;
        cin >> n >> h;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        sort(v.rbegin(), v.rend());
        if (h <= v[0])
        {
                cout << 1 << endl;
        }
        else if (h <= v[0] + v[1])
        {
                cout << 2 << endl;
        }
        else
        {
                ll ab = v[0] + v[1];
                ll rem = h % ab;
                ll q = h / ab;
                if (rem == 0)
                {
                        cout << 2 * q << endl;
                }
                else
                {
                        if (rem <= v[0])
                        {
                                cout << 2 * q + 1 << endl;
                        }
                        else
                                cout << 2 * q + 2 << endl;
                }
        }
}

//................................
