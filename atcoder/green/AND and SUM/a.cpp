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
// ll ll
//...............................

void suraj()
{
        ll a, s;
        cin >> a >> s;

        if (a > s / 2)
        {
                cout << "No" << endl;
                return;
        }
        // else if (a == s / 2) // a=1 and s=1 was leading to the error.
        // {
        //         cout << "Yes" << endl;
        //         return;
        //         // if s = odd , x = s/2 & y = s/2+1
        //         // if s = eve , x = s/2 & y = s/2
        // }
        else if (a <= s / 2)
        {
                ll y = s - 2 * a;

                if ((y & a) == 0)
                        cout << "Yes" << endl;
                else
                        cout << "No" << endl;
                return;

                // assuning x=a and y=a for Now.
                // for the binary form of y, if say 5th bit is 1, then either the 5th bit a needs
                // to be 1 or even the 4th bit of a needs to be 1.

                // converting a llo binary form
                vector<ll> bin_a;
                while (a)
                {
                        if (a & 1)
                                bin_a.pb(1);
                        else
                                bin_a.pb(0);
                        a /= 2;
                }
                while (bin_a.size() < 65)
                        bin_a.pb(0);
                reverse(bin_a.begin(), bin_a.end());

                // converting y llo binary form
                vector<ll> bin_y;
                while (y)
                {
                        if (y & 1)
                                bin_y.pb(1);
                        else
                                bin_y.pb(0);
                        y /= 2;
                }
                while (bin_y.size() < 65)
                        bin_y.pb(0);
                reverse(bin_y.begin(), bin_y.end());

                // cout << "bin_a: " << endl;
                // for (auto el : bin_a)
                //         cout << el;
                // cout << endl;

                // cout << "bin_y: " << endl;
                // for (auto el : bin_y)
                //         cout << el;
                // cout << endl;

                for (ll i = 0; i < bin_y.size(); i++)
                {
                        if (bin_y[i] == 1)
                        {
                                // cout << "i: " << i << endl;
                                if (bin_a[i] == 0)
                                {
                                        // cout << "if" << endl;
                                        continue;
                                }
                                else
                                {
                                        // cout << "else" << endl;
                                        cout << "No" << endl;
                                        return;
                                }
                        }
                }
                cout << "Yes" << endl;
        }
}

//................................

// ll

// ll

// int

// int
