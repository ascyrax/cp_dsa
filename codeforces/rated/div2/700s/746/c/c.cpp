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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
vector<vector<ll>> graph;
vector<bool> visited;
vector<pair<ll, ll>> edges;
ll xorTotal = 0;
ll cnt = 0;
vector<ll> v;
//...............................
ll dfs(ll node)
{
        ll xorSum = 0;
        visited[node] = true;
        xorSum ^= v[node - 1];
        // cout << "node = " << node << endl;

        for (ll neigh : graph[node])
        {
                if (visited[neigh])
                        continue;
                ll temp = 0;
                if (!visited[neigh])
                {
                        temp = dfs(neigh);
                }
                // cout << "node = " << node << " neigh = " << neigh << " temp = " << temp << endl;
                if (temp == xorTotal)
                {
                        cnt++;
                        // edges.pb(make_pair(node, neigh));
                        // xorSum = 0;
                }
                else
                {
                        xorSum ^= temp;
                }
        }
        // cout << "xorSum = " << xorSum << endl;
        return xorSum;
}
//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;
        cnt = 0;
        xorTotal = 0;
        graph = vector<vector<ll>>(n + 1, vector<ll>());
        visited = vector<bool>(n + 1, false);
        v = vector<ll>(n);
        for (ll &i : v)
        {
                cin >> i;
                xorTotal ^= i;
        }
        for (ll i = 0; i < n - 1; i++)
        {
                ll u, v;
                cin >> u >> v;
                graph[u].pb(v);
                graph[v].pb(u);
        }
        if (xorTotal == 0) //removing one edge is enough
        {
                cout << "YES" << endl;
        }
        else // break llo 3 components of xorSum=xorTotal
        {
                // cout << "xorTotal = " << xorTotal << endl;
                dfs(1);
                // cout << "cnt = " << cnt << endl;
                if (cnt >= 2 && k > 2)
                        cout << "YES" << endl;
                else
                        cout << "NO" << endl;
        }
}

//................................
