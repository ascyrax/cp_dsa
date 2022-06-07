#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        ll n, q;
        cin >> n >> q;
        vector<pair<ll, ll>> a;
        map<ll, ll> m;
        set<ll> temp;
        for (ll i = 0; i < n; i++)
        {
                ll l, r, v;
                cin >> l >> r >> v;
                m[l] += v;
                m[r] -= v;

                temp.insert(l);
                temp.insert(r);
        }

        for (ll i : temp)
        {
                a.pb(make_pair(i, m[i]));
        }
        ll tempSum = 0;
        for (ll i = 0; i < a.size(); i++)
        {
                tempSum += a[i].second;
                a[i].second = tempSum;
        }

        vector<ll> ps(a.size());
        ps[0] = a[0].second;

        for (ll i = 1; i < a.size(); i++)
        {
                ps[i] = ps[i - 1] + (a[i].first - a[i - 1].first - 1) * a[i - 1].second + a[i].second;
        }

        vector<ll> ref;
        for (ll i : temp)
                ref.pb(i);

        for (ll i = 0; i < q; i++)
        {
                ll ans = 0;
                ll l, r;
                cin >> l >> r;

                r--;
                auto lowr = lower_bound(ref.begin(), ref.end(), r) - ref.begin();
                auto upr = upper_bound(ref.begin(), ref.end(), r) - ref.begin();
                auto lowitr = lower_bound(ref.begin(), ref.end(), r);
                auto upitr = upper_bound(ref.begin(), ref.end(), r);
                if (upitr == ref.end() && lowitr == ref.end())
                {

                        ans += ps[ps.size() - 1];
                }
                else if (upitr == ref.end() && lowitr != ref.end())
                {
                        ans += ps[ps.size() - 1];
                }
                else if (lowr == upr)
                { // r does not exist
                        if (lowr == 0)
                        {
                                ans += 0;
                        }
                        else
                        {
                                ll left = a[lowr - 1].first;
                                ans = ps[lowr - 1] + (r - left) * a[lowr - 1].second;
                        }
                }
                else
                { //r exists in a
                        if (lowr == 0)
                        {
                                ans += 0;
                        }
                        else
                        {
                                ans += ps[lowr];
                        }
                }
                // left now
                l--;
                auto lowl = lower_bound(ref.begin(), ref.end(), l) - ref.begin();
                auto upl = upper_bound(ref.begin(), ref.end(), l) - ref.begin();
                auto lowitl = lower_bound(ref.begin(), ref.end(), l);
                auto upitl = upper_bound(ref.begin(), ref.end(), l);
                if (lowitl == ref.end() && upitl == ref.end())
                {
                        ans = 0;
                }
                else if (lowitl != ref.end() && upitl == ref.end())
                {
                        ans = 0;
                }
                else if (lowl == upl)
                { // l does not exist
                        if (lowl == 0)
                        {
                                ans -= 0;
                        }
                        else
                        {
                                ll left = a[lowl - 1].first;
                                ans = ans - (ps[lowl - 1] + (l - left) * a[lowl - 1].second);
                        }
                }
                else
                { //l exists
                        if (lowl == 0)
                        {
                                ans -= ps[0];
                        }
                        else
                        {
                                ans -= ps[lowl];
                        }
                }
                cout << ans << endl;
        }
}

//................................
