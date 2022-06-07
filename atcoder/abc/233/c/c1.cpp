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
        startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        ll n, x;
        cin >> n >> x;
        vector<vector<ll>> bags;
        vector<ll> vl(n);
        map<ll, ll> mPrev;
        for (ll i = 0; i < n; i++)
        {
                ll l;
                cin >> l;
                vl[i] = l;
                vector<ll> a(l);
                map<ll, ll> mNew;
                if (i == 0)
                {
                        for (ll j = 0; j < l; j++)
                        {
                                cin >> a[j];
                                mNew[a[j]]++;
                        }
                }
                else
                        for (ll j = 0; j < l; j++)
                        {
                                cin >> a[j];
                                for (auto el : mPrev)
                                {
                                        if (el.first <= x / a[j]) // this is not the perfect condition
                                                mNew[el.first * a[j]] += el.second;
                                }
                        }
                bags.pb(a);
                // cout << "HI. i = " << i << endl;
                mPrev.clear();
                for (auto el : mNew)
                {
                        mPrev[el.first] += el.second;
                }
                // cout << "mPrev: " << endl;
                // for (auto el : mPrev)
                //         cout << el.first << " " << el.second << endl;
        }
        cout << mPrev[x] << endl;
}

//................................
// int
// int
// int
// int
