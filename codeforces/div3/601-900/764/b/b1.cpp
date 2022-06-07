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
        int a, b, c;
        cin >> a >> b >> c;
        int d = 0;
        int m = 0;
        // m>0

        // change a
        d = c - b;
        m = (2 * b - c) / a; // such that m*a=a(new)
        if ((2 * b - c) % a == 0 && (m > 0))
        {
                cout << "YES" << endl;
                return;
        }
        // b
        d = (c - a) / 2;
        m = (c + a) / (2 * b);
        if ((c - a) % 2 == 0 && ((c + a) % (2 * b) == 0) && (c + a) / (2 * b) > 0)
        {
                cout << "YES" << endl;
                return;
        }
        // c
        d = b - a;
        m = (2 * b - a) / c;
        if ((2 * b - a) % c == 0 && ((2 * b - a) > 0))
        {
                cout << "YES" << endl;
                return;
        }
        cout << "NO" << endl;
}

//................................
// int
// int
// int
// int
