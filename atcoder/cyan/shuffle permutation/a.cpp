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
ll n, k;
int mod = 998244353;
vector<bool> visited;
vector<vector<int>> graph_row, graph_col;
int cnt = 0;
ll fact(ll n)
{
        ll result = 1;
        while (n)
        {
                result *= n;
                result %= mod;
                n--;
        }
        return result;
}

void dfs_row(int node)
{
        for (auto neigh : graph_row[node])
        {
                if (!visited[neigh])
                {
                        cnt++;
                        visited[neigh] = true;
                        dfs_row(neigh);
                }
        }
}
void dfs_col(int node)
{
        for (auto neigh : graph_col[node])
        {
                if (!visited[neigh])
                {
                        cnt++;
                        visited[neigh] = true;
                        dfs_col(neigh);
                }
        }
}
//...............................

void suraj()
{
        cin >> n >> k;
        vector<vector<ll>> grid(n + 1, vector<ll>(n + 1, 0));
        for (ll i = 1; i <= n; i++)
        {
                for (ll j = 1; j <= n; j++)
                {
                        cin >> grid[i][j];
                }
        }

        graph_row = vector<vector<int>>(n + 1, vector<int>());
        graph_col = vector<vector<int>>(n + 1, vector<int>());

        // ll colPairs = 0;
        for (ll i = 1; i <= n; i++)
        {
                for (ll j = i + 1; j <= n; j++)
                {
                        ll flag = 1;
                        for (ll row = 1; row <= n; row++)
                        {
                                if (grid[row][i] + grid[row][j] > k)
                                {
                                        flag = -1;
                                        break;
                                }
                        }
                        if (flag == 1)
                        {
                                // cols.insert(i);cols.insert(j);
                                graph_col[i].pb(j);
                                graph_col[j].pb(i);
                                // colPairs++;
                        }
                }
        }

        // ll rowPairs = 0;
        for (ll i = 1; i <= n; i++)
        {
                for (ll j = i + 1; j <= n; j++)
                {
                        ll flag = 1;
                        for (ll col = 1; col <= n; col++)
                        {
                                if (grid[i][col] + grid[j][col] > k)
                                {
                                        flag = -1;
                                        break;
                                }
                        }
                        if (flag == 1)
                        {
                                graph_row[i].pb(j);
                                graph_row[j].pb(i);
                        }
                        // rowPairs++;
                }
        }
        // cout << rowPairs << " " << colPairs << endl;

        // cout << (fact(rowPairs + 1) * fact(colPairs + 1)) % mod << endl;

        ll ans = 1;
        // columns
        visited = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
                if (!visited[i])
                {
                        cnt = 1;
                        visited[i] = true;
                        dfs_col(i);
                        ans *= fact(cnt);
                        ans %= mod;
                }
        }

        // rows
        visited = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
                if (!visited[i])
                {
                        cnt = 1;
                        visited[i] = true;
                        dfs_row(i);
                        ans *= fact(cnt);
                        ans %= mod;
                }
        }
        cout << ans << endl;

        // for (int i = 0; i <= n; i++)
        // {
        //         for (auto el : graph_row[i])
        //                 cout << el << " ";
        //         cout << endl;
        // }

        // for (int i = 0; i <= n; i++)
        // {
        //         for (auto el : graph_col[i])
        //                 cout << el << " ";
        //         cout << endl;
        // }
}

//................................

// ll

// ll

// ll

// int
