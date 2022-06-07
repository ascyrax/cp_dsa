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
vector<vector<int>> dag;
vector<bool> visited;
vector<int> dp;
// dp[i] = max length of a path starting at the ith index.

int dfs(int node)
{
        for (auto neigh : dag[node])
        {
                if (!visited[neigh])
                {
                        visited[neigh] = true;
                        dp[node] = max(dp[node], dfs(neigh) + 1);
                }
                else
                {
                        dp[node] = max(dp[node], dp[neigh] + 1);
                }
        }
        return dp[node];
}
//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;

        dag = vector<vector<int>>(n, vector<int>());
        visited = vector<bool>(n, false);
        dp = vector<int>(n, 0);

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                dag[a].pb(b);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
                if (!visited[i])
                {
                        visited[i] = true;
                        int val = dfs(i);
                        // cout << "val = " << val << endl;
                        ans = max(ans, val);
                }
        }
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
