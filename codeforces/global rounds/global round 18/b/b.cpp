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

vector<int> v(20, 0);
vector<vector<int>> save;
int main()
{
        ioss
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        save.pb(v);
        for (int i = 1; i <= 2e5; i++)
        {
                int val = i;
                int a = 0;
                while (val)
                {
                        if (val % 2 == 1)
                                v[a]++;
                        val /= 2;
                        a++;
                }
                save.pb(v);
        }
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
void suraj()
{
        int l, r;
        cin >> l >> r;

        // for (int i : save[r])
        //         cout << i << " ";
        // cout << endl;
        // for (int i : save[l])
        //         cout << i << " ";
        // cout << endl;

        vector<int> temp(20, 0);
        for (int i = 0; i < 20; i++)
        {
                temp[i] = save[(r)][i] - save[(l - 1)][i];
        }
        // for (int i : temp)
        //         cout << i << " ";
        // cout << endl;
        int mx = 0;
        for (int i = 0; i < 20; i++)
                mx = max(mx, temp[i]);
        cout << (r - l + 1) - mx << endl;
}
//................................

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................
