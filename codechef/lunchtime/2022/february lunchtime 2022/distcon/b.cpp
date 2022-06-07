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

        // cin>>t;

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
        int d;
        cin >> d;

        int x1 = 2e5, y1 = 2e5;
        int x2 = x1 + d, y2 = y1;
        if (d % 2 == 0)
        {
                int x3 = x1 + d / 2;
                int y3 = y1 - d / 2;
                int x4 = x3;
                int y4 = y1 + d / 2;
                cout << x1 << " " << y1 << endl;
                cout << x2 << " " << y2 << endl;
                cout << x3 << " " << y3 << endl;
                cout << x4 << " " << y4 << endl;
        }
        else
        {
                // int x3=
                // cout << x1 << " " << y1 << endl;
                // cout << x2 << " " << y2 << endl;
                // cout << x3 << " " << y3 << endl;
                // cout << x4 << " " << y4 << endl;
                cout << -1 << endl;
        }
}

//................................

// int

// int

// int

// int
