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

        vector<int> a(n), b(n);
        for (int &i : a)
                cin >> i;
        for (int &i : b)
                cin >> i;
        vector<pair<int, int>> ab;
        for (int i = 0; i < n; i++)
        {
                ab.pb(make_pair(a[i], b[i]));
        }

        sort(ab.begin(), ab.end());

        for (int i = 0; i < n; i++)
        {
                if (ab[i].first > k)
                        break;
                else
                {
                        k += ab[i].second;
                }
        }
        cout << k << endl;
}

//................................

// int

// int

// int

// int
