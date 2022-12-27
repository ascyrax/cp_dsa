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
        ll cnt = 0;
        while (1)
        {
                cnt++;
                ll a = 1;
                while (a < n)
                        a *= 2;
                if (a == n)
                {
                        cout << cnt << endl;
                        return;
                }
                else
                        a /= 2;

                ll b = 1;
                ll next = 1;
                while (b < n)
                        b *= (++next);
                if (b == n)
                {
                        cout << cnt << endl;
                        return;
                }
                else
                        b /= next;
                n -= max(a, b);
        }
}

//................................

// ll

// ll

// int

// int
