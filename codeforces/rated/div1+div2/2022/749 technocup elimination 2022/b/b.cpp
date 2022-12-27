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
int n, m;
vector<vector<int>> dg, ug;
vector<int> in_degree;
queue<int> q;
vector<int> topSort;
vector<int> visited;
vector<int> parent;
//...............................
void bfs()
{
        while (!q.empty())
        {
                int top = q.front();
                q.pop();
                visited[top] = true;
                for (auto neigh : dg[top])
                {
                        if (visited[neigh])
                                continue;
                        in_degree[neigh]--;
                        if (in_degree[neigh] == 0)
                                q.push(neigh);
                }
                topSort.pb(top);
        }
}
void dfs(int node, int color)
{
        // if (visited[node] != 0)
        //         return;
        visited[node] = color;
        // parent[node] = color;
        for (auto neigh : ug[node])
        {
                if (visited[neigh] != 0)
                        continue;
                parent[neigh] = node;
                dfs(neigh, color);
        }
        return;
}
//...............................

void suraj()
{
        cin >> n >> m;
        dg = vector<vector<int>>(n + 1, vector<int>());
        ug = vector<vector<int>>(n + 1, vector<int>());
        in_degree = vector<int>(n + 1, 0);
        visited = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
                int a, b, c;
                cin >> a >> b >> c;
                // dg[a].pb(b);
                // dg[c].pb(b);
                // in_degree[b] += 2;
                ug[a].pb(c);
                ug[c].pb(a);
        }

        // for (int i = 1; i <= n; i++)
        // {
        //         if (in_degree[i] == 0)
        //                 q.push(i);
        // }

        // bfs();
        // cout << "topSort" << endl;
        // for (int i : topSort)
        //         cout << i << " ";
        // cout << endl;
        // for (int i = 0; i < (int)topSort.size() - 1; i++)
        // {
        //         cout << topSort[i] << " " << topSort[i + 1] << endl;
        // }
        // topSort.clear();
        // in_degree.clear();
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
                if (ug[i].size() == 0)
                {
                        ans.pb(i);
                }
                for (int j : ug[i])
                {
                        cout << i << " " << j << endl;
                }
        }
        set<pair<int, int>> sans;
        for (int i = 0; i < (int)ans.size() - 1; i++)
        {
                ug[ans[i]].pb(ans[i + 1]);
                ug[ans[i + 1]].pb(ans[i]);
                int l = min(ans[i], ans[i + 1]);
                int r = max(ans[i], ans[i + 1]);
                sans.insert(make_pair(l, r));
                // cout << ans[i] << " " << ans[i + 1] << endl;
        }
        int color = 1;
        for (int i = 1; i <= n; i++)
        {
                if (visited[i] == 0)
                {
                        parent[i] = i;
                        dfs(i, color);
                        color++;
                }
        }
        set<int> parents;
        vector<int> temp;
        map<int, int> xxx;
        for (int i = 1; i <= n; i++)
        {
                parents.insert(parent[i]);
                xxx[parent[i]] = i;
                // auto it = lower_bound(temp.begin(), temp.end(), parent[i]);
                // if (it != temp.end())
                // {
                //         if (*it == parent[i])
                //         {
                //                 continue;
                //         }
                // }
                // else
                // {
                //         temp.pb[parent[i]];
                // }
        }
        vector<int> vp;
        for (int parent : parents)
        {
                vp.pb(parent);
        }
        for (auto el : sans)
                cout << el.first << " " << el.second << endl;
        for (int i = 0; i < (int)vp.size() - 1; i++)
        {
                cout << xxx[vp[i]] << " " << xxx[vp[i + 1]] << endl;
        }
}

//................................
