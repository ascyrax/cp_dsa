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
        if (n == k && n == 1)
        {
                cout << "YES" << endl;
                cout << 1 << endl;
                return;
        }
        int n_odd = (n * k + 1) / 2;
        int n_even = (n * k) / 2;
        if (n_even % k == 0 && n_odd % k == 0)
        {
                cout << "YES" << endl;
                int a = 1, b = 2;
                int even_rows = n_even / k;
                int odd_rows = n_odd / k;
                for (int i = 1; i <= odd_rows; i++)
                {
                        for (int j = 1; j <= k; j++)
                        {
                                cout << a << " ";
                                a += 2;
                        }
                        cout << endl;
                }
                for (int i = 1; i <= even_rows; i++)
                {
                        for (int j = 1; j <= k; j++)
                        {
                                cout << b << " ";
                                b += 2;
                        }
                        cout << endl;
                }
        }
        else
                cout << "NO" << endl;
}

//................................

// int

// int

// int

// int
