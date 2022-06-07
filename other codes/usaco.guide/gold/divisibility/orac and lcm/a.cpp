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
vector<pair<ll, ll>> primeFact[200002];
vector<ll> cntPrime[200002];
//...............................
void prePrime()
{
        // cout << "prePrime" << endl;
        for (ll i = 2; i <= 200000; i++)
        {
                if (primeFact[i].empty())
                {
                        for (ll j = i; j <= 200000; j += i)
                        {
                                ll q = j;
                                ll cnti = 0;
                                while (q % i == 0)
                                {
                                        cnti++;
                                        q /= i;
                                }
                                primeFact[j].pb(make_pair(i, cnti));
                        }
                }
        }
        return;
}
ll pw(ll a, ll b)
{
        ll ans = 1;
        for (int i = 1; i <= b; ++i)
                ans = (ans * a);
        return ans;
}
//...............................
// http://www.youtube.com/watch?v=c5z-LfY-QQ8
void suraj()
{
        prePrime();
        // cout << "hello" << endl;
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        // cntPrime[i] will contain the prime i as if how many
        // times it has appeared  in the input llegers
        for (ll i = 0; i < n; i++)
        {
                ll curr = v[i];
                // prime factorize current
                // and add all the primes in the vector
                // cout << "i = " << i << endl;
                for (pair<ll, ll> p : primeFact[curr])
                {
                        cntPrime[p.first].pb(p.second);
                }
        }
        ll ans = 1;
        for (ll i = 2; i <= 200000; i++)
        {
                sort(cntPrime[i].begin(), cntPrime[i].end());
                if (cntPrime[i].size() == n)
                {
                        ans *= pw(i, cntPrime[i][1]);
                }
                else if (cntPrime[i].size() == n - 1)
                {
                        ans *= pw(i, cntPrime[i][0]);
                }
                else
                {
                        ans = ans;
                }
        }
        cout << ans << endl;
}

//................................
