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
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}
int ans = 0;
vector<pair<int, int>> v;
//...............................
void toh(int n, int src, int dest, int aux)
{
        if (n == 1)
        {
                ans++;
                v.pb(make_pair(src, dest));
                return;
        }
        toh(n - 1, src, aux, dest);
        toh(1, src, dest, aux);
        toh(n - 1, aux, dest, src);
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        toh(n, 1, 3, 2); // move n disks from 1 -> 3 using 2
        cout << ans << endl;
        for (auto el : v)
                cout << el.first << " " << el.second << endl;
}

//................................
// int
// int
// int
// int
// 7
// 1 3
// 1 2
// 3 2
// 1 3
// 2 1
// 2 3
// 1 3

// 7
// 1 2
// 1 3
// 2 3
// 1 3
// 1 2
// 1 3
// 2 3