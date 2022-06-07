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
        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        for (string &el : s)
                cin >> el;

        map<string, int> mp;

        vector<string> t(m);
        for (string &el : t)
        {
                cin >> el;
                mp[el] = 3;
        }

        for (auto station : s)
        {
                if (mp[station] == 3)
                        cout << "Yes" << endl;
                else
                        cout << "No" << endl;
        }
}

//................................

// int

// int

// int

// int
