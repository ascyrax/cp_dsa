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
int n, m;
vector<vector<int>> dg, backEdge;
vector<bool> visited;
vector<int> in_degree, dist, prevFlight;
int maxDist = 0;
vector<int> topSort;
queue<int> q;
//...............................
void bfs()
{
        while (!q.empty())
        {
                int top = q.front();
                visited[top] = true;

                for (auto neigh : dg[top])
                {
                        if (visited[neigh])
                                continue;
                        in_degree[neigh]--;
                        if (in_degree[neigh] == 0)
                        {
                                q.push(neigh);
                        }
                }
                for (auto prev : backEdge[top])
                {
                        if (dist[top] < dist[prev] + 1)
                        {
                                // maxDist = max(dist[prev] + 1, maxDist);
                                dist[top] = dist[prev] + 1;
                                prevFlight[top] = prev;
                        }
                }
                q.pop();
                topSort.pb(top);
        }
}

//...............................

void suraj()
{
        cin >> n >> m;
        dg = vector<vector<int>>(n + 1, vector<int>());
        backEdge = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);
        in_degree = vector<int>(n + 1, 0);
        dist = vector<int>(n + 1, 0);
        dist[1] = 1;
        prevFlight = vector<int>(n + 1, -1);
        prevFlight[1] = 1;

        // flights
        for (int i = 0; i < n; i++)
        {
                int a, b;
                cin >> a >> b;
                in_degree[b]++;
                dg[a].pb(b);
                backEdge[b].pb(a);
        }
        for (int i = 1; i <= n; i++)
        {
                if (in_degree[i] == 0)
                        q.push(i);
        }
        bfs();
        // cout << "topSort " << endl;
        // for (int i : topSort)
        //         cout << i << " ";
        // cout << endl;

        // if there is not a valid topological sorting
        // if (topSort.size() != n)
        // {
        //         cout << "IMPOSSIBLE" << endl;
        // }
        // else
        // {

        int node = n;
        vector<int> ans;
        ans.pb(node);
        while (node != 1 && node != -1)
        {
                ans.pb(prevFlight[node]);
                node = prevFlight[node];
        }
        if (node == -1)
        {
                cout << "IMPOSSIBLE" << endl;
                return;
        }
        reverse(ans.begin(), ans.end());
        cout << dist[n] << endl;
        for (int i : ans)
                cout << i << " ";
        cout << endl;
        // }
        return;
}

//................................
