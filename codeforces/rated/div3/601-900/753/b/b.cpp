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
        ll x, n;
        cin >> x >> n;
        if (n == 0)
        {
                cout << x << endl;
                return;
        }
        if (x % 2 == 0)
        {
                x--;
                // now odd => go right +2 +3 -4 -5
                ll q = (n - 1) / 4;
                ll rem = (n - 1) % 4;
                x = x - 4 * q;
                ll temp = 4 * q + 1;
                if (rem == 0)
                {
                        x = x;
                }
                else if (rem == 1)
                {
                        x += (temp + 1);
                }
                else if (rem == 2)
                {
                        x += (temp + 1 + temp + 2);
                }
                else if (rem == 3)
                {
                        x += (temp + 1 + temp + 2);
                        x -= temp + 3;
                }
        }
        else
        {
                x++;
                // now even => go left -2 -3 +4 +5
                ll q = (n - 1) / 4;
                ll rem = (n - 1) % 4;
                x = x + 4 * q;
                ll temp = 4 * q + 1;
                if (rem == 0)
                {
                        x = x;
                }
                else if (rem == 1)
                {
                        x -= (temp + 1);
                }
                else if (rem == 2)
                {
                        x -= (temp + 1 + temp + 2);
                }
                else if (rem == 3)
                {
                        x -= (temp + 1 + temp + 2);
                        x += temp + 3;
                }
        }
        cout << x << endl;
}

//................................
