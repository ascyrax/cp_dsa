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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        string s;
        cin >> s;
        vector<ll> psLeft(n), psRight(n);
        for (ll i = 0; i < n; i++)
        {
                if (s[i] == 'B')
                {
                        if (i - 1 >= 0)
                                psLeft[i] = psLeft[i - 1] - v[i];
                        else
                                psLeft[i] = -v[i];
                }
                else
                {
                        if (i - 1 >= 0)
                                psLeft[i] = psLeft[i - 1] + v[i];
                        else
                                psLeft[i] = v[i];
                }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
                if (s[i] == 'B')
                {
                        if (i + 1 <= n - 1)
                                psRight[i] = psRight[i + 1] - v[i];
                        else
                                psRight[i] = -v[i];
                }
                else
                {
                        if (i + 1 <= n - 1)
                                psRight[i] = psRight[i + 1] + v[i];
                        else
                                psRight[i] = v[i];
                }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
                ans = max(ans, psLeft[i]);
                ans = max(ans, psRight[i]);
        }
        ll bob = 0;
        for (ll i = 0; i < n; i++)
        {
                if (s[i] == 'B')
                        bob += v[i];
        }
        // cout << psLeft[0] << " " << psRight[0] << endl;
        cout << bob + ans << endl;
}

//................................
