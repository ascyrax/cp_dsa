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
        //ioss
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................
int n, m;
vector<vector<int>> dg;
vector<int> visited;
int visitCounter = 0;
int reqNode = -1;
vector<int> parent;
//...............................
void dfs(int node)
{
        cout << "dfs" << visitCounter << endl;
        visited[node] = visitCounter;
        for (int neigh : dg[node])
        {
                if (visited[neigh] == 0)
                {
                        cout << "if"
                             << " " << neigh << endl;
                        dfs(neigh);
                }
                else if (visited[neigh] == visitCounter)
                {
                        cout << "else if " << neigh << endl;
                        reqNode = neigh;
                        return;
                }
                if (reqNode != -1)
                        return;
        }

        return;
}

void bfs()
{
        queue<pair<int, int>> q;
        vector<bool> bfsVisited(n + 1, false);
        pair<int, int> currentNode;

        q.push(make_pair(reqNode, 1));

        while (!q.empty())
        {
                currentNode = q.front();
                int depth = currentNode.second;
                q.pop();

                bfsVisited[currentNode.first] = true;

                for (int neigh : dg[currentNode.first])
                {
                        if (neigh == reqNode)
                        {
                                parent[neigh] = currentNode.first;
                                // cout << depth + 1 << endl;
                                return;
                        }
                        else if (!bfsVisited[neigh])
                        {
                                parent[neigh] = currentNode.first;
                                q.push(make_pair(neigh, depth + 1));
                        }
                }
        }
        return;
}
//...............................

void suraj()
{

        cin >> n >> m;
        dg = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                dg[a].pb(b);
        }
        for (auto i : dg)
        {
                for (int a : i)
                        cout << a << " ";
                cout << endl;
        }
        for (int i = 1; i <= n; i++)
        {
                if (visited[i] == 0)
                {
                        ++visitCounter;
                        dfs(i);
                }
                if (reqNode != -1)
                {
                        break;
                }
        }
        cout << reqNode << endl;
        if (reqNode == -1)
                cout << "IMPOSSIBLE" << endl;
        else
        {
                bfs();
                vector<int> ans;
                int temp = reqNode;
                ans.pb(temp);
                while (parent[temp] != reqNode)
                {
                        ans.pb(parent[temp]);
                        temp = parent[temp];
                }
                ans.pb(parent[temp]);
                reverse(ans.begin(), ans.end());
                cout << ans.size() << endl;
                for (int i : ans)
                        cout << i << " ";
                cout << endl;
        }
}

//................................
