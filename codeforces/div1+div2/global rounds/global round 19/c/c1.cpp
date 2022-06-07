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

        ll carry = 0;
        ll ans = 0;

        bool even = false;

        for (int i = 1; i <= n - 2; i++)
        {
                if (v[i] % 2 == 0)
                {
                        even = true;
                        break;
                }
        }

        if (even)
        {
                for (int i = 1; i <= n - 2; i++)
                        ans += (v[i] + 1) / 2;
                cout << ans << endl;
        }
        else
        {
                if (n == 3)
                        cout << -1 << endl;
                else
                {
                        int cnt_one = 0;
                        for (int i = 1; i <= n - 2; i++)
                        {
                                if (v[i] == 1)
                                        cnt_one++;
                        }
                        if (cnt_one == n - 2)
                                cout << -1 << endl;
                        else
                        {
                                for (int i = 1; i <= n - 2; i++)
                                        ans += (v[i] + 1) / 2;
                                cout << ans << endl;
                        }
                }
        }
}

//................................

// ll

// ll

// int

// int
