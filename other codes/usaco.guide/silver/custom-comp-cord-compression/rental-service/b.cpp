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
        freopen("rental.in", "r", stdin);
        freopen("rental.out", "w", stdout);
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
bool second(pair<ll, ll> a, pair<ll, ll> b)
{
        if (a.second > b.second)
                return true;
        else if (a.second == b.second)
        {
                if (a.first > b.first)
                        return false;
                else
                        return true;
        }
        else
                return false;
}
//...............................

void suraj()
{
        ll n, m, r;
        cin >> n >> m >> r;
        vector<ll> cows;
        vector<pair<ll, ll>> qp;
        vector<ll> rent;
        for (ll i = 0; i < n; i++)
        {
                ll x;
                cin >> x;
                cows.pb(x);
        }
        sort(cows.rbegin(), cows.rend());
        vector<ll> pscows = {0};
        for (ll i : cows)
                pscows.pb(i + pscows.back());
        // for (ll i : pscows)
        //         cout << i << " ";
        // cout << endl;

        vector<ll> psMilk = {0};
        for (ll i = 0; i < m; i++)
        {
                ll q, p;
                cin >> q >> p;
                qp.pb(make_pair(q, p));
        }
        sort(qp.begin(), qp.end(), second);
        for (auto el : qp)
                psMilk.pb(el.first + psMilk.back());
        // cout << "psMilk" << endl;
        // for (ll i : psMilk)
        //         cout << i << " ";
        // cout << endl;
        vector<ll> psqp = {0};
        for (auto i : qp)
                psqp.pb(i.first * i.second + psqp.back());
        // for (ll i : psqp)
        //         cout << i << " ";
        // cout << endl;

        for (ll i = 0; i < r; i++)
        {
                ll x;
                cin >> x;
                rent.pb(x);
        }
        sort(rent.rbegin(), rent.rend());
        vector<ll> psrent = {0};
        for (ll i : rent)
                psrent.pb(i + psrent.back());
        // for (ll i : psrent)
        //         cout << i << " ";
        // cout << endl;

        ll sellMilk = 0, rentCow = n;
        ll ans = 0;
        for (sellMilk = 0; sellMilk <= n; sellMilk++)
        {
                // cout << "sellMilk: " << sellMilk << endl;
                ll sum = 0;
                rentCow = min(n - sellMilk, (ll)psrent.size() - 1);
                ll nMilk = pscows[min((ll)pscows.size() - 1, sellMilk)];
                // cout << "nMilk: " << nMilk << endl;
                auto it = lower_bound(psMilk.begin(), psMilk.end(), nMilk);
                if (it == psqp.end())
                {
                        sum = psqp[psqp.size() - 1] + psrent[rentCow];
                }
                else if (*it == nMilk)
                {
                        sum = psqp[it - psMilk.begin()] + psrent[rentCow];
                }
                else
                {
                        sum = psqp[it - psMilk.begin() - 1] + psrent[rentCow];
                        // cout << "hi " << *(it - 1) << " " << nMilk << endl;
                        sum += ((nMilk - *(it - 1)) * (qp[it - psMilk.begin() - 1].second));
                }
                // sum = psqp[sellMilk] + psrent[rentCow];
                // cout << sum << " " << psrent[rentCow] << endl;
                // cout << sum << " " << ans << endl;
                ans = max(ans, sum);
        }
        cout << ans << endl;
}

//................................
