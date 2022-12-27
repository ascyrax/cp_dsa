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
        // ioss
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
ll n, m;
vector<ll> a, b;
ll sa = 0, sb = 0;
ll ans = 0;
ll nSwaps = -1;
vector<pair<ll, ll>> ansPair;
map<ll, pair<ll, ll>> ma;
//...............................

//...............................

void suraj()
{
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
                ll x;
                cin >> x;
                a.pb(x);
                sa += x;
        }
        cin >> m;
        for (ll i = 0; i < m; i++)
        {
                ll x;
                cin >> x;
                b.pb(x);
                sb += x;
        }
        // cout << "zero" << endl;
        //k=0
        ans = abs(sa - sb);
        nSwaps = 0;
        // cout << "one" << endl;
        //k=1
        for (ll i = 0; i < n; i++)
        {
                for (ll j = 0; j < m; j++)
                {
                        ll ta = sa - a[i] + b[j];
                        ll tb = sb - b[j] + a[i];
                        if (abs(ta - tb) < ans)
                        {
                                nSwaps = 1;
                                ans = abs(ta - tb);
                                ansPair.clear();
                                ansPair.pb({i, j});
                        }
                }
        }
        // cout << "twwwwwwwooooooooooooo" << endl;
        //k=2
        if (n > 1 && m > 1)
        {
                for (ll i = 0; i < n; i++)
                {
                        for (ll j = i + 1; j < n; j++)
                        {
                                //a[i]+a[j] is x
                                ma[2 * (a[i] + a[j])] = make_pair(i, j);
                        }
                }
                // cout << "ma" << endl;
                // for (auto el : ma)
                //         cout << el.first << "       " << el.second.first << " " << el.second.second << endl;
                // cout << "ma" << endl;
                for (ll i = 0; i < m; i++)
                {
                        for (ll j = i + 1; j < m; j++)
                        {
                                ll tb = sb - (b[i] + b[j]);
                                ll ta = sa + (b[i] + b[j]);
                                //x=corresponding a[i]+a[j]
                                //tb+x and ta-x
                                //we want (abs((ta-x)-(tb+x))) to be as small as possible
                                //viz sa+b[i]+b[j]-x -(sb -(b[i] + b[j]+x))
                                //viz sa-sb+2(b[i]+b[j])-2x to be as small as possible
                                //viz sa-sb-2(b[i]+b[j]) to be as close as 2x
                                auto it = ma.lower_bound(abs(ta - tb));
                                // cout << ta << " " << tb << " " << abs(ta - tb) << endl;
                                auto temp = it;
                                ll twoX;
                                if (it == ma.end())
                                {
                                        twoX = (*(--temp)).first;
                                }
                                else if (it == ma.begin())
                                {
                                        twoX = (*it).first;
                                }
                                else
                                {
                                        if (abs(abs(ta - tb) - (*it).first) < abs(abs(ta - tb) - (*(--temp)).first))
                                        {
                                                twoX = (*it).first;
                                        }
                                        else
                                                twoX = (*temp).first;
                                }
                                // cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << endl;
                                // cout << twoX << endl;
                                if (twoX == abs(ta - tb) || twoX != abs(ta - tb))
                                {
                                        ta = ta - twoX / 2;
                                        tb = tb + twoX / 2;
                                        if (abs(ta - tb) < ans)
                                        {
                                                nSwaps = 2;
                                                ans = abs(ta - tb);
                                                ansPair.clear();
                                                ansPair.pb(make_pair((*it).second.first, i));
                                                ansPair.pb(make_pair((*it).second.second, j));
                                        }
                                }
                        }
                }
        }
        cout << ans << endl;
        cout << nSwaps << endl;
        for (auto el : ansPair)
                cout << el.first + 1 << " " << el.second + 1 << endl;
}

//................................
