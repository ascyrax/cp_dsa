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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        ioss
            // startTime=(double)clock();
            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
            // cout << setprecision(15) << fixed;
            int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        sort(v.begin(), v.end());
        // n-1 to 0
        // no of elements that will remain unchanged

        vector<ll> ps(n);
        for (ll i = 0; i < n; i++)
        {
                if (i == 0)
                        ps[i] = v[i];
                if (i > 0)
                        ps[i] = ps[i - 1] + v[i];
        }

        if (ps[n - 1] <= k)
        {
                cout << 0 << endl;
                return;
        }
        else if (ps[n - 1] == k + 1)
        {
                cout << 1 << endl;
                return;
        }
        // if we are here => atleast one element needs to be changed
        ll ans = 1e18;
        for (ll i = n - 1; i >= 0; i--) // i =n-1 => all n-1 last elements (i.e. leaving the first(smallest) element) dont change through step 2
        {
                // if i elemnts of the array v are unchanged
                // elem no=1 to elem no=1+i-1
                ll sum = ps[1 + i - 1] - ps[0];
                // this is the sum of unchanged elements
                ll sumDynamicElements = ps[n - 1] - sum;
                // if (sum > k)
                //         continue;
                ll remSum = k - sum;
                ll cntVaryingElem = (n - 1 - i) + 1; // cnt of elements changing  through step 2 + the smaleest element(which change through step 1)
                ll avg = remSum / cntVaryingElem;
                if (remSum % cntVaryingElem != 0)
                {
                        if (remSum < 0)
                                avg = (remSum / cntVaryingElem) - 1;
                        // -7/2 -> -3
                        // but we want -4 as the value of each element for sum<=k...thats why
                        if (remSum > 0)
                                ;
                        // do nothing
                }
                if (avg <= v[0])
                {
                        ll diff = v[0] - avg;
                        ans = min(ans, diff + (cntVaryingElem - 1));
                }
                else
                {
                        ans = min(ans, 0 + (cntVaryingElem - 1));
                        // if (sumDynamicElements >= remSum)
                        // {
                        //         ans = min(ans, 0ll);
                        //         continue;
                        // }
                        // else
                        // {
                        //         ll diff = 0; // as the first(smallest) element doesnt need to be decreased
                        //         // ll sum2 = ps[n - 1] - ps[]
                        //         // since avg>v[0] => maybe not all the (cntVaryingElem-1) largest elements
                        //         // needs to be changed to v[0] through the second step.
                        //         // int cnt = 0;
                        //         // int ptr = n - 1;
                        //         // while (sumDynamicElements > remSum)
                        //         // {
                        //         //         if (ptr == 1 + i - 1)
                        //         //                 break;
                        //         //         sumDynamicElements -= v[ptr];
                        //         //         sumDynamicElements += v[0];
                        //         //         cnt++;
                        //         // }
                        //         // if (sumDynamicElements <= remSum)
                        //         //         ans = min(ans, diff + cntVaryingElem - 1);
                        //         ans=min(ans)
                        // }
                }
        }
        cout << ans << endl;
}

//................................
// ll
// ll
// ll
// ll
