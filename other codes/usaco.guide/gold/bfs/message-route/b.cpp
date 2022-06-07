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
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int distMin = -1;
vector<int> parent;
//...............................
void bfs(int node)
{
        parent[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, 1});

        while (!q.empty())
        {
                auto currentNode = q.front();
                q.pop();
                if (visited[currentNode.first])
                        continue;
                visited[currentNode.first] = true;
                for (int neigh : graph[currentNode.first])
                {
                        if (neigh == n)
                        {
                                parent[neigh] = currentNode.first;
                                distMin = currentNode.second + 1;
                                return;
                        }
                        if (!visited[neigh])
                        {
                                if (parent[neigh] == -1)
                                        parent[neigh] = currentNode.first;
                                q.push({neigh, currentNode.second + 1});
                        }
                }
        }
        return;
}
//...............................

void suraj()
{
        cin >> n >> m;
        graph = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);
        parent = vector<int>(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
                graph[b].pb(a);
        }
        bfs(1);
        // for (int i : parent)
        //         cout << i << " ";
        // cout << endl;
        if (distMin != -1)
        {
                cout << distMin << endl;
                int curr = n;
                vector<int> ans;
                ans.pb(n);
                while (parent[curr] != 1)
                {
                        // cout << parent[curr] << endl;
                        ans.pb(parent[curr]);
                        curr = parent[curr];
                }
                ans.pb(1);
                reverse(ans.begin(), ans.end());
                for (int i : ans)
                        cout << i << " ";
                cout << endl;
        }
        else
                cout << "IMPOSSIBLE" << endl;
}

//................................
