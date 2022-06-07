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

        // ioss

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        // cin>>t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
vector<vector<int>> dg;
int n, m;
vector<int> ans;
vector<int> visited;
int dfsno = 0;
int flag = 0;
vector<bool> recStack;

void dfs(int node)
{
        for (auto neigh : dg[node])
        {
                if (visited[neigh] == -1)
                {
                        visited[neigh] = dfsno;
                        dfs(neigh);
                }
                else if (visited[neigh] == dfsno && (recStack[neigh] == true))
                {
                        flag = -1;
                }
                if (flag == -1)
                        return;
        }
        recStack[node] = false;
        ans.pb(node);
}
void top_sort()
{
        for (int i = 0; i < n; i++)
        {
                dfsno++;
                if (visited[i] == -1)
                {
                        visited[i] = dfsno;
                        recStack[i] = true;
                        dfs(i);
                }
        }
        reverse(ans.begin(), ans.end());
}
//...............................

void suraj()
{
        cin >> n >> m;
        dg = vector<vector<int>>(n, vector<int>());
        visited = vector<int>(n, -1);
        recStack = vector<bool>(n, false);
        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                dg[a].pb(b);
        }
        top_sort();

        if (flag == -1)
        {
                cout << "IMPOSSIBLE" << endl;
                return;
        }

        for (int i : ans)
                cout
                    << i + 1 << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
