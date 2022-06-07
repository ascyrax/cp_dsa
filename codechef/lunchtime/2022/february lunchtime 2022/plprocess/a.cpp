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
        ll n;
        cin >> n;
        ll sum = 0;
        vector<ll> v(n);
        for (ll &i : v)
        {
                cin >> i;
                sum += i;
        }
        ll total = sum;
        sum = 0;
        ll ans = 1e18;
        for (ll i = 0; i < n; i++)
        {
                sum += v[i];
                ans = min(ans, max(sum, total - sum));
        }
        // cout << total / 2 + abs(sum) << endl;
        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
