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
        ll n, x, t;
        cin >> n >> x >> t;
        // case of 1 1 3 does not come under any group
        if(n==1){
            cout<<0<<endl;return;
        }
        if (0 + t >= n * x)
        {
                cout << (n - 1) * (n - 1 + 1) / 2 << endl;
        }
        else if (0 + t < 1 * x)
        {
                cout << 0 << endl;
        }
        else if (0 + t == x)
        {
                cout << n - 1 << endl;
        }
        else if (0 + t > x && 0 + t < n * x)
        {
                ll each = ((0 + t) - (0)) / x;
                // ll ans = (n - x) * (x + n - 1) / 2;
                ll ans = (each)*(2*n-1-each)/2;
                cout << ans << endl;
        }
}

//................................
