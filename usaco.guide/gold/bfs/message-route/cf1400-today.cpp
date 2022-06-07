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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
                cout
            << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;
int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int ans = -1;
//...............................

void bfs(int startNode)
{
        visited[startNode] = true;
        queue<pair<int, int>> q;
        q.push({startNode, 0});

        while (!q.empty())
        {
                pair<int, int> currentNode = q.front();
                for (int neigh : graph[currentNode.first])
                {
                        if (neigh == n)
                        {
                                ans = currentNode.second + 1;
                        }
                        if (!visited[neigh])
                        {
                                visited[neigh] = true;
                                q.push({neigh, currentNode.second + 1});
                        }
                }
                q.pop();
        }
}

void suraj()
{
        cin >> n >> m;

        graph = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
                graph[b].pb(a);
        }
        bfs(1);
        if (ans == -1)
                cout << "IMPOSSIBLE" << endl;
        else
        {
                cout << ans + 1 << endl;
        }
}

//................................
