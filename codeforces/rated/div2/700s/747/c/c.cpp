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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        // ioss
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        vector<ll> differ;
        for (ll i = 0; i < n; i++)
        {
                if (s[i] != c)
                {
                        differ.pb(i + 1);
                }
        }
        sort(differ.begin(), differ.end());
        ll len = (ll)differ.size();

        if (len == 0)
                cout << 0 << endl;
        else if (len == 1)
        {
                cout << 1 << endl;
                if (differ[0] == n)
                        cout << n - 1 << endl;
                else
                        cout << n << endl;
        }
        else
        {
                for (ll i = n; i >= 1; i--)
                {
                        auto it = lower_bound(differ.begin(), differ.end(), i);
                        if (it == differ.end())
                        {
                                cout << 1 << endl;
                                cout << i << endl;
                                return;
                        }
                        else if ((*it) != i) // implies that i is missing from the differ vector
                        {
                                auto it2 = lower_bound(differ.begin(), differ.end(), (2 * i));
                                if ((it2 == differ.end()))
                                {
                                        cout << 1 << endl;
                                        cout << i << endl;
                                        return;
                                } // below condition gets wrong if differ is sth like   1 2 3 5 6 7 9 10 11 12 13 14 15 16 17 18....
                                // becz first i-> 8 will be false cz 2*i exist
                                // next i->4 will give true but in fact we cannot use i=4 since 16 is present
                                // else if ((*it2) != (2 * i))
                                // {
                                //         cout << 1 << endl;
                                //         cout << i << endl;
                                //         return;
                                // }
                                // alternately this can also be used instead of the above if statement
                                // if (2 * i > n)
                                // {
                                //         cout << 1 << endl;
                                //         cout << i << endl;
                                //         return;
                                // }
                        }
                        // if (s[i - 1] == c)
                        // {
                        //         if (i * 2 > n)
                        //         {
                        //                 cout << 1 << endl
                        //                      << i << endl;
                        //                 return;
                        //         }
                        // }
                }
                cout << 2 << endl;
                cout << n << " " << n - 1 << endl;
        }
}

//................................
