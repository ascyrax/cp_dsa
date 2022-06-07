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
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................
const int m = 1e9 + 7;
ll modm(ll a, ll b)
{
        if (b == 0)
                return 1 % m;
        else if (b % 2 == 0)
        {
                ll temp = modm(a, b / 2);
                return (temp * temp) % m;
        }
        else if (b % 2 == 1)
        {
                ll temp = modm(a, b / 2);
                return ((temp * temp) % m * a) % m;
        }
}
void suraj()
{
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
                ll a, b;
                cin >> a >> b;
                ll ans = modm(a, b);
                cout << ans << endl;
        }
}

//................................
