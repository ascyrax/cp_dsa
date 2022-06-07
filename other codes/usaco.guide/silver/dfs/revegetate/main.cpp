#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                     \
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
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
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
vector<pair<int, string>> neigh[int(1e5) + 1];
vector<bool> visited(int(1e5) + 1);
vector<int> vcolor(int(1e5) + 1);
int flag = 0;

//...............................

void dfs(int node, int color)
{
    visited[node] = true;
    vcolor[node] = color;
    for (auto neighbors : neigh[node])
    {
        if (neighbors.second == "S")
        {
            if (visited[neighbors.first])
            {
                if (vcolor[neighbors.first] != color)
                {
                    // cout << "flag = -1 " << node << " " << neighbors.first << " " << neighbors.second << endl;
                    flag = -1;
                    return;
                }
            }
            else
            {
                vcolor[neighbors.first] = color;
                // cout << "node= " << node << endl;
                // for (int i : vcolor)
                //         cout << i << " ";
                // cout << endl;
                dfs(neighbors.first, color);
            }
        }
        else if (neighbors.second == "D")
        {
            if (visited[neighbors.first])
            {
                if (vcolor[neighbors.first] != ((color == 1) ? 2 : 1))
                {
                    // cout << "flag = -1 " << node << " " << neighbors.first << " " << neighbors.second << endl;
                    flag = -1;
                    return;
                }
            }
            else
            {
                vcolor[neighbors.first] = (color == 1) ? 2 : 1;
                // cout << "node = " << node << endl;
                // for (int i : vcolor)
                //         cout << i << " ";
                // cout << endl;
                dfs(neighbors.first, vcolor[neighbors.first]);
            }
        }
    }
    return;
}

void suraj()
{
    int n, m;
    cin >> n >> m;

    vcolor.resize(n + 1);
    // neigh.resize(n + 1);
    visited.resize(n + 1);

    // vcolor[1] = 1;

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int a, b;
        cin >> a >> b;
        neigh[a].pb(make_pair(b, s));
        neigh[b].pb(make_pair(a, s));
    }
    int ncomponents = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //         for (auto j : neigh[i])
    //                 cout << j.first << " " << j.second << " ";
    //         cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {

        if (visited[i] == false)
        {
            ncomponents++;
            dfs(i, 1);
        }
        if (flag == -1)
        {
            cout << 0 << endl;
            return;
        }
        // for (int i : vcolor)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : visited)
        //         cout << i << " ";
        // cout << endl;
    }
    // cout << "ncomponents = " << ncomponents << endl;
    cout << 1;
    for (int i = 1; i <= ncomponents; i++)
        cout << 0;
    cout << endl;
}

//................................
