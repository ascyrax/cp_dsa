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
        int n, k;
        cin >> n >> k;

        int mid = n / 2;

        int cnt = 0;
        int ind = 2;

        // do 1 step;
        cnt++;
        ind = mid + (ind / 2);

        while (ind != 2)
        {
                if (ind % 2 == 0)
                        ind = mid + (ind / 2);
                else
                        ind = (ind + 1) / 2;
                cnt++;
        }
        k = k % cnt;
        vector<int> f;
        f.pb(0);
        for (int i = 1; i <= n; i++)
                f.pb(i);
        map<int, int> g;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 0; j < k; j++)
                {
                        if (f[i] % 2 == 0)
                        {
                                f[i] = mid + (f[i] / 2);
                        }
                        else
                        {
                                f[i] = (f[i] + 1) / 2;
                        }
                }
                g[f[i]] = i;
        }
        for (auto el : g)
                cout << el.second << " ";
        cout << endl;
}

//................................
// int
// int
// int
// int
