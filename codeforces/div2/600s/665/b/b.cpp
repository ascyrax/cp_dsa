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
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        ll ans = 0;
        ll temp = min(z1, y2);
        ans += 2 * temp;
        z1 -= temp;
        y2 -= temp;
        // cout << x1 << " " << y1 << " " << z1 << endl;
        // cout << x2 << " " << y2 << " " << z2 << endl;
        // cout << "ans = " << ans << endl;
        z2 = max(0ll, z2 - (x1 + z1));
        // cout << "z2 = " << z2 << endl;
        ans -= 2 * min(y1, z2);
        cout << ans << endl;
        // cout << "--------------------------" << endl;
}

//................................
