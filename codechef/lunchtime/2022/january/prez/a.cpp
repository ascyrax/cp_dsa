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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll lens = n;

        // vector<ll> v(lens);
        ll last = k;
        ll i = 0;
        for (i = 0; i < n; i++)
        {
                ll diff = 10ll - (s[i] - '0');
                if (diff == 10ll)
                        diff = 0ll;
                if (last - diff < 0ll)
                        break;
                ll q = (last - diff) / 10ll;

                last = q * 10ll + diff;

                // last = v[i];
        }
        cout << i << endl;
}

//................................

// ll

// int

// int

// int
