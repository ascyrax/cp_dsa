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
        ll t;
        cin >> t;
        for (ll i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const ll INF = ll(1e9);
const ll NEG_INF = ll(-1e9);
// const ll INF = 2147483647;
// const ll NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        ll n, m, k;
        cin >> n >> m >> k;
        ll mn = min(n, m);
        ll mx = max(n, m);
        ll diff = mx - mn;
        ll kCopy = k;
        if (k < max(n, m))
        {
                cout << -1 << endl;
        }
        else
        {

                if (diff == 0)
                {
                        ll left = k - mn;
                        if (left % 2 == 0)
                                cout << k << endl;
                        else
                        {
                                if (left >= 3)
                                {
                                        cout << k - 2 << endl;
                                }
                                else if (left == 1)
                                {
                                        cout << mn - 1 << endl;
                                }
                        }
                }
                else
                {
                        if (diff % 2 == 0)
                        {
                                k = k - mn;
                                if (k % 2 == 0)
                                {
                                        cout << kCopy << endl;
                                }
                                else
                                {
                                        if (k >= diff + 3)
                                        {
                                                cout << kCopy - 2 << endl;
                                        }
                                        else if (k == diff + 1)
                                        {
                                                // cout << mn + diff - 1 << endl;
                                                // diff -1 or k-2
                                                cout << kCopy - 2 << endl;
                                        }
                                }
                        }
                        else
                        {
                                if (k % 2 == 0)
                                {
                                        cout << kCopy - 1 << endl;
                                }
                                else
                                {
                                        cout << kCopy - 1 << endl;
                                }
                        }
                }
        }
}

//................................
