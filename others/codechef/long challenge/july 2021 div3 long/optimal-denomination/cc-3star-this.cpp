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

const int mod = 1e9 + 7;

//...............................

void suraj()
{
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        sort(v.begin(), v.end());
        if (n == 1)
        {
                cout << 1 << endl;
                return;
        }
        ll smallest = v[0];
        ll secondSmallest = v[1];
        ll ansa = 0, ansb = 0, ansc = 0;
        //find no of notes corresponding to the smallest no
        ll largest = v[n - 1];
        //largest no will be converted to the smallest no
        ansa += smallest / smallest;
        for (int i = 0; i <= n - 2; i++)
        {
                if (v[i] % smallest != 0)
                {
                        ansa = 1e18;
                        break;
                }
                ansa += v[i] / smallest;
        }

        //find no of notes corresponding to the secondSmallest no
        //smallest no will be converted to the secondSmallest no
        ansb += secondSmallest / secondSmallest;
        for (int i = 1; i <= n - 1; i++)
        {
                if (v[i] % secondSmallest != 0)
                {
                        ansb = 1e18;
                        break;
                }
                ansb += v[i] / secondSmallest;
        }
        //no of notes corresponding to the smallest and no change in any ones salary
        for (int i = 0; i <= n - 1; i++)
        {
                if (v[i] % smallest != 0)
                {
                        ansc = 1e18;
                        break;
                }
                ansc += v[i] / smallest;
        }
        cout << min(min(ansa, ansb), ansc) << endl;
}

//................................
