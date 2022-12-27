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

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................
ll mod = 998244353;
void suraj()
{
        ll n, m, k, q;
        cin >> n >> m >> k >> q;
        map<ll, ll> row, col;
        // vector<vector<ll>> grid(n + 1, vector<ll>(m + 1));
        set<ll> st;
        vector<int> rows, cols;
        for (ll i = 1; i <= q; i++)
        {
                ll x, y;
                cin >> x >> y;
                row[x] = i;
                col[y] = i;
                rows.pb(x);
                cols.pb(y);
        }
        for (ll i : rows)
        {
                for (ll j : cols)
                {
                        // grid[i][j] = max(row[i], col[j]);
                        if (max(row[i], col[j]) != 0)
                                st.insert(max(row[i], col[j]));
                }
        }
        ll cnt = st.size();
        ll ans = 1;

        for (ll i = 1; i <= cnt; i++)
        {
                ans *= k;
                ans %= mod;
                // k--;
        }

        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
