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
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        vector<string> vs(n);
        for (string &s : vs)
                cin >> s;

        if (vs[r - 1][c - 1] == 'B')
                cout << 0 << endl;
        else
        {
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (vs[i][j] == 'B')
                                        cnt++;
                        }
                }
                if (cnt == 0)
                        cout << -1 << endl;
                else
                {
                        for (int col = 0; col < m; col++)
                        {
                                if (vs[r - 1][col] == 'B')
                                {
                                        cout << 1 << endl;
                                        return;
                                }
                        }
                        for (int row = 0; row < n; row++)
                        {
                                if (vs[row][c - 1] == 'B')
                                {
                                        cout << 1 << endl;
                                        return;
                                }
                        }
                        cout << 2 << endl;
                }
        }
}

//................................
// int
// int
// int
// int
