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

        freopen("milkvisits.in", "r", stdin);
        freopen("milkvisits.out", "w", stdout);

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
string s;
vector<vector<int>> tree;
vector<bool> visited;
int cntH = 0, cntG = 0;
int start, finish;
bool found = false;
void dfs(int node)
{
        for (auto neigh : tree[node])
        {
                if (!visited[neigh])
                {
                        if (s[neigh - 1] == 'H')
                                cntH++;
                        else
                                cntG++;
                        visited[neigh] = true;
                        if (neigh == finish)
                        {
                                found = true;
                                return;
                        }
                        dfs(neigh);
                        if (found)
                                return;
                        if (s[neigh - 1] == 'H')
                                cntH--;
                        else
                                cntG--;
                }
        }
}
//...............................

void suraj()
{
        cin >> n >> m;
        cin >> s;
        int lens = n;
        tree = vector<vector<int>>(n + 1, vector<int>());

        for (int i = 0; i < n - 1; i++)
        {
                int a, b;
                cin >> a >> b;
                tree[a].pb(b);
                tree[b].pb(a);
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
                char c;
                cin >> start >> finish >> c;
                visited = vector<bool>(n + 1, false);
                cntH = 0, cntG = 0;
                found = false;
                // dfs from a to finish and if cnt of c>0 the ans.pb(1) else ans.pb(0)
                visited[start] = true;
                if (s[start - 1] == 'H')
                        cntH++;
                else
                        cntG++;
                dfs(start);
                // cout << c << " " << cntH << " " << cntG << endl;
                if (c == 'H')
                {
                        if (cntH > 0)
                                ans.pb(1);
                        else
                                ans.pb(0);
                }
                else
                {
                        if (cntG > 0)
                                ans.pb(1);
                        else
                                ans.pb(0);
                }
        }
        for (auto el : ans)
                cout << el;
        cout << endl;
}

//................................

// int

// int

// int

// int
