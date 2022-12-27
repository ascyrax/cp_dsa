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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
ll n, m;
vector<string> grid;
ll q;
vector<vector<bool>> visited;
set<ll> badCol;
//...............................
void dfs(ll x, ll y)
{
        if (x > n || y > m)
                return;
        if (visited[x][y])
                return;
        if (grid[x][y] == 'X')
                return;
        visited[x][y] = true;
        dfs(x + 1, y);
        dfs(x, y + 1);
        return;
}
//...............................

void suraj()
{ 
        cin >> n >> m;
        grid = vector<string>(n + 1, "");
        visited = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
        for (ll i = 1; i <= n; i++)
        {
                string s;
                cin >> s;
                grid[i] = s;
        }
        dfs(1, 1);

        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= m; j++)
                {
                        if (grid[i][j] == '.' && visited[i][j] == false)
                        {
                                badCol.insert(j);
                        }
                }
        }
        cin >> q;
        for (ll i = 0; i < q; i++)
        {
                ll ca, cb;
                cin >> ca >> cb;
                auto left = badCol.lower_bound(ca);
                auto right = badCol.upper_bound(cb);
                if (left == badCol.end() || (left == right))
                {
                        cout << "YES" << endl;
                }
                else
                        cout << "NO" << endl;
        }
}

//................................
