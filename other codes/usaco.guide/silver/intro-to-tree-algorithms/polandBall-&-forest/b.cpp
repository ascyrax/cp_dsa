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
        vector<int> v(n + 1);
        vector<int> fe(n + 1); // fe => farthest edge
        vector<bool> flag(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
                int temp;
                cin >> temp;
                fe[i] = temp;
        }
        if (n == 1)
        {
                cout << 1 << endl;
                return;
        }
        set<pair<int, int>> diameters; // of each tree in the forest
        for (int i = 1; i <= n; i++)
        {
                if (flag[i])
                        continue;
                flag[i] = true;
                int a = fe[i];
                if (a == i)
                {
                        diameters.insert(make_pair(a, a));
                        continue;
                }
                int b = fe[a];
                int mn = min(a, b);
                int mx = max(a, b);
                diameters.insert(make_pair(mn, mx));
                flag[b] = true;
        }

        cout << diameters.size() << endl;
}

//................................

// int

// int

// int

// int
