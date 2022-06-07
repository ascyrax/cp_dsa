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
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;
vector<vector<int>> graph(1e5 + 1);
vector<bool> visited(1e5 + 1);
int cnt = 0;
//...............................
void dfs(int node)
{
        visited[node] = true;
        cnt++;
        for (int neigh : graph[node])
        {
                if (visited[neigh])
                        continue;
                else
                {
                        dfs(neigh);
                }
        }
        return;
}

void suraj()
{
        int n, m;
        cin >> n >> m;
        graph.resize(n + 1);
        visited.resize(n + 1);
        for (int i = 1; i <= m; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
        }
        // if graph is conneceted and a cycle exists ----------yes
        dfs(1);
        if (cnt == n)
                cout << "YES" << endl;
        //else no
        else
        {
                cout << "NO" << endl;
                cout << "1 ";
                for (int i = 1; i <= n; i++)
                {
                        if (visited[i] == false)
                                cout << i << endl;
                        break;
                }
        }
}

//................................
