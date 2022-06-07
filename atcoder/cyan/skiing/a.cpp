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
int n, m;
vector<vector<int>> tree;
vector<int> height, happiness;
int ans = 0;
void dfs(int node, int parent)
{
        cout << "node : " << node << " , parent : " << parent << endl;
        for (auto child : tree[node])
        {
                if (child == parent)
                        continue;
                if (height[node] >= height[child])
                {
                        int delHappiness = height[node] - height[child]; // >= 0
                        happiness[child] = happiness[node] + delHappiness;
                }
                else if (height[node] < height[child])
                {
                        int delHappiness = 2 * (height[node] - height[child]); // < 0
                        happiness[child] = happiness[node] + delHappiness;
                }
                ans = max(ans, happiness[child]);
                dfs(child, node);
        }
        return;
}
//...............................

void suraj()
{
        cin >> n >> m;
        tree = vector<vector<int>>(n + 1, vector<int>());

        height = vector<int>(n + 1, 0);
        happiness = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; i++)
                cin >> height[i];

        for (int i = 1; i <= m; i++)
        {
                int u, v;
                cin >> u >> v;
                tree[u].pb(v);
                tree[v].pb(u);
        }

        ans = happiness[1]; // ie = 0

        dfs(1, -1);

        cout << ans << endl;
}

//................................

// int

// int

// int

// int
