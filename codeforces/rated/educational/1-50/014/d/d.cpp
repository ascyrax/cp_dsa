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
        //cout << setprecision(15) << fixed;
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
vector<int> visited;
vector<pair<int, pair<int, int>>> bucket; // (node,color) color=> the group to which this node belongs to
vector<int> value;
//...............................
void dfs(int node, int color)
{
        visited[node] = color;
        bucket.pb(make_pair(value[node], make_pair(node, color)));
        for (int neigh : graph[node])
        {
                // cout << "neigh = " << neigh << endl;
                if (!visited[neigh])
                {
                        // cout << "neigh not visited = " << neigh << endl;
                        dfs(neigh, color);
                }
        }
        return;
}
//...............................

void suraj()
{

        cin >> n >> m;
        graph = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<int>(n + 1, 0);
        value = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
                cin >> value[i];
        }
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
                graph[b].pb(a);
        }
        int color = 1;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++)
        {
                if (!visited[i])
                {
                        // cout << "i = " << i << endl;
                        dfs(i, color++);
                        sort(bucket.rbegin(), bucket.rend());
                        // cout << "bucket after sort" << endl;
                        // for (auto el : bucket)
                        // {
                        //         cout << el.first << " ";
                        // }
                        // cout << endl;
                        vector<int> bucketIndex;
                        for (auto el : bucket)
                                bucketIndex.push_back(el.second.first);
                        sort(bucketIndex.begin(), bucketIndex.end());
                        // for (auto el : bucket)
                        // {
                        //         cout << el.second.first << " ";
                        // }
                        // cout << endl;
                        // for (auto el : bucket)
                        // {
                        //         cout << el.second.second << " ";
                        // }
                        // cout << endl;
                        for (int j = 0; j < (int)bucket.size(); j++)
                        {
                                int nodeIndex = bucketIndex[j];
                                ans[nodeIndex] = bucket[j].first;
                        }
                        // for (int i : ans)
                        //         cout << i << " ";
                        // cout << endl;
                }

                bucket.clear();
        }
        for (int i = 1; i <= n; i++)
        {
                cout << ans[i] << " ";
        }
        cout << endl;
}

//................................
