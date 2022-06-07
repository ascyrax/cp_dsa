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
        int n, k, x;
        cin >> n >> k >> x;

        if (x > k)
        {
                cout << -1 << endl;
        }
        else if (x <= k)
        {
                int q = n / k;
                int r = n % k;
                vector<int> v;
                while (n > 0)
                {
                        for (int i = 0; i < x; i++)
                        {
                                cout << i << " ";
                                n--;
                                if (n == 0)
                                        break;
                        }
                }
                cout << endl;
        }
}

//................................

// int

// int

// int

// int
