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
int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
ll n, m, mn;
ll ans;
//...............................

//...............................

void suraj()
{
        cin >> n >> m;
        mn = min(m, n);
        ans = m * n; //ans=mn-sum([n/i]i) for i=1 to mn
        ans %= MOD;
        // i => 1 to sqrt(n) also [n/i] ranges from => 1 to sqrt(n)
        ll a = 0;
        // cout << (ll)sqrt(n) << endl;
        for (ll i = 1; i <= (ll)(sqrt(n)); i++)
        {
                // cout << "i= " << i << endl;
                a += (n / i) * i;
                a %= MOD;
        }
        ll b = 0;
        for (ll j = 1; j < ll((sqrt(n))); j++)
        {
                // cout << "j = " << j << endl;
                //for [n/i]=i there will be a range of nos
                // they will range from [n/(i+1)] to [mn/(i)]..left bound that is [n/(i+1)] value will be excluded
                ll left = n / (j + 1), right = (mn / j);
                ll sumLeft = left * (left + 1) / 2;
                sumLeft %= MOD;
                ll sumRight = right * (right + 1) / 2;
                sumRight %= MOD;

                b += ((sumRight - sumLeft) * j + MOD);
                b %= MOD;
                cout << "left= " << left << "right= " << right << endl;
                cout << sumLeft << " " << sumRight << " " << b << endl;
        }
        // b++;
        // ll c = ll(sqrt(n));
        // if (c == ceil(sqrt(n)))
        // {
        //         c = (n / c) * c;
        //         c %= MOD;
        // }
        // else
        // {
        //         c = 0;
        // }

        cout
            << ans << " " << a << " " << b << endl;
        // cout << ans - a - b << endl;
        cout << (ans - a - b + MOD) % MOD << endl;
}

//................................
