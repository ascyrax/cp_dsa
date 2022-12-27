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
        vector<ll> a(n), b(n);
        set<ll> univList;
        vector<vector<ll>> univ(n);

        for (ll i = 0; i < n; i++)
        {
                cin >> a[i];
                a[i]--;
                univList.insert(a[i]);
        }
        // sort(univList.begin(), univList.end());
        for (ll i = 0; i < n; i++)
        {
                cin >> b[i];
        }

        for (ll i = 0; i < n; i++)
        {
                univ[a[i]].pb(b[i]);
        }

        // for (ll i : univList)
        // {
        //         for (ll j : univ[i])
        //                 cout << j << " ";
        //         cout << endl;
        // }

        // sort(univ.begin(), univ.end());

        for (ll i : univList)
        {
                sort(univ[i].rbegin(), univ[i].rend());
        }
        // for (ll i : univList)
        // {
        //         for (ll j : univ[i])
        //                 cout << j << " ";
        //         cout << endl;
        // }
        vector<vector<ll>> ps(n, vector<ll>(1, 0));

        for (ll i : univList)
        {
                ps[i] = vector<ll>((ll)univ[i].size());
                for (ll j = 0; j < univ[i].size(); j++)
                {
                        if (j == 0)
                                ps[i][j] = univ[i][j];
                        else
                                ps[i][j] = ps[i][j - 1] + univ[i][j];
                }
        }

        // for (ll k = 1; k <= n; k++)
        // {
        //         ll ans = 0;
        //         for (ll j : univList)
        //         {
        //                 ll rem = ps[j].size() % k;
        //                 if ((ll)ps[j].size() - 1 - rem >= 0)
        //                 {
        //                         // cout << "if " << (ll)ps[j].size() - 1 - rem << " " << ps[j].size() << " " << rem << " " endl;
        //                         ans += ps[j][ps[j].size() - 1 - rem];
        //                 }
        //                 // cout << k << " " << j << " " << rem << " " << ans << endl;
        //         }
        //         cout << ans << " ";
        // }cout << endl;
        vector<ll> ans(n);
        for (int j : univList)
        {
                for (int k = 1; k <= (int)univ[j].size(); k++)
                {
                        int rem = (int)univ[j].size() % k;
                        ans[k - 1] += ps[j][(int)univ[j].size() - 1 - rem];
                }
        }
        for (ll i : ans)
                cout << i << " ";
        cout << endl;
}

//................................
