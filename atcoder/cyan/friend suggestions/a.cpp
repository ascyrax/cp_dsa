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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> components(n + 1), compSize(n + 1, 1);
        for (int i = 1; i <= n; i++)
                components[i] = i;

        vector<vector<int>> graph(n + 1, vector<int>()), blocks(n + 1, vector<int>());

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                graph[a].pb(b);
                graph[b].pb(a);

                int ca = components[a];
                int cb = components[b];
                while (components[ca] != ca)
                        ca = components[ca];
                while (components[cb] != cb)
                        cb = components[cb];

                if (cb > ca)
                {
                        components[ca] = cb;
                        compSize[cb] += compSize[ca];
                }
                else if (ca > cb)
                {
                        components[cb] = ca;
                        compSize[ca] += compSize[cb];
                }
        }

        // for (int i = 1; i <= n; i++)
        //         cout << components[i] << " ";
        // cout << endl;

        for (int i = 0; i < k; i++)
        {
                int c, d;
                cin >> c >> d;
                blocks[c].pb(d);
                blocks[d].pb(c);
        }
        // cout << "a" << endl;

        // cout << "blocks: " << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //         for (auto el : blocks[i])
        //                 cout << el << " ";
        //         cout << endl;
        // }

        // cout << "compSize: " << endl;
        // for (auto el : compSize)
        //         cout << el << " ";
        // cout << endl;

        for (int v = 1; v <= n; v++) // v for vertex
        {
                int cv = components[v];
                while (components[cv] != cv)
                        cv = components[cv];
                int cvSize = compSize[cv];
                int edgesv = graph[v].size();

                // cout << endl
                //      << "v = " << v << " ";

                int fcand = (cvSize - 1) - edgesv; // -1 for itself & -edgesv for those who are friends already

                // cout << cv << " " << cvSize << " " << edgesv << " " << fcand << endl;

                for (auto el : blocks[v])
                {
                        int cel = components[el];
                        while (components[cel] != cel)
                                cel = components[cel];
                        if (cel == cv)
                                fcand--;
                }
                cout << fcand << " ";
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
