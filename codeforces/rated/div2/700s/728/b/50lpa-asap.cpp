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
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++) //{cout<<"Case #"<<i<<": ";
                suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{
        ll n;
        cin >> n;
        ll ans = 0;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        //rhs = i+j <=2n
        //hence we only need to deal with
        //lhs =ai.aj<=2n

        //a sorted vector s containing all ais
        vector<pair<ll, ll>> vp;

        for (int i = 0; i < n; i++)
        {
                vp.pb(make_pair(v[i], i));
        }
        sort(vp.begin(), vp.end());
        //for element si=3 we need to iterate in this vector itself
        for (int i = 0; i < n; i++)
        {
                //vp[i].first
                for (int j = i + 1; j < n && vp[j].first <= (2 * n / vp[i].first); j++)
                {
                        if (vp[i].first * vp[j].first == vp[i].second + vp[j].second + 2)
                                ans++;
                }
        }
        //from i+1 to i+sth such that si*s(i+sth)<=2n
        //viz (i+sth)<=2n/si
        //and check for si*sj==si.second+si.first
        cout << ans << endl;
}

//................................
