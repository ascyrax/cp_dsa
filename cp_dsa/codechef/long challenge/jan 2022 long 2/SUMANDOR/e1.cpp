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

//...............................

void suraj()
{
        ll x, s;
        cin >> x >> s;

        ll s2 = s, x2 = x;
        ll ptrs = 0, ptrx = 0;

        while (s2 > 0)
        {
                if (s2 % 2 == 1)
                {
                        break;
                }
                s2 /= 2;
                ptrs++;
        }
        while (x2 > 0)
        {
                if (x2 % 2 == 1)
                {
                        break;
                }
                x2 /= 2;
                ptrx++;
        }

        if (s < x)
        {
                cout << -1 << endl;
        }
        else if (s == x)
        {
                cout << 1 << endl;
        }
        else if (s > x && ptrs < ptrx)
        {
                cout << -1 << endl;
        }
        else if (s > x && ptrs >= ptrx)
        {
                // ll ans = s / x;
                // ll rem = s % x;

                vector<ll> bits;

                x2 = x;
                ptrx = 0;
                while (x2 > 0)
                {
                        if (x2 % 2 == 1)
                        {
                                bits.pb((ll)pow(2, ptrx));
                        }
                        ptrx++;
                        x2 /= 2;
                }

                // ll ptrRem = 0;
                map<ll, ll> bitCnt;
                // while (rem > 0)
                // {
                //         if (rem % 2 == 1)
                //         {
                //                 ll val = pow(2, ptrRem);
                //                 auto pos = upper_bound(bits.begin(), bits.end(), val) - 1;
                //                 bitCnt[*pos] += (val / (*pos));
                //         }
                //         rem /= 2;
                //         ptrRem++;
                // }
                ll ptrSum = 0;
                while (s > 0)
                {
                        if (s % 2 == 1)
                        {
                                ll val = pow(2, ptrSum);
                                auto pos = upper_bound(bits.begin(), bits.end(), val);
                                pos--;
                                bitCnt[*pos] += (val / (*pos));
                        }
                        s /= 2;
                        ptrSum++;
                }

                ll mx = 0;
                for (auto el : bitCnt)
                        mx = max(el.second, mx);
                cout << mx << endl;
                // cout << ans + mx << endl;
        }
}

//................................
// ll
// ll
// ll
// int
