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
        int x, d;
        cin >> x >> d;
        // vector<int> vgood, vbeau;
        map<int, int> mbeau, mgood;
        for (int i = d; i * i <= x; i += d)
        {
                // vgood.pb(i);
                // cout << "i = " << i << endl;
                mgood[i] = 1;
                int q = i / d;
                // cout << "mgood" << endl;
                // for (auto el : mgood)
                //         cout << el.first << " " << el.second << endl;
                if (mgood.count(q) > 0 && mgood[q] == 1)
                {
                        // q is good => i i.e q*d can be represented as a product of two good nos.
                        mbeau[i] = 0; // i is not beautiful
                }
                else
                {
                        mbeau[i] = 1;
                }
        }
        cout << "mgood" << endl;
        for (auto el : mgood)
                cout << el.first << " " << el.second << endl;
        cout << "mbeau" << endl;
        for (auto el : mbeau)
                cout << el.first << " " << el.second << endl;
        set<pair<int, int>> ans;
        for (int i = d; i * i <= x; i += d)
        {
                int q = x / i;
                cout << "i = " << i << endl;
                cout << "q = " << q << endl;
                if ((mbeau.count(q) > 0 && (mbeau[q] == 1)) && (mbeau.count(i) > 0 && (mbeau[i] == 1)))
                {
                        int a = min(q, i);
                        int b = max(q, i);
                        cout << "a = " << a << endl;
                        cout << "b = " << b << endl;
                        ans.insert(make_pair(a, b));
                        if (ans.size() == 2)
                        {
                                cout << "YES" << endl;
                                return;
                        }
                }
        }
        cout << "NO" << endl;
}

//................................

// int

// int

// int

// int
