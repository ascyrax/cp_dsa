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

void suraj()
{
        int n;
        cin >> n;
        ll prod = 1;
        vector<ll> v = {1};
        ll cnt = 0;
        for (int i = 2; i <= n; i++)
        {
                if (__gcd(i, n) == 1)
                {
                        cnt++;
                        v.pb(i);
                        prod = (prod % n * i % n) % n;
                }
        }
        if (prod % n == 1)
        {
                cout << int(v.size()) << endl;
                for (ll i : v)
                        cout << i << " ";
                cout << endl;
        }
        else
        {
                cout << int(v.size() - 1) << endl;
                ll remove = prod % n;
                for (ll i : v)
                {
                        if (i == remove)
                                continue;
                        else
                                cout << i << " ";
                }
                cout << endl;
        }
}

//................................
