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
        vector<int> a(n), b(n);

        for (int &i : a)
                cin >> i;
        for (int &i : b)
                cin >> i;

        // 2^2 + 3^2 << (2+3)^2
        // say, if we choose the min possible elements for a, then
        // the elements of b will be having large values which will never lead to min possible total cost.
        // so we need to make the sum of elements of both the arrays as close to each other as possible.

        
}

//................................

// int

// int

// int

// int
