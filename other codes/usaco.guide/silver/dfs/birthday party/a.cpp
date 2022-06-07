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
int n, m;
int main()
{

        // ioss

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        // cin>>t;
        while (1)
        {
                cin >> n >> m;
                if (n == 0 && m == 0)
                        return 0;
                else
                {
                        suraj();
                }
        }

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
        vector<vector<int>> g(n, vector<int>());

        for (int i = 0; i < m; i++)
        {
                int a, b;
                cin >> a >> b;
                g[a].pb(b);
                g[b].pb(a);
        }
        if (n == 1)
        {
                cout << "No" << endl;
                return;
        }
        for (int i = 0; i < n; i++)
                if (g[i].size() <= 1)
                {
                        cout << "Yes" << endl;
                        return;
                }
        cout << "No" << endl;
}

//................................

// int

// int

// int

// int
