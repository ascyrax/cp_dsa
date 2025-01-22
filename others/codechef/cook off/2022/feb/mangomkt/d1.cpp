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
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> g(n + 1, vector<ll>());

        vector<ll> node(n + 1, 0);

        ll sum = 0;

        for (ll i = 1; i <= n; i++)
        {
                cin >> node[i];
                sum += node[i];
        }

        for (ll i = 1; i <= m; i++)
        {
                ll a, b;
                cin >> a >> b;

                g[a].pb(b);
                g[b].pb(a);
        }

        ll q;
        cin >> q;
        for (ll i = 1; i <= q; i++)
        {
                char a;
                cin >> a;
                if (a == '?')
                {
                        cout << sum + 2 * m - ((n - 1) * (n - 1 + 1) / 2) << endl;
                }
                else if (a == '+')
                {
                        ll a, b;
                        cin >> a >> b;
                        m++; // m is the no of edges
                }
                else
                {
                        ll a, b;
                        cin >> a >> b;
                        m--;
                }
        }
}

//................................

// ll

// ll

// int

// int
