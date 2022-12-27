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
        int l, r, k;
        cin >> l >> r >> k;

        int neven = 0, nodd = 0;

        if (l % 2 == 0)
        {
                if (r % 2 == 0)
                {
                        neven = (r - l + 1 + 1) / 2;
                        nodd = (r - l + 1) - neven;
                }
                else
                {
                        neven = (r - l + 1) / 2;
                        nodd = neven;
                }
        }
        else
        {
                if (r % 2 == 0)
                {
                        neven = (r - l + 1) / 2;
                }
                else
                {
                        nodd = (r - l + 1 + 1) / 2;
                        neven = (r - l + 1) - nodd;
                }
        }

        cout << neven << " " << nodd << endl;

        if (k >= nodd)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;
}

//................................

// int

// int

// int

// int
