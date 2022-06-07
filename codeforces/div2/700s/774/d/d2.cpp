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
vector<vector<int>> t;
vector<vector<pair<int, int>>> dp;
vector<bool> visited;
void dfs(int node, int parent)
{
        dp[node][1].first = 1; // i.e. itself
        dp[node][1].second = 0;
        dp[node][0].first = 0; // since this node is not included as a good node.
        dp[node][0].second = 0;
        for (auto neigh : t[node])
        {
                if (neigh == parent)
                {
                        dp[node][1].first += dp[neigh][0].first;
                        dp[node][1].second += dp[neigh][0].second;
                        dp[node][0].first += max(dp[neigh][0].first, dp[neigh][1].first);
                        if (dp[neigh][0].first > dp[neigh][1].first)
                                dp[node][0].second += dp[neigh][0].second;
                        else
                                dp[node][0].second += dp[neigh][1].second;
                        continue;
                }
                if (!visited[neigh])
                {
                        visited[neigh] = true;
                        dfs(neigh, node);
                }
                dp[node][1].first += dp[neigh][0].first;
                dp[node][1].second += dp[neigh][0].second;
                dp[node][0].first += max(dp[neigh][0].first, dp[neigh][1].first);
                if (dp[neigh][0].first > dp[neigh][1].first)
                        dp[node][0].second += dp[neigh][0].second;
                else
                        dp[node][0].second += dp[neigh][1].second;
        }
        dp[node][1].second *= 2; // adding the weight of node which is equal to the sum of the weights of all its neighbors.
        dp[node][0].second += 1; // since this node is given the weight = 1 only.
        return;
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        t = vector<vector<int>>(n, vector<int>());
        visited = vector<bool>(n, false);
        dp = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, make_pair(0, 0)));
        // dp[i][0] = (g,s)=> if i is the root and it is chosen as a bad node, then in its subtree, there are g good nodes and the sum of all the nodes in the subtree is = s.
        // dp[i][1] = (g,s)=> if i is the root and it is chosen as a good node, then in its subtree, there are g good nodes and the sum of all the nodes in the subtree is = s.

        for (int i = 0; i < n - 1; i++)
        {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                t[a].pb(b);
                t[b].pb(a);
        }
        dfs(0, -1);

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < 2; j++)
                {
                        cout << dp[i][j].first << " " << dp[i][j].second << "  ,  ";
                }
                cout << endl;
        }

        pair<int, int> ans = make_pair(0, 1e18);

        for (int i = 0; i < n; i++)
        {
                // case 1: when i is the root and it is chosen.
                if (dp[i][1].first > ans.first)
                        ans = dp[i][1];
                else if (dp[i][1].first == ans.first)
                {
                        if (dp[i][1].second <= ans.second)
                                ans = dp[i][1];
                }
                // case 2: when i is the root and it is not chosen.
                if (dp[i][0].first > ans.first)
                        ans = dp[i][0];
                else if (dp[i][0].first == ans.first)
                {
                        if (dp[i][0].second <= ans.second)
                                ans = dp[i][0];
                }
        }

        cout << ans.first << " " << ans.second << endl;
}

//................................

// int

// int

// int

// int
