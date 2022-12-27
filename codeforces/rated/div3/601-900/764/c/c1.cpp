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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        cout
            << setprecision(15) << fixed;
        int t;
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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
        {
                cin >> i;
                while (i > n)
                {
                        i /= 2;
                }
        }
        if (n == 1)
        {
                cout << "YES" << endl;
                return;
        }
        sort(v.rbegin(), v.rend());

        vector<bool> found(n + 1, false); // 1-indexed
        vector<ll> dup, missing;
        for (ll i = 0; i < n; i++)
        {
                if (found[v[i]])
                {
                        dup.pb(v[i]);
                }
                else
                        found[v[i]] = true;
        }
        for (ll i = 1; i <= n; i++)
        {
                if (found[i] == false)
                {
                        missing.pb(i);
                }
        }
        sort(dup.rbegin(), dup.rend());
        sort(missing.rbegin(), missing.rend());

        // cout << "duplicates" << endl;
        // for (auto el : dup)
        //         cout << el << " ";
        // cout << endl;
        // cout << "missing" << endl;
        // for (auto el : missing)
        //         cout << el << " ";
        // cout << endl;

        if (missing.size() != dup.size())
        {
                cout << "NO" << endl;
                return;
        }

        for (ll i = 0; i < missing.size(); i++) // biggest missing value first
        {
                // cout << "i = " << i << endl;
                for (int j = dup.size() - 1; j >= 0; j--) // smallest duplicate value first
                {
                        // cout << "j= " << j << endl;
                        // cout << "missing = " << missing[i] << endl;
                        // cout << "dup = " << dup[j] << endl;
                        if (dup[j] < missing[i])
                        {
                                continue;
                        }
                        else if (dup[j] == missing[i])
                        {
                                dup.erase(dup.begin() + j);
                                missing.erase(missing.begin() + i);
                                i--;
                                j--;
                                break;
                        }
                        else if (dup[j] > missing[i])
                        {
                                int copy = dup[j];
                                while (copy > missing[i])
                                {
                                        copy /= 2;
                                }
                                if (copy == missing[i])
                                {
                                        // cout << "if" << endl;
                                        dup.erase(dup.begin() + j);
                                        missing.erase(missing.begin() + i);
                                        i--;
                                        j--;
                                        break;
                                }
                        }
                }
        }
        if (missing.size() > 0)
                cout << "NO" << endl;
        else
                cout << "YES" << endl;
}

//................................
// ll
// int
// int
// int
