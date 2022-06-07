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
        int n, k;
        cin >> n >> k;

        if (k == n - 1)
        {
                if (n == 4)
                        cout << -1 << endl;
                else
                {
                        cout << n / 2 + 1 << " " << n - 1 << endl;
                        for (int i = 1; i < n / 2 - 2; i++)
                        {
                                cout << i << " " << n - 1 - i << endl;
                        }
                        cout << n / 2 - 2 << " " << n / 2 - 2 + 1 << endl;
                        cout << 0 << " " << n / 2 << endl;
                }
        }
        else
        {
                cout << k << " " << n - 1 << endl;
                for (int i = 1; i < n / 2; i++)
                {
                        if ((i == k) || (n - 1 - i == k))
                        {
                                if (i == k)
                                        cout << 0 << " " << n - 1 - i << endl;
                                else
                                        cout << i << " " << 0 << endl;
                        }
                        else
                                cout << i << " " << n - 1 - i << endl;
                }
        }
}

//................................

// int

// int

// int

// int
