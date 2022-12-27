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
        int r, g, b, w;
        cin >> r >> g >> b >> w;

        int even = 0, odd = 0;
        if (r % 2 == 0)
                even++;
        else
                odd++;
        if (g % 2 == 0)
                even++;
        else
                odd++;
        if (b % 2 == 0)
                even++;
        else
                odd++;
        if (w % 2 == 0)
                even++;
        else
                odd++;
        int gteo = 0; // count greater than or equal to 1
        if (r >= 1)
                gteo++;
        if (g >= 1)
                gteo++;
        if (b >= 1)
                gteo++;
        if (even == 4 || (even == 3 && odd == 1))
        {
                cout << "YES" << endl;
        }
        else
        {
                if (odd == 4 && gteo == 3)
                {
                        cout << "YES" << endl;
                }
                else if (odd == 3 && even == 1 && gteo == 3)
                {
                        cout << "YES" << endl;
                }
                else
                        cout << "NO" << endl;
        }
}

//................................
