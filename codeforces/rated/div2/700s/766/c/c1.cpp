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
vector<vector<int>> tree;
// vector<vector<int>> grid;
vector<int> visited;
//...............................
void dfs(int node, int val)
{
        // cout << "node = " << node << " , "
        //      << " val = " << val << endl;
        // if (visited[node] != -1)
        //         return;
        visited[node] = val;
        for (auto neigh : tree[node])
        {
                if (visited[neigh] == -1) // ie not visited yet
                {
                        dfs(neigh, val + 1);
                }
        }
        return;
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        tree = vector<vector<int>>(n, vector<int>());
        // grid = vector<vector<int>>(n, vector<int>(n, 0));
        visited = vector<int>(n, -1);

        vector<pair<int, int>> vp;

        for (int i = 0; i < n - 1; i++)
        {
                int u, v;
                cin >> u >> v;
                u--;
                v--;
                vp.pb(make_pair(u, v));
                tree[u]
                    .pb(v);
                tree[v].pb(u);
        }

        int leaf = -1;

        for (int i = 0; i < n; i++)
        {
                if (tree[i].size() > 2)
                {
                        cout << -1 << endl;
                        return;
                }
                else if (tree[i].size() == 1)
                {
                        leaf = i;
                }
        }

        // cout << "leaf = " << leaf << endl;

        dfs(leaf, 0);

        // for (int i : visited)
        //         cout << i << " ";
        // cout << endl;

        // even->odd =2 & odd->even =3
        for (int i = 0; i < n - 1; i++)
        {
                int u = vp[i].first;
                int v = vp[i].second;
                if (visited[v] < visited[u])
                {
                        int temp = u;
                        u = v;
                        v = temp;
                }
                // cout << "u = " << u << " , v = " << v << endl;
                // cout << "visited[u] = " << visited[u] << " , visited[v] = " << visited[v] << endl;
                if (visited[u] % 2 == 0 && visited[v] % 2 == 1)
                        cout << 2 << " ";
                else
                        cout << 3 << " ";
        }
        cout << endl;
}

//................................
// int
// int
// int
// int
