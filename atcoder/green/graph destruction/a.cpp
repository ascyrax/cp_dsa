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

//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n + 1, vector<int>());

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                g[a].pb(b);
                g[b].pb(a);
        }

        for (int i = 1; i <= n; i++)
        {
                sort(g[i].rbegin(), g[i].rend());
        }

        int nComps = 0;
        vector<int> ans;
        // when simulation has not begun => 0 components
        ans.pb(0);
        // for nth vertex
        nComps = 1;
        ans.pb(nComps);
        // we will place the vertex from nth to 1st and find the no of components
        for (int i = n - 1; i >= 1; i--)
        {
                cout << "vertex = " << i << endl;
                cout << "g[i][0] = " << g[i][0] << endl;
                cout << "nComps before conditions = " << nComps << endl;
                if (g[i][0] > i)
                {
                        // => it has an edge common with some vertex which is already present in our ongoing simulation
                        ans.pb(nComps);
                }
                else
                {
                        nComps++;
                        ans.pb(nComps);
                }
                cout << "nComps: " << nComps << endl;
        }
        // we dont need the no of components before removing the first vertex.
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        for (auto el : ans)
                cout << el << endl;
}

//................................

// int

// int

// int

// int
