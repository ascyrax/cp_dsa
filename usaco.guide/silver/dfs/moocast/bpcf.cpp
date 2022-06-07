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
        freopen("moocast.in", "r", stdin);
        freopen("moocast.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

int n;
vector<vector<int>> graph(201);

vector<int> vx(1), vy(1), vp(1);
vector<bool> visited(201);
int cnt = 1;
//...............................
int dfs(int node)
{
        visited[node] = true;

        for (int adjNode : graph[node])
        {
                if (visited[adjNode])
                        continue;
                else
                {
                        visited[adjNode] = true;
                        // double dist = sqrt((vx[node] - vx[adjNode]) * (vy[node] - vy[adjNode]));
                        // if(dist<=vp[node]){

                        // }
                        // cnt += dfs(adjNode);
                        cnt++;
                        dfs(adjNode);
                }
        }
        return cnt;
}

void suraj()
{
        cin >> n;
        graph.resize(n + 1);
        visited.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
                int x, y, p;
                cin >> x >> y >> p;
                vx.pb(x);
                vy.pb(y);
                vp.pb(p);
        }
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        if (i == j)
                                continue;
                        double dist = sqrt((vx[i] - vx[j]) * (vx[i] - vx[j]) + (vy[i] - vy[j]) * (vy[i] - vy[j]));
                        if (dist <= vp[i])
                        {
                                // cout << i << " " << j << " " << dist << " "
                                //      << "hehe" << endl;
                                graph[i].pb(j);
                        }
                }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
                // dfs(i);
                ans = max(ans, dfs(i));
                cnt = 1;
                visited.clear();
                visited.resize(n + 1);
                // visited.assign(n + 1, false);
        }
        cout << ans << endl;
        // for (int i = 1; i <= n; i++)
        //         cout << vx[i] << " " << vy[i] << " " << vp[i] << endl;
        // cout << "input.." << endl;
        // for (int i = 0; i <= n; i++)
        // {
        //         for (int j : graph[i])
        //                 cout << j << " ";
        //         cout << endl;
        // }
}

//................................
