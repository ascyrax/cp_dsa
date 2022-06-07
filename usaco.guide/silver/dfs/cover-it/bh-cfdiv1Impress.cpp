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
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax
int n, m;
const ll mod = 1e9 + 7;
vector<vector<int>> graph;
vector<int> vcolor;
vector<bool> visited;
// vcolor[0]=1;  why is this error here
vector<int> d;
//...............................

void dfs(int node, int color)
{
        visited[node] = true;
        vcolor[node] = color;
        for (int neigh : graph[node])
        {
                if (visited[neigh] != true)
                {
                        // cout << "dfs " << neigh << " " << color + 1 << endl;
                        dfs(neigh, color + 1);
                }
        }
        return;
}
void bfs(int node)
{
        d = vector<int>(n, int(1e9));
        d[node] = 0;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
                int v = q.front();
                q.pop();

                for (auto to : graph[v])
                {
                        if (d[to] == int(1e9))
                        {
                                d[to] = d[v] + 1;
                                q.push(to);
                        }
                }
        }
}
void suraj()
{

        cin >> n >> m;
        graph = vector<vector<int>>(n + 1);
        vcolor = vector<int>(n + 1);
        visited = vector<bool>(n + 1);
        // vcolor[1] = 1;
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                // if (graph[a].size() < 2)
                graph[a].pb(b);
                // if (graph[b].size() < 2)
                graph[b].pb(a);
        }
        vector<int> even, odd;

        // bfs(1);
        // for (int i = 0; i < n; ++i)
        // {
        //         if (d[i] & 1)
        //                 odd.push_back(i);
        //         else
        //                 even.push_back(i);
        // }

        // if (even.size() < odd.size())
        // {
        //         cout << even.size() << endl;
        //         for (auto v : even)
        //                 cout << v + 1 << " ";
        // }
        // else
        // {
        //         cout << odd.size() << endl;
        //         for (auto v : odd)
        //                 cout << v + 1 << " ";
        // }
        // cout << endl;

        // // dfs waala implementation jo ki wrong ho ha rha hai
        dfs(1, 1);

        for (int i = 1; i <= n; i++)
        {
                // cout << vcolor[i] << " ";
                if (vcolor[i] % 2 == 0)
                        even.pb(i);
                else
                        odd.pb(i);
        }
        if (even.size() < odd.size())
        {
                cout << even.size() << endl;
                for (auto v : even)
                        cout << v << " ";
        }
        else
        {
                cout << odd.size() << endl;
                for (auto v : odd)
                        cout << v << " ";
        }
        cout << endl;
}

//................................
// #include <bits/stdc++.h>

// using namespace std;

// const int INF = 1e9;

// int n, m;
// vector<int> d;
// vector<vector<int>> g;

// void bfs(int s)
// {
//         d = vector<int>(n, INF);
//         d[s] = 0;

//         queue<int> q;
//         q.push(s);

//         while (!q.empty())
//         {
//                 int v = q.front();
//                 q.pop();

//                 for (auto to : g[v])
//                 {
//                         if (d[to] == INF)
//                         {
//                                 d[to] = d[v] + 1;
//                                 q.push(to);
//                         }
//                 }
//         }
// }

// int main()
// {
// #ifdef _DEBUG
//         freopen("input.txt", "r", stdin);
// //	freopen("output.txt", "w", stdout);
// #endif

//         int t;
//         cin >> t;

//         for (int tc = 0; tc < t; ++tc)
//         {
//                 cin >> n >> m;
//                 g = vector<vector<int>>(n);
//                 for (int i = 0; i < m; ++i)
//                 {
//                         int x, y;
//                         cin >> x >> y;
//                         --x, --y;
//                         g[x].push_back(y);
//                         g[y].push_back(x);
//                 }

//                 bfs(0);
//                 vector<int> even, odd;
//                 for (int i = 0; i < n; ++i)
//                 {
//                         if (d[i] & 1)
//                                 odd.push_back(i);
//                         else
//                                 even.push_back(i);
//                 }

//                 if (even.size() < odd.size())
//                 {
//                         cout << even.size() << endl;
//                         for (auto v : even)
//                                 cout << v + 1 << " ";
//                 }
//                 else
//                 {
//                         cout << odd.size() << endl;
//                         for (auto v : odd)
//                                 cout << v + 1 << " ";
//                 }
//                 cout << endl;
//         }

//         return 0;
// }