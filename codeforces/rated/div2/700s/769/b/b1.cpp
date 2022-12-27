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

        int val = 1;
        while (val <= n - 1)
        {
                val *= 2;
        }
        val /= 2;
        // cout << "val : " << val << endl;
        vector<int> ans;
        for (int i = n - 1; i >= val; i--)
        {
                ans.pb(i);
        }
        for (int i = 0; i < val; i++)
                ans.pb(i);

        for (int el : ans)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
