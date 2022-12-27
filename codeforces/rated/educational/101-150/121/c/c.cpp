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
        ioss
            // startTime=(double)clock();
            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
            // cout << setprecision(15) << fixed;
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
ll consSum(ll a)
{
        return ((a * (a + 1)) / 2ll);
}
//...............................

void suraj()
{
        ll n;
        cin >> n;

        vector<ll> k(n);
        for (ll &i : k)
                cin >> i;

        vector<ll> h(n);
        for (ll &i : h)
                cin >> i;

        ll ans = 0;

        for (int i = 1; i < n; i++) // left to right wave
        {
                ll rk = k[i];
                ll lk = k[i - 1];
                ll rh = h[i];
                ll lh = h[i - 1];

                ll diff = rk - lk;
                // cout << "i = " << i << endl;

                if (diff >= rh)
                {
                        // cout << "if" << endl;
                        continue;
                }
                else
                {
                        // cout << "else" << endl;
                        // ll lhNext = lh + 1;
                        // cout << "rh = " << rh << endl;
                        rh = max(rh, lh + diff);
                        // cout << "rh = " << rh << endl;
                        h[i] = rh;
                }
        }
        cout << "k : " << endl;
        for (auto el : k)
                cout << el << " ";
        cout << endl;
        cout << "h : " << endl;
        for (auto el : h)
                cout << el << " ";
        cout << endl;

        for (ll i = n - 1; i >= 1; i--)
        {
                cout << "i = " << i << endl;
                ll rk = k[i];
                ll lk = k[i - 1];
                ll rh = h[i];
                ll lh = h[i - 1];
                ll diff = rk - lk;

                cout << rk << " " << lk << " " << rh << " " << lh << endl;

                if (diff >= rh)
                {
                        cout << "if" << endl;
                        ans += consSum(rh);
                }
                else
                {
                        cout << "else" << endl;
                        // lh = rh - diff;
                        h[i - 1] = max(h[i - 1], rh - diff);
                        lh = h[i - 1];
                        rh = max(rh, lh + diff);
                        ans += (consSum(rh) - consSum(lh));
                        // ll temp = rh - (diff - 1); // => rh = temp + diff-1; // temp is value at lt+1 time
                        // if (lh < temp)
                        // {
                        //         h[i - 1] = max(h[i - 1], temp - 1);
                        //         if (diff == 1)
                        //                 ans += rh;
                        //         else
                        //                 ans += (consSum(rh) - consSum(temp - 1));
                        // }
                        // else if (lh >= temp)
                        // {
                        //         temp = lh + 1; // or 1
                        //         rh = temp + diff - 1;
                        //         if (diff == 1)
                        //                 ans += rh;
                        //         else
                        //                 ans += (consSum(rh) - consSum(temp - 1));
                        // }
                }
                cout << "ans = " << ans << endl;
        }
        // cout << "ans = " << ans << endl;
        ans += consSum(h[0]);
        cout << ans << endl;
}

//................................
// ll
// ll
// int
// int
