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
        ll n, alice, y;
        cin >> n >> alice >> y;

        int bob = alice + 3;

        vector<ll> v(n);
        int n_odd = 0;
        for (ll &el : v)
        {
                cin >> el;
                if (el & 1)
                        n_odd++;
        }
        if (n_odd & 1)
        {
                alice = alice ^ 1;
                bob = bob ^ 1;
        }
        if ((alice & 1) == (y & 1))
                cout << "Alice" << endl;
        else
                cout << "Bob" << endl;
}

//................................

// int

// int

// int

// int
