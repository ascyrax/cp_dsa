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
        ll a, b, c;
        cin >> a >> b >> c;
        ll sa = a * 1, sb = b * 2, sc = c * 3;
        ll mn = min(a, min(b, c));
        if (c % 2 == 0)
        {
                c = c % 2;
        }
        else
        {
                if (mn >= 1)
                {
                        c--;
                        a--;
                        b--;
                }
                c = c % 2;
        }
        if (b % 2 == 0)
        {
                b = b % 2;
        }
        else
        {
                if (a >= 2)
                {
                        a -= 2;
                        b--;
                        b = b % 2;
                }
                else
                {
                        b = b % 1;
                }
        }
        a = a % 2;
        if (b == 0)
                cout << a << endl;
        else
        {
                cout << b * 2 - a * 1 << endl;
        }
}

//................................
