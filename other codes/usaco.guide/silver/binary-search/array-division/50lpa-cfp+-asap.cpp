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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        ll l = 1e9;
        for (ll i : v)
                l = min(l, i);
        ll r = accumulate(v.begin(), v.end(), 0ll);
        ll m = l + (r - l) / 2;
        while (l < r)
        {
                m = l + (r - l) / 2;
                ll ngrps = 0;
                ll sum = 0;
                for (ll i = 0; i < n; i++)
                {
                        if (v[i] > m)
                        {
                                // l=m+1;
                                //or
                                ngrps = k + 1; //this will lead to l=m+1;
                                break;
                        }
                        sum += v[i];
                        if (sum > m)
                        {
                                ngrps++;
                                sum = v[i];
                        }
                        else if (sum == m)
                        {
                                ngrps++;
                                sum = 0;
                        }
                }

                if (sum > 0)
                        ngrps++;
                // cout << l << " " << m << " " << r << " " << ngrps << endl;
                if (ngrps < k)
                {
                        r = m - 1;
                }
                else if (ngrps > k)
                {
                        l = m + 1;
                }
                else if (ngrps == k)
                {
                        r = m;
                }
        }
        cout << l << endl;
}

//................................
