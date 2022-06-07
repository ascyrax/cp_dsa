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
const ll mod = 998244353;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

ll factorial(ll n, ll DivideBy) //fact(a)/b in maths = fact(a,b) in my code
{
        ll fact = 1;
        while (n > 0)
        {
                if (n != DivideBy)
                        fact *= n;
                fact %= mod;
                n--;
        }
        return fact;
}
//...............................

//...............................

void suraj()
{

        //if max-2nd max>1 then  ans=0
        //else if max-2nd max=1 then any one 2nd max value must come after max
        //else if max=2nd max then any order is ok

        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
                ll x;
                cin >> x;
                v.pb(x);
        }
        sort(v.rbegin(), v.rend());
        ll bigA = v[0];
        ll bigB = 0;
        for (ll i = 0; i < n; i++)
        {
                if (v[i] < bigA)
                {
                        bigB = v[i];
                        break;
                }
        }
        ll cntA = 0, cntB = 0;
        for (ll i = 0; i < n; i++)
        {
                if (v[i] == bigA)
                        cntA++;
                else if (v[i] == bigB)
                        cntB++;
        }
        // cout << bigA << " " << bigB << endl;
        // cout << cntA << " " << cntB << endl;
        if (cntA > 1)
        {
                cout << factorial(n, 1) << endl;
        }
        else if (bigA - bigB > 1)
                cout << 0 << endl;
        else if (bigA - bigB == 1)
        {
                cout << (factorial(n, 1) - factorial(n, cntB + 1) + mod) % mod << endl;
        }
        // cout << factorial(21) << endl;
}

//................................
