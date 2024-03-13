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

        ioss

            // startTime=(double)clock();

            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

            // cout << setprecision(15) << fixed;

            int t = 1;

        // cin >> t;

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
        ll mod = 1e9 + 7;
        ll n, m;
        cin >> n >> m;

        vector<ll> compounds(n);
        for (ll i = 0; i < n; i++)
        {
                cin >> compounds[i];
        }

        for (ll i = 0; i < m; i++)
        {
                ll c, x;
                cin >> c >> x;
                c--;
                ll temp = compounds[c];
                compounds[c] = 0;

                // vector<pair<ll, ll>> decomps(x, make_pair(0, 0));

                for (ll j = 0; j < x; j++)
                {
                        ll wi, xi;
                        cin >> wi >> xi;
                        xi--;
                        // decomps.pb(make_pair(wi, xi));
                        compounds[xi] += wi * temp;
                        compounds[xi] %= mod;
                }
        }

        for (ll i : compounds)
                cout << i << endl;
}

//................................

// ll

// int

// int

// int
