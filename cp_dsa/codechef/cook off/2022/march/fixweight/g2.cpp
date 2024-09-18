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
        ll n, x;
        cin >> n >> x;

        if (x <= n)
        {
                cout << "YES" << endl;
                return;
        }
        // else if x>n
        for (ll i = 2; i <= n; i++)
        {
                ll maxLen = (n - i + 1);
                if (x % i == 0 && x / i <= n && (x / i) <= maxLen)
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
