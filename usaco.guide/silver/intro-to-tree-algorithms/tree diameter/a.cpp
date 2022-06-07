// two dfs implementation
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
int n;
vector<vector<int>> tree;
int maxDist = 0, maxDistNode = -1;
void dfs(int node, int parent, int dist)
{
        // cout << node << " " << parent << " " << dist << endl;
        for (int child : tree[node])
        {
                if (child == parent)
                        continue;
                if (dist + 1 > maxDist)
                {
                        maxDist++;
                        maxDistNode = child;
                }
                // cout << maxDist << " " << maxDistNode << " " << parent << endl;
                dfs(child, node, dist + 1);
        }
}
//...............................

void suraj()
{
        cin >> n;
        tree = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++)
        {
                int a, b;
                cin >> a >> b;
                tree[a].pb(b);
                tree[b].pb(a);
        }
        dfs(1, -1, 0);
        maxDist = 0;
        dfs(maxDistNode, -1, 0);
        cout << maxDist << endl;
}

//................................

// int

// int

// int

// int
