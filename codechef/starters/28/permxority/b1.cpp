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
        int n;
        cin >> n;

        if (n == 2)
                cout << -1 << endl;
        else if (n % 2 == 1)
        {
                for (int i = 1; i <= n; i++)
                        cout << i << " ";
                cout << endl;
        }
        else
        {
                cout << 1 << " " << n << " ";
                for (int i = 2; i <= n - 1; i++)
                        cout << i << " ";
                cout << endl;
        }
}

//................................

// int

// int

// int

// int
