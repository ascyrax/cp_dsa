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
        vector<ll> vd(n);
        for (ll &i : vd)
                cin >> i;
}

//................................
