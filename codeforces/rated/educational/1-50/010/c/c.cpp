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
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        vector<ll> pos(n + 1);
        for (ll i = 0; i < n; i++)
        {
                cin >> v[i];
                pos[v[i]] = i;
        }
        vector<pair<ll, ll>> fp;
        vector<ll> z(n + 1, 1e9);
        ll goodPairs = 0;

        for (ll i = 0; i < m; i++)
        {
                ll a, b;
                cin >> a >> b;
                if (pos[a] > pos[b])
                {
                        ll c = a;
                        a = b;
                        b = c;
                }
                fp.pb(make_pair(a, b));
                // cout << pos[a] << " " << pos[b] << endl;
                if (z[pos[a]] != 0)

                        z[pos[a]] = min(z[pos[a]], pos[b]);
                else
                        z[pos[a]] = pos[b];
                // e.g. z[5]=7.. since 1 and 6 are foe pairs
        }
        for (int i = 0; i < n; i++)
        {
                if (z[i] == 0)
                        z[i] = i + 1;
        }
        // for (int i = 0; i < n; i++)
        //         cout << z[i] << " ";
        // cout << endl;
        ll sol = 0;
        for (int i = n - 1; i >= 0; i--)
        {
                //i is the current position that we r dealing with

                //we need to find the optimal right end for i
                if (i + 1 < n)
                {
                        z[i] = min(z[i], z[i + 1]);
                }
                else
                        z[i] = i + 1;
                // cout << "i = " << i << " z[i] = " << z[i] << endl;
                sol += (z[i] - i);
        }
        cout << sol << endl;
}

//................................
// // Retired?
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef long unsigned long ull;
// typedef double long ld;

// int n, m;
// int a[300005], inv[300005], e[300005];

// int main()
// {
//         ios::sync_with_stdio(!cin.tie(0));

//         cin >> n >> m;
//         for (int i = 1; i <= n; i++)
//                 cin >> a[i], inv[a[i]] = i;

//         for (int i = 1; i <= 9; i++)
//         {
//                 cout << "i = " << i << " inv[i] = " << inv[i] << endl;
//         }
//         while (m--)
//         {
//                 int x, y;
//                 cin >> x >> y;
//                 cout << x << " " << y << endl;
//                 x = inv[x], y = inv[y];
//                 if (x > y)
//                         swap(x, y);
//                 e[y] = max(e[y], x);
//                 cout << x << " " << y << " " << e[y] << endl;
//         }
//         cout << "e[i]" << endl;
//         for (int i = 0; i <= 15; i++)
//         {
//                 cout << e[i] << endl;
//         }

//         ll sol = 0;
//         for (int i = 1; i <= n; i++)
//         {
//                 e[i] = max(e[i], e[i - 1]);

//                 sol += i - e[i];
//                 cout << "i = " << i << " e[i] = " << e[i] << " sol = " << sol << endl;
//         }
//         cout << sol << '\n';
// }
