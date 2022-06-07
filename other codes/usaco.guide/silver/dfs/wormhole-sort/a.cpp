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
int n, m;

vector<int> visited;
vector<vector<pair<int, int>>> g;
bool check(int val)
{
}
//...............................

void suraj()
{
        cin >> n >> m;
        vector<int> v(n + 1);
        visited = vector<int>(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
                cin >> v[i];
        }
        g = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
        for (int i = 0; i < n; i++)
        {
                int a, b, w;
                cin >> a >> b >> w;
                g[a].pb(make_pair(b, w));
                g[b].pb(make_pair(a, w));
        }

        int l = 0, r = 1e9;
        while (l < r)
        {
                int m = l + (r - l) / 2;
                if (check(m))
                {
                        r = m;
                }
                else
                        l = m + 1;
        }
        cout << l << endl;
}

//................................

// int

// int

// int

// int
