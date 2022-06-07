// dp implementation
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
vector<int> leafDist, maxLen;
// maxLen[i] is the max length of a path whose root(highest point) is node i.
int diameter = 0;
void dfs(int node, int parent)
{
        int nChild = 0;
        vector<int> v;
        for (auto child : tree[node])
        {
                if (child == parent)
                        continue;
                nChild++;
                dfs(child, node);
                // maxLen[node] = max(maxLen[node], leafDist[child] + 1);
                v.pb(leafDist[child]);
                leafDist[node] = max(leafDist[node], leafDist[child] + 1);
        }
        sort(v.rbegin(), v.rend());
        if (nChild == 0)
                return;
        else if (nChild == 1)
        {
                // maxLen[node] = max(maxLen[node], leafDist[child] + 1);
                maxLen[node] = v[0] + 1;
        }
        else
        {
                maxLen[node] = v[0] + v[1] + 2;
        }
        diameter = max(diameter, maxLen[node]);
}
//...............................

void suraj()
{
        cin >> n;
        tree = vector<vector<int>>(n + 1, vector<int>());
        leafDist = vector<int>(n + 1, 0);
        maxLen = vector<int>(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
                int a, b;
                cin >> a >> b;
                tree[a].pb(b);
                tree[b].pb(a);
        }
        dfs(1, -1);
        cout << diameter << endl;
}

//................................

// int

// int

// int

// int
