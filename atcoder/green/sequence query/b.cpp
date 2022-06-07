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

        // freopen("shell.in", "r", stdin);
        // freopen("shell.out", "w", stdout);

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

        ll q;
        cin >> q;
        multiset<ll> s;
        for (ll i = 0; i < q; i++)
        {
                ll c;
                cin >> c;
                if (c == 1)
                {
                        ll x;
                        cin >> x;
                        s.insert(x);
                }
                else
                {
                        ll x, k;
                        cin >> x >> k;

                        if (c == 3)
                        {
                                auto it = s.lower_bound(x);
                                if (it == s.end())
                                {
                                        cout << -1 << endl;
                                        continue;
                                }
                                ll flag = 0;
                                for (ll i = 0; i < k - 1; i++)
                                {
                                        it++;
                                        if (it == s.end())
                                        {
                                                cout << -1 << endl;
                                                flag = -1;
                                                break;
                                        }
                                }
                                if (flag == -1)
                                        continue;
                                cout << *it << endl;
                        }
                        else if (c == 2)
                        {
                                auto it = s.upper_bound(x);
                                ll flag = 0;
                                // cout << "*it = " << *it << endl;
                                // if (it == s.end() || (*it) != x)
                                // {
                                //         k++; // so that iterating from 0 to k-2 i.e. k-1 times will now become k times.
                                // }
                                for (ll i = 0; i < k; i++)
                                {
                                        if (it == s.begin())
                                        {
                                                cout << -1 << endl;
                                                flag = -1;
                                                break;
                                        }
                                        it--;
                                }
                                if (flag == -1)
                                        continue;
                                cout << *it << endl;
                        }
                }
        }
}

//................................

// ll

// int

// int

// int
