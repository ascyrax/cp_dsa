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
vector<int> visited;
vector<vector<int>> graph;
//...............................
void dfs(int node, int group)
{
        visited[node] = group;
        for (int neigh : graph[node])
        {
                if (visited[neigh] == -1)
                {
                        dfs(neigh, group);
                }
        }
        return;
}
//...............................

void suraj()
{
        int nCities, nRoads;
        cin >> nCities >> nRoads;
        visited = vector<int>(nCities + 1, -1);
        graph = vector<vector<int>>(nCities + 1, vector<int>());

        for (int i = 0; i < nRoads; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
                graph[b].pb(a);
        }
        int group = 0;
        for (int i = 1; i <= nCities; i++)
        {
                if (visited[i] == -1)
                        dfs(i, ++group);
        }
        cout << group - 1 << endl;
        int temp = 1;
        vector<int> ans;
        for (int i = 1; i <= nCities; i++)
        {
                if (visited[i] == temp)
                {
                        ans.pb(i);
                        temp++;
                }
        }
        for (int i = 1; i < (int)ans.size(); i++)
                cout << ans[i] << " " << ans[i - 1] << endl;
}

//................................
