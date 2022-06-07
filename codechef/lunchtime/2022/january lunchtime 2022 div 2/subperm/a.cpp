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
        if (n == 1)
        {
                if (k == 1)
                        cout << 1 << endl;
                return;
        }
        int diff = n - k;
        if (diff + 2 > n)
        {
                cout << -1 << endl;
                return;
        }
        vector<int> v;
        int val = 1;
        for (int i = 1; i <= n; i++)
        {
                if (i == diff + 2)
                {
                        v.pb(2);
                        if (val == 2)
                                val++;
                }
                else if (i == 2)
                {
                        v.pb(++val);
                        val++;
                }
                else
                {
                        v.pb(val++);
                }
        }
        for (int i : v)
                cout << i << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
