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
vector<vector<int>> udg;
queue<pair<int, int>> q; // node and distance index
vector<bool> visited;
vector<int> dist;
int girth = 1e9;
int d = 0;
int flag = -1;
vector<vector<bool>> grid;
vector<int> parent;
//...............................
void bfs()
{
        q.push(make_pair(1, d));
        parent[1] = 1;
        while (!q.empty())
        {
                // cout<<"begin "<<endl;

                auto front = q.front();
                dist[front.first] = front.second;
                q.pop();
                visited[front.first] = true;
                for (auto neigh : udg[front.first])
                {
                        // if (grid[front.first][neigh] == false)
                        // {
                        //         continue;
                        // }
                        if (neigh == parent[front.first])
                                continue;
                        parent[neigh] = front.first;
                        if (visited[neigh])
                        {
                                cout << "neigh = " << neigh << " " << dist[neigh] << endl;
                                girth = front.second + 1 - dist[neigh];
                                cout << "girth = " << girth << endl;
                                flag = 1;
                                break;
                        }
                        else
                        {
                                // grid[front.first][neigh] = false;
                                // grid[neigh][front.first] = false;
                                q.push(make_pair(neigh, front.second + 1));
                        }
                }
                if (flag == 1)
                        break;
        }
        return;
}
//...............................

void suraj()
{
        cin >> n >> m;
        udg = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);
        dist = vector<int>(n + 1, false);
        parent = vector<int>(n + 1, -1);
        // grid = vector<vector<bool>>(n + 1, vector<bool>(n + 1, true));
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                udg[a].pb(b);
                udg[b].pb(a);
        }
        bfs();
        cout << girth << endl;
}

//................................
