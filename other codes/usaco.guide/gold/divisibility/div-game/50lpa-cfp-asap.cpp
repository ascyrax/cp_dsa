#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
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
    //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
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
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    //find the prime factorization of n
    map<ll, ll> primefact;
    ll ncopy = n;
    for (ll i = 2; i * i <= ncopy; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            primefact[i]++;
        }
    }
    if (n > 1)
        kl
            primefact[n]++;
    //n=p1e1*p2e2*p3e3*p4e4...pkek
    for (auto i : primefact)
    {
        // cout << i.first << " " << i.second << " ";
        // cout << endl;
        ll sum = 0;
        ll j = 1;
        for (j = 1; j <= i.second; j++)
        {
            sum += j;
            if (sum == i.second)
            {
                ans += j;
                break;
            }
            if (sum > i.second)
            {
                ans += j - 1;
                break;
            }
        }
    }
    // cout << endl;
    cout << ans << endl;
    //e1=>3(=noperation say) if  e1>=6 && e1<10
    //6 corresponds to 1+2+3
    //10 corresponds to 1+2+3+4
    //our ans=noperations for e1 to ek
}

//................................
