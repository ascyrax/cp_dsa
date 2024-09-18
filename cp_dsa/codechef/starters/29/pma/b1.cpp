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
        ll mnPos = 1e9;
        ll mxNeg = 0;
        ll
            sum = 0;
        for (ll i = 0; i < n; i++)
        {
                ll a;
                cin >> a;
                a = abs(a);

                if (i % 2 == 0)
                {
                        mnPos = min(mnPos, a);
                        sum += a;
                }
                else
                {
                        sum -= a;
                        mxNeg = max(mxNeg, a);
                }
        }
        ll ans1 = sum;
        // cout << sum << endl;
        sum -= 2 * mnPos;
        sum += 2 * mxNeg;
        cout << max(ans1, sum) << endl;
}

//................................

// ll

// ll

// int

// int
