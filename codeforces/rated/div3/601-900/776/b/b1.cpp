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
        ll l, r, a;
        cin >> l >> r >> a;
        ll qmax = r / a;
        ll rmax = r % a;
        ll ans = qmax + rmax;
        if (qmax * a - 1 >= l)
        {
                rmax = a - 1;
                ans = max(ans, (qmax - 1 + (a - 1)));
        }
        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
