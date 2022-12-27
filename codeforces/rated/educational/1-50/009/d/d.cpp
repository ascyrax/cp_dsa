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
        vector<ll> cnt(m + 1, 0), z(m + 1, 0);
        // map<ll, ll> cnt, z;// its implemented as a red black tree and insertion, search are all in O(log n)
        //so we cant use map as it will make my algo's complexity = mlog(m)*log(m)

        for (ll &i : v)
        {
                cin >> i;
                if (i <= m)
                        cnt[i]++;
        }
        for (ll i = 1; i <= m; i++)
        {
                for (ll j = i; j <= m; j += i)
                {
                        z[j] += cnt[i];
                }
        }
        ll len = -1, lcm = -1;
        for (ll i = 1; i <= m; i++)
        {
                if (z[i] >= len)
                {
                        if (z[i] == len)
                        {
                                if (i < lcm)
                                {
                                        lcm = i;
                                }
                        }
                        else
                        {
                                len = z[i];
                                lcm = i;
                        }
                }
                // }else if(z[i]==len){
                //         if()
                // }
        }
        cout << lcm << " " << len << endl;
        for (ll i = 0; i < n; i++)
        {
                if (lcm % v[i] == 0)
                        cout << i + 1 << " ";
        }
        cout << endl;
}

//................................
