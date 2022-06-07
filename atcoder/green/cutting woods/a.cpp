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
        int l, q;
        cin >> l >> q;
        vector<int> v;
        set<int> s;
        v.pb(0);
        v.pb(l);
        s.insert(0);
        s.insert(l);

        for (int i = 0; i < q; i++)
        {
                int c, x;
                cin >> c >> x;

                if (c == 1)
                        s.insert(x);
                else
                {
                        auto loc = s.lower_bound(x);
                        int len = 0;
                        auto l = --loc;
                        ++loc;
                        auto r = loc;
                        len = (*r) - (*l);
                        cout << len << endl;
                }
        }
}

//................................

// int

// int

// int

// int
