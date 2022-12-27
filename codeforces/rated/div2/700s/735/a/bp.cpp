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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        ll ans = 1;
        for (ll i = 1; i < n; i++)
        {
                ans = max(ans, v[i - 1] * v[i]);
        }
        // cout << "ans = " << ans << endl;
        ll l = 0, r = n - 1;
        while (l < r)
        {
                // for (int i = l; i <= r; i++)
                // {
                //         cout << v[i] << " ";
                // }
                // cout << endl;
                ans = max(ans, v[l] * v[l + 1]);
                ans = max(ans, v[r] * v[r - 1]);
                if (v[l] < v[r])
                {
                        l++;
                }
                else if (v[l] > v[r])
                {
                        r--;
                }
                else if (v[l] == v[r])
                {
                        if (v[l + 1] < v[r - 1])
                                l++;
                        else
                                r--;
                }
        }
        cout << ans << endl;
}

//................................
