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
        freopen("lasers.in", "r", stdin);
        freopen("lasers.out", "w", stdout);
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
int n, xl, yl, xb, yb;
map<pair<int, int>, int> visited;
map<int, vector<pair<int, int>>> mx, my;
queue<pair<int, int>> q;
// int flag = -1;
//...............................
void dfs(int nodeX, int nodeY, int dist)
{

        if (visited[make_pair(nodeX, nodeY)] != 0 && dist > visited[make_pair(nodeX, nodeY)])
                return;
        // cout << "nodeX: " << nodeX << " nodeY: " << nodeY << endl;
        // if (nodeX == xb && nodeY == yb)
        // {
        //         visited[make_pair(nodeX, nodeY)] = min(visited[make_pair(nodeX, nodeY)], dist);
        // }
        if (visited[make_pair(nodeX, nodeY)] == 0)
                visited[make_pair(nodeX, nodeY)] = dist;
        else
                visited[make_pair(nodeX, nodeY)] = min(dist, visited[make_pair(nodeX, nodeY)]);
        // cout << "nodeX: " << nodeX << " nodeY: " << nodeY << endl;
        // for (auto neigh : mx[nodeX])
        // {
        //         cout << "neigh mx = " << neigh.first << " " << neigh.second << endl;
        // }
        // for (auto neigh : my[nodeY])
        // {
        //         cout << "neigh my = " << neigh.first << " " << neigh.second << endl;
        // }
        for (auto neigh : mx[nodeX])
        {
                dfs(neigh.first, neigh.second, dist + 1);
        }

        for (auto neigh : my[nodeY])
        {
                dfs(neigh.first, neigh.second, dist + 1);
        }
        return;
}
void bfs()
{
        q.push(make_pair(xl, yl));
        int dist = 0;
        while (!q.empty())
        {
                auto top = q.front();
                q.pop();
                dist++;
                for (auto neigh : mx[top.first])
                {
                        if (visited[make_pair(neigh.first, neigh.second)] != 0)
                        {
                                if (visited[make_pair(neigh.first, neigh.second)])
                        }
                        else
                        {
                                q.push(make_pair(neigh.first, neigh.second));
                        }
                }
        }
}
//...............................

void suraj()
{
        cin >> n >> xl >> yl >> xb >> yb;
        mx[xl].pb(make_pair(xl, yl));
        my[yl].pb(make_pair(xl, yl));
        mx[xb].pb(make_pair(xb, yb));
        my[yb].pb(make_pair(xb, yb));
        for (int i = 0; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                mx[x].pb(make_pair(x, y));
                my[y].pb(make_pair(x, y));
        }
        // for (auto el : mx)
        // {
        //         cout << el.first << endl;
        //         for (auto i : el.second)
        //                 cout << i.first << " " << i.second << "      ";
        //         cout << endl;
        // }
        // for (auto el : my)
        // {
        //         cout << el.first << endl;
        //         for (auto i : el.second)
        //                 cout << i.first << " " << i.second << "      ";
        //         cout << endl;
        // }
        // dfs(xl, yl, 0);
        bfs();
        // for (auto el : visited)
        // {
        //         cout << el.first.first << " " << el.first.second << "           " << el.second << endl;
        // }
        if (visited[make_pair(xb, yb)] > 0)
        {
                cout << visited[make_pair(xb, yb)] - 1 << endl;
        }
        else
                cout << -1 << endl;
}

//................................
