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

        ioss

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
        for (int &i : v)
                cin >> i;
        int cnt = 0;
        vector<int> imp;
        for (int i = 1; i < n - 1; i++)
        {
                if (v[i] > v[i - 1] && v[i] > v[i + 1])
                {
                        // v[i] = max(v[i - 1], v[i + 1]);
                        imp.pb(i);
                        // cnt++;
                }
        }

        // for (auto el : imp)
        //         cout << el << " ";
        // cout << endl;

        for (int i = 1; i < imp.size(); i++)
        {
                if (imp[i] - imp[i - 1] == 2)
                {
                        cnt++;
                        v[imp[i] - 1] = max(v[imp[i]], v[imp[i - 1]]);
                        i++;
                }
        }

        // for (auto el : v)
        //         cout << el << " ";
        // cout << endl;

        imp.clear();

        for (int i = 1; i < n - 1; i++)
        {
                if (v[i] > v[i - 1] && v[i] > v[i + 1])
                {
                        v[i] = max(v[i - 1], v[i + 1]);
                        // imp.pb(i);
                        cnt++;
                }
        }

        cout << cnt << endl;
        for (int el : v)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
