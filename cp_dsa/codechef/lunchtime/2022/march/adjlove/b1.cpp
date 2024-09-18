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
        vector<int> v(n);
        int odd = 0, even = 0;
        vector<int> vodd, veven;
        for (int &i : v)
        {
                cin >> i;
                if (i & 1)
                {
                        odd++;
                        vodd.pb(i);
                }
                else
                {
                        even++;
                        veven.pb(i);
                }
        }

        if (odd <= 1)
                cout << -1 << endl;
        else if (odd & 1)
        { // odd= 3 5 7 ..
                if (even == 0)
                {
                        cout << -1 << endl;
                        return;
                }

                // cout << vodd[0] << " " << veven[0] << " ";

                for (int i = 0; i <= vodd.size() - 2; i++)
                {
                        cout << vodd[i] << " ";
                }
                for (auto el : veven)
                        cout << el << " ";
                cout << vodd[vodd.size() - 1] << endl;
        }
        else
        {
                for (auto el : vodd)
                        cout << el << " ";
                for (auto el : veven)
                        cout << el << " ";
                cout << endl;
        }
}

//................................

// int

// int

// int

// int
