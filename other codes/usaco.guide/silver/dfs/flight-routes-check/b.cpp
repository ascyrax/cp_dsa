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
int nCities, mRoads;
vector<vector<int>> dir_graph, dir_graph_rev;
vector<bool> visited, visited_rev;
//...............................
void dfs(int node)
{
        if (visited[node])
                return;
        else
                visited[node] = true;
        for (int neigh : dir_graph[node])
        {
                if (!visited[neigh])
                {
                        dfs(neigh);
                }
        }
        return;
}
void dfs_rev(int node)
{
        if (visited_rev[node])
                return;
        else
                visited_rev[node] = true;
        for (int neigh : dir_graph_rev[node])
        {
                if (!visited_rev[neigh])
                {
                        dfs_rev(neigh);
                }
        }
        return;
}
//...............................

void suraj()
{
        cin >> nCities >> mRoads;
        dir_graph = vector<vector<int>>(nCities + 1, vector<int>());
        dir_graph_rev = vector<vector<int>>(nCities + 1, vector<int>());
        visited = vector<bool>(nCities + 1, false);
        visited_rev = vector<bool>(nCities + 1, false);
        cout << sizeof(visited) << " " << sizeof(visited_rev) << " " << sizeof(nCities) << endl;
        for (int i = 0; i < mRoads; i++)
        {
                int a, b;
                cin >> a >> b;
                dir_graph[a].pb(b);
                dir_graph_rev[b].pb(a);
        }
        //if one node can visit all other nodes and can also be visited by all other nodes
        //then => all nodes can visit and be visited by each other
        dfs(1);
        for (int i = 1; i <= nCities; i++)
        {
                if (!visited[i])
                {
                        cout << "NO" << endl;
                        cout << 1 << " " << i << endl;
                        return;
                }
        }
        //now we will check whether we can visit city 1 from all other nodes
        //for this we can reverse all the road directions and check if we can
        //visit all other nodes from node 1(again)
        dfs_rev(1);
        for (int i = 1; i <= nCities; i++)
        {
                if (!visited_rev[i])
                {
                        cout << "NO" << endl;
                        cout << i << " " << 1 << endl;
                        return;
                }
        }
        cout << "YES" << endl;
}

//................................
