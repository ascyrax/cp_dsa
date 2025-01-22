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
        for (int &i : v)
                cin >> i;

        for (int i = 0; i < n; i += 3)
        {
                int cnt = n - i;
                if (cnt == 1)
                        break;
                else if (cnt == 2)
                {
                        v[i + 1] = 2 * v[i];
                        break;
                }
                else if (cnt == 3)
                {
                        v[i + 1] = 2 * v[i];
                        v[i + 2] = 2;
                }
                else
                {

                        v[i + 1] = 2 * v[i];
                        v[i + 2] = 2 * v[i + 3];
                }
        }
        for (int el : v)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
