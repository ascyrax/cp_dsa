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
        if (n == 1)
        {
                cout << 0 << endl;
        }
        else if (n == 2 || n == 3)
        {
                cout << 6 << endl;
        }
        else if (n == 4)
        {
                cout << 20 << endl;
        }
        else
        {
                int val = 1;
                while (val < n)
                {
                        val *= 2;
                }
                // val-1 -> 0
                // val-2 -> 1
                // val-(n+1) ->n
                int last = val - (n + 1);
                cout << "last = " << last << endl;
                // if nth position has a value t, then n-3 will have t+3.
                // => if nth position has a value last then for value last+diff, we need to go to n-diff position.
                int a = (n - last); // 1-indexed.
                ll ans = 0;
                ans += (last + 1) * val;
                }
}

//................................

// int

// int

// int

// int
