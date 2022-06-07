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
vector<vector<ll>> tree;
vector<ll> w;
vector<bool> visited;
void dfs(ll node)
{
        // cout << "node = " << node + 1 << endl;
        ll flag = 1;
        if (w[node] == 0)
                flag = 0;
        // cout << "flag = " << flag << endl;
        for (auto neigh : tree[node])
        {
                // cout << "neigh = " << neigh + 1 << endl;
                if (!visited[neigh])
                {
                        visited[neigh] = true;
                        dfs(neigh);
                }
                if (flag == 0)
                {
                        // cout << "wneigh = " << w[neigh] << endl;
                        w[node] += w[neigh];
                }
        }
        return;
}
//...............................

void suraj()
{
        ll n;
        cin >> n;
        tree = vector<vector<ll>>(n, vector<ll>());
        w = vector<ll>(n, 0);
        visited = vector<bool>(n, false);

        for (ll i = 0; i < n - 1; i++)
        {
                ll a, b;
                cin >> a >> b;
                a--;
                b--;
                tree[a].pb(b);
                tree[b].pb(a);
        }
        ll leaf = -1;
        for (ll i = 0; i < n; i++)
        {
                if (tree[i].size() == 1)
                {
                        if (leaf == -1)
                                leaf = i;
                        // i.e. if i is a leaf.
                        w[i] = 1;
                        w[tree[i][0]] = 1;
                }
        }

        // for (ll i : w)
        //         cout << i << " ";
        // cout << endl;

        visited[leaf] = true;
        dfs(leaf);

        ll cntGood = 0, sumWeights = 0;
        for (ll i = 0; i < n; i++)
        {
                ll neighW = 0;
                for (auto neigh : tree[i])
                {
                        neighW += w[neigh];
                }
                sumWeights += w[i];
                if (w[i] == neighW)
                        cntGood++;
        }

        cout << cntGood << " " << sumWeights << endl;
        for (auto weight : w)
                cout << weight << " ";
        cout << endl;
}

//................................

// ll

// ll

// int

// int
