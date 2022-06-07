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
        int n;
        cin >> n;

        int nMoves = 0;

        vector<int> r(3), g(3), b(3);

        for (int &i : r)
                cin >> i;
        for (int &i : g)
                cin >> i;
        for (int &i : b)
                cin >> i;

        if (g[0] < r[1])
        {
                nMoves += g[0];
                r[1] -= g[0];
                g[0] = 0;
        }
        else if (r[1] <= g[0])
        {
                nMoves += r[1];
                r[1] = 0;
                g[0] -= r[1];
        }

        if (b[0] < r[2])
        {
                nMoves += b[0];
                r[2] -= b[0];
                b[0] = 0;
        }
        else if (r[2] <= b[0])
        {
                nMoves += r[2];
                r[2] = 0;
                b[0] -= r[2];
        }

        if (b[1] < g[2])
        {
                nMoves += b[1];
                g[2] -= b[1];
                b[1] = 0;
        }
        else if (g[2] <= b[1])
        {
                nMoves += g[2];
                g[2] = 0;
                b[1] -= g[2];
        }

        if (r[1] != 0) // => g[0]=0 & g[2]!=0 => b[1]=0 & b[0]!=0
        {              // r[1] = g[2] = b[0]
                nMoves += r[1] * 2;
        }
        else if (r[2] != 0) // => b[0]=0 & b[1]!=0 => g[2]=0 & g[0]!=0
        {                   // r[2]=g[0]=b[1]
                nMoves += r[2] * 2;
        }

        cout << nMoves << endl;
}

//................................
// int
// int
// int
// int
