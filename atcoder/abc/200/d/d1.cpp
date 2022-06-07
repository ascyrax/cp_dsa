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
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
                cin >> i;
        if (n >= 8)
        {
                cout << "Yes" << endl;
                map<ll, ll> m; // <sum%200,index>
                for (ll i = 1; i < pow(2, 8); i++)
                {
                        // corresponding to i, choose the elements from the array v.
                        ll sum = 0;
                        ll ptr = 0;
                        ll i2 = i;
                        while (i2)
                        {
                                if (i2 % 2 == 1)
                                {
                                        sum += v[n - 1 - ptr];
                                }
                                ptr++;
                                i2 /= 2;
                        }
                        if (m.count(sum % 200) > 0)
                        {
                                // cout << "Yes" << endl;
                                ll a = m[sum % 200];
                                ll b = i;

                                vector<ll> va, vb;
                                ll temp = 0;
                                while (a)
                                {
                                        if (a % 2 == 1)
                                        {
                                                // va.pb(v[n - 1 - temp]);
                                                va.pb(n - temp);
                                        }
                                        temp++;
                                        a /= 2;
                                }
                                temp = 0;
                                while (b)
                                {
                                        if (b % 2 == 1)
                                        {
                                                // vb.pb(v[n - 1 - temp]);
                                                vb.pb(n - temp);
                                        }
                                        temp++;
                                        b /= 2;
                                }
                                sort(va.begin(), va.end());
                                sort(vb.begin(), vb.end());

                                cout << va.size() << " ";
                                for (ll el : va)
                                        cout << el << " ";
                                cout << endl;
                                cout << vb.size() << " ";
                                for (ll el : vb)
                                        cout << el << " ";
                                cout << endl;

                                return;
                        }
                        else
                        {
                                m[sum % 200] = i;
                        }
                }
        }
        else
        {
                // n=> 2^n-1;
                map<ll, ll> m; // <sum%200,index>
                for (ll i = 1; i < pow(2, n); i++)
                {
                        // corresponding to i, choose the elements from the array v.
                        ll sum = 0;
                        ll ptr = 0;
                        ll i2 = i;
                        while (i2)
                        {
                                if (i2 % 2 == 1)
                                {
                                        sum += v[n - 1 - ptr];
                                }
                                ptr++;
                                i2 /= 2;
                        }
                        if (m.count(sum % 200) > 0)
                        {
                                // cout << "hi" << endl;
                                cout << "Yes" << endl;
                                ll a = m[sum % 200];
                                ll b = i;
                                // cout << "a = " << a << endl;
                                // cout << "b = " << b << endl;

                                vector<ll> va, vb;
                                ll temp = 0;
                                while (a)
                                {
                                        if (a % 2 == 1)
                                        {
                                                // va.pb(v[n - 1 - temp]);
                                                va.pb(n - temp);
                                        }
                                        temp++;
                                        a /= 2;
                                }
                                temp = 0;
                                while (b)
                                {
                                        if (b % 2 == 1)
                                        {
                                                // vb.pb(v[n - 1 - temp]);
                                                vb.pb(n - temp);
                                        }
                                        temp++;
                                        b /= 2;
                                }
                                sort(va.begin(), va.end());
                                sort(vb.begin(), vb.end());

                                cout << va.size() << " ";
                                for (ll el : va)
                                        cout << el << " ";
                                cout << endl;
                                cout << vb.size() << " ";
                                for (ll el : vb)
                                        cout << el << " ";
                                cout << endl;

                                return;
                        }
                        else
                        {
                                m[sum % 200] = i;
                        }
                }
                cout << "No" << endl;
        }
}

//................................
// ll
// int
// int
// int
