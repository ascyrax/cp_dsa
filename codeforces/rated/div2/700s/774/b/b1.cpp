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
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        sort(v.rbegin(), v.rend());

        ll sred = 0, sblue = 0;
        ll l = 0, r = n - 1;
        sred += v[l++];
        sblue += v[r--];
        sblue += v[r--];
        if (sred > sblue)
        {
                cout << "YES" << endl;
                return;
        }
        while (l < r)
        {
                sred += v[l++];
                sblue += v[r--];
                // cout << sred << " " << sblue << endl;
                if (sred > sblue)
                {
                        cout << "YES" << endl;
                        return;
                }
        }
        cout << "NO" << endl;
}

//................................

// ll

// ll

// int

// int
