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
        int n;
        cin >> n;

        vector<int> v(n);

        for (int &i : v)
        {
                cin >> i;
        }
        int r = -1;
        for (int i = 0; i < n - 1; i++)
        {
                if (v[i] > v[i + 1])
                {
                        r = i;
                        break;
                }
        }
        // int l = r;

        // for (int i = r; i >= 0; i--)
        // {
        //         if (v[i] == v[i - 1])
        //                 l = i - 1;
        //         else
        //                 break;
        // }

        if (r == -1)
        {
                int val = v[n - 1];
                for (int i : v)
                        if (i != val)
                                cout << i << " ";
                cout << endl;
        }
        else
        {
                int val = v[r];
                for (int i : v)
                        if (i != val)
                                cout << i << " ";
                cout << endl;
        }
}

//................................

// int

// int

// int

// int
