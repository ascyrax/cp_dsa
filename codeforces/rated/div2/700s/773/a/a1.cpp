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
        int xa, ya;
        cin >> xa >> ya;
        int xb, yb;
        cin >> xb >> yb;
        int xc, yc;
        cin >> xc >> yc;

        int len = 0;

        if (ya == yb || yb == yc || yc == ya)
        {
                if (ya == yb)
                {
                        len = abs(xa - xb);
                        if (yc > yb)
                                cout << 0 << endl;
                        else
                                cout << len << endl;
                }
                else if (yb == yc)
                {
                        len = abs(xb - xc);
                        if (ya > yb)
                                cout << 0 << endl;
                        else
                                cout << len << endl;
                }
                else
                {
                        len = abs(xc - xa);
                        if (yb > ya)
                                cout << 0 << endl;
                        else
                                cout << len << endl;
                }
        }
        else
                cout << 0 << endl;
}

//................................

// int

// int

// int

// int
