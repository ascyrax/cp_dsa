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
        // ioss
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
vector<vector<pair<int, int>>> tree;
vector<bool> visited;
// vector<bool> isLeaf;
vector<int> leafCnt;
//...............................
void dfsLeafCnt(int node, int parent = -1)
{
        // cout << "func called" << endl;
        // if (node == 1)
        // {
        //         if (tree[node].size() == 1)
        //         {
        //                 for (auto child : tree[node])
        //                 {
        //                         if (child.first == node)
        //                                 continue;
        //                         if (!visited[child.first])
        //                         {
        //                                 dfsLeafCnt(child.first, node);
        //                         }
        //                         leafCnt[node] += leafCnt[child.first];
        //                 }
        //         }
        // }
        // else
        // {
        if (tree[node].size() >= 2 || (node == 1))
        {
                for (auto child : tree[node])
                {
                        if (child.first == parent)
                                continue;
                        if (!visited[child.first])
                        {
                                visited[child.first] = true;
                                dfsLeafCnt(child.first, node);
                        }
                        leafCnt[node] += leafCnt[child.first];
                }
        }
        else if (tree[node].size() == 1)
        {
                // isLeaf[node] = true;
                leafCnt[node] = 1;
                visited[node] = true;
        }

        // }
        return;
}
//...............................

void suraj()
{
        int n, s;
        cin >> n >> s;

        tree = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
        visited = vector<bool>(n + 1, false);
        leafCnt = vector<int>(n + 1, 1);

        int nMoves = 0;

        for (int i = 0; i < n - 1; i++)
        {
                // cout << "i = " << i << endl;
                int u, v, w;
                cin >> u >> v >> w;
                while (w > s)
                {
                        nMoves++;
                        w /= 2;
                }
                tree[u].pb({v, w});
                tree[v].pb({u, w});
        }
        // cout << "dfs" << endl;
        // dfs for leafCnt
        visited[1] = true;
        dfsLeafCnt(1, -1);
        for (int i : leafCnt)
                cout << i << " ";
        cout << endl;
        // dfsLeafCnt(0); will also do
}

//................................
