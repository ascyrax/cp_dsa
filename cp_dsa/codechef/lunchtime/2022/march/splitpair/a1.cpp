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

        vector<int> digits;
        int last = n % 10;
        n /= 10;
        int even = 0, odd = 0, zero = 0;
        while (n > 0)
        {
                int rem = n % 10;
                if (rem & 1)
                        odd++;
                else
                        even++;
                digits.pb(n % 10);
                n /= 10;
        }
        if (last & 1)
        {
                if (odd >= 1)
                        cout << "YES" << endl;
                else
                        cout << "NO" << endl;
        }
        else
        {
                if (even >= 1)
                        cout << "YES" << endl;
                else
                        cout << "NO" << endl;
        }
}

//................................

// int

// int

// int

// int
