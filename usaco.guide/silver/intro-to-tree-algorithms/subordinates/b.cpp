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
vector<int> subtree;
void dfs(int node, int parent)
{
        subtree[node] = 1; // ie counting the node itself
        for (auto neigh : tree[node])
        {
                if (neigh != parent)
                {
                        dfs(neigh, node);
                }
                subtree[node] += subtree[neigh];
        }
        return;
}
//...............................

void suraj()
{
        cin >> n;
        tree = vector<vector<int>>(n + 1, vector<int>());
        subtree = vector<int>(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
                int parent;
                cin >> parent;
                tree[parent].pb(i);
        }

        dfs(1, -1);

        for (int i = 1; i <= n; i++)
        {
                cout << subtree[i] - 1 << " ";
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
