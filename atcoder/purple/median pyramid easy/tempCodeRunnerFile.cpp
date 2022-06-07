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
        int n, x;
        cin >> n >> x;

        if (n != x)
        {
                if (x == 1 || x == 2 * n - 1)
                {
                        cout << "No" << endl;
                }
                else if (x == 2)
                { // n>2 cz n==2 case will not come here.
                        // since x-2 is not possible therefore we could not put this in the else case and had to make a separate case
                        //       3 1 2 4 where 2 is the mid element
                        cout << "Yes" << endl;
                        int val = 5;
                        for (int i = 1; i <= n - 3; i++)
                                cout << val++ << endl;
                        cout << 3 << endl;
                        cout << 1 << endl;
                        cout << 2 << endl;
                        cout << 4 << endl;
                        for (int i = n + 2; i <= 2 * n - 1; i++)
                                cout << val++ << endl;
                }
                else
                {
                        cout << "Yes" << endl;

                        int val = 1;
                        for (int i = 1; i <= n - 3; i++)
                        {
                                if (val == x - 2 || val == x - 1 || val == x || val == x + 1)
                                {
                                        val++;
                                        continue;
                                }
                                cout << val++ << endl;
                        }
                        cout << x - 1 << endl;
                        cout << x + 1 << endl;
                        cout << x << endl;
                        cout << x - 2 << endl;
                        for (int i = n + 2; i <= 2 * n - 1; i++)
                        {
                                if (val == x - 2 || val == x - 1 || val == x || val == x + 1)
                                {
                                        val++;
                                        continue;
                                }
                                cout << val++ << endl;
                        }
                }
        }
        else if (n == x)
        {
                cout << "Yes" << endl;
                for (int i = 1; i <= 2 * n - 1; i++)
                        cout << i << endl;
        }
}

//................................

// int

// int

// int

// int
