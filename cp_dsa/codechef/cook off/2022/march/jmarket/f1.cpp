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

void suraj()
{
        ll x, a, b, c;
        cin >> x >> a >> b >> c;
        vector<ll> v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        sort(v.begin(), v.end());
        ll ans = 0;
        ans = (x - 1) * v[0];
        ans += v[1];
        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
