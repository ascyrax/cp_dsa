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

        freopen("mountains.in", "r", stdin);
        freopen("mountains.out", "w", stdout);

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
bool cc(pair<int, int> &a, pair<int, int> &b)
{
        if (a.first < b.first)
                return true;
        else if (a.first > b.first)
                return false;
        else if (a.first == b.first)
        {
                if (a.second > b.second)
                        return true;
                else
                        return false;
        }
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                vp.pb(make_pair(x - y, x + y));
        }

        sort(vp.begin(), vp.end(), cc);

        pair<int, int> current = vp[0];

        int nVisible = 1;

        for (int i = 1; i < n; i++)
        {
                if (vp[i].second > current.second)
                {
                        current = vp[i];
                        nVisible++;
                }
        }

        cout << nVisible << endl;
}

//................................

// int

// int

// int

// int
